let alwaysOne = (_) => 1;

let halfOfString = s => String.length(s) / 2;

let solve = ( ~input = Input.input, ~getInputModifier = alwaysOne, () ) =>
  input
    |> Js.String.split("")
    |> Array.mapi(( index, str ) =>
        ( ( index + getInputModifier(input) ) mod String.length(input), str )
      )
    |> Array.map((( index, str )) =>
        Js.String.get(input, index) === str ? int_of_string(str) : 0
      )
    |> Array.fold_left((+), 0);

Js.log2("Day 01, Part 1: ", solve());
Js.log2("Day 01, Part 2: ", solve(~getInputModifier = halfOfString, ()));
