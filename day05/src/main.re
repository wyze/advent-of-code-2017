let rec jump = ( position, steps, modifier, instructions ) =>
  switch instructions[position] {
    | exception _ => steps
    | current => {
      instructions[position] = modifier(current);

      jump(current + position, steps + 1, modifier, instructions);
    }
  };

let addOne = (+)(1);

let addOneOrSubtractOne = num =>
  num > 2 ? num - 1 : num + 1;

let solve = ( ~input = Input.input, modifier ) =>
  input
    |> Js.String.split("\n")
    |> Array.map(int_of_string)
    |> jump(0, 0, modifier);

Js.log2("Day 05, Part 1:", solve(addOne));
Js.log2("Day 05, Part 2:", solve(addOneOrSubtractOne));
