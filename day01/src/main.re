let createGetChar = ( input, modifier ) => index =>
  Js.String.(get(input, (index + modifier) mod length(input)));

let createMatcher = getChar => ( a, ( i, v ) ) =>
  switch (getChar(i) == v) {
    | true => a + int_of_string(v)
    | false => a
  };

let getOutput = (~input = Input.input, getModifier) => {
  let modifier = getModifier(input);

  input
    |> Js.String.split("")
    |> Array.to_list
    |> List.mapi(( i, s ) => (i, s))
    |> List.fold_left(createMatcher(createGetChar(input, modifier)), 0);
};

let part1 = getOutput((_) => 1);

let part2 = getOutput(s => String.length(s) / 2);

Js.log("Day 01, Part 1: " ++ string_of_int(part1));
Js.log("Day 01, Part 2: " ++ string_of_int(part2));
