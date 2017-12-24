let part1 = input =>
  float(input - 2) ** 2. |> truncate;

let part2 = input => {
  let start = input * 100 + 100000;
  let max = start + 17000;
  let rec loop = ( num, count ) =>
    switch ( num <= max ) {
      | true => {
        let rec prime = rem =>
          switch ( num mod rem ) {
            | 0 => rem
            | _ => prime(rem + 1)
          };

        loop(num + 17, count + ( num != prime(2) ? 1 : 0 ));
      }
      | false => count
    };

  loop(start, 0);
};

let parse = input =>
  input
    |> Js.String.split("\n")
    |> arr => Scanf.sscanf(arr[0], "%s %s %d", ( _, _, num ) => num);

let solve = ( ~input = Input.input, solver ) =>
  input
    |> parse
    |> solver;

Js.log2("Day 23, Part 1:", solve(part1));
Js.log2("Day 23, Part 2:", solve(part2));
