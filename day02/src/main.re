let parseAndSort = input =>
  input
    |> Js.String.split("\n")
    |> Array.map(row =>
        row
          |> Js.String.split("\t")
          |> Array.map(int_of_string)
          |> Js.Array.sortInPlaceWith(( a, b ) => a - b)
          |> Array.to_list
      )
    |> Array.to_list;

let diff = nums =>
  (nums |> List.rev |> List.hd) - List.hd(nums);

let diviser = ( left, current, right ) =>
  switch current {
    | 0 => switch (left mod right) {
      | 0 => left / right
      | _ => switch (right mod left) {
        | 0 => right / left
        | _ => 0
      }
    }
    | _ => current
  };

let rec divisible = numbers =>
  switch numbers {
    | [] => 0
    | [ head, ...tail ] => {
      switch (List.fold_left(diviser(head), 0, tail)) {
        | 0 => divisible(tail)
        | n => n
      };
    }
  };

let getOutput = ( ~input = Input.input, mapper ) =>
  input
    |> parseAndSort
    |> List.map(mapper)
    |> List.fold_left((+), 0);

Js.log2("Day 02, Part 1:", getOutput(diff));
Js.log2("Day 02, Part 2:", getOutput(divisible));
