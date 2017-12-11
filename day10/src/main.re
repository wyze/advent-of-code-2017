type state = {
  numbers: Js.Array.t(int),
  position: int,
  skip: int,
};

let range = Array.init(256, x => x);

let rec process = ( skip, position, numbers, lengths ) =>
  switch lengths {
    | [ len, ...rest ] => {
      let amount = Js.Math.max_int(position + len - Array.length(numbers), 0);
      let reversed = Js.Array.(
        concat(
          slice(~start=0, ~end_=amount, numbers),
          slice(~start=position, ~end_=(position + len), numbers)
        )
        |> reverseInPlace
      );
      let final = Js.Array.(
        concat(
          concat(
            sliceFrom(position + len, numbers),
            slice(~start=0, ~end_=(length(reversed) - amount), reversed)
          ),
          concat(
            slice(~start=amount, ~end_=position, numbers),
            sliceFrom(length(reversed) - amount, reversed)
          )
        )
      );

      process(skip + 1, (position + len + skip) mod Array.length(final), final, rest);
    }
    | [] => { numbers, position, skip }
  };

let rec stringToCharList = str =>
  switch str {
    | "" => []
    | str => [ str.[0], ...stringToCharList(String.(sub(str, 1, length(str) - 1))) ]
  };

let rec sparse = ( skip, position, round, numbers, lengths ) =>
  switch round {
    | 0 => numbers
    | _ => {
      let state = process(skip, position, numbers, lengths);

      sparse(state.skip, state.position, round - 1, state.numbers, lengths);
    }
  };

let dense = numbers => Array.(
  init(16, x => x)
    |> map(index =>
        sub(numbers, index * 16, 16)
          |> fold_left((lxor), 0)
      )
);

let toHex = number =>
  switch ( Printf.sprintf("%x", number) ) {
    | str when ( String.length(str) == 1 ) => "0" ++ str
    | str => str
  };

let multiplyFirstTwo = ({ numbers }) =>
  switch ( numbers |> Array.to_list ) {
    | [ first, second, ..._ ] => first * second
    | _ => 0
  };

let part1 = input =>
  input
    |> Js.String.split(",")
    |> Array.map(int_of_string)
    |> Array.to_list
    |> process(0, 0, range)
    |> multiplyFirstTwo;

let part2 = input =>
  (input |> stringToCharList |> List.map(Char.code)) @ [ 17, 31, 73, 47, 23 ]
   |> sparse(0, 0, 64, range)
   |> dense
   |> Array.map(toHex)
   |> Js.Array.joinWith("");

let solve = ( ~input = Input.input, solver ) =>
  input |> solver;

Js.log2("Day 10, Part 1:", solve(part1));
Js.log2("Day 10, Part 2:", solve(part2));
