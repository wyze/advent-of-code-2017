type component = {
  left: int,
  right: int,
};

let rec process = ( input, ( strength, length ) as maxInProcess, getMax, parts ) => {
  let rec loop = ( index, maxInLoop ) =>
    switch ( index > Array.length(parts) - 1 ) {
      | true => maxInLoop
      | false => {
        let { left, right } = parts[index];
        let newMax = if ( left == input || right == input ) {
          let flippedInput = left == input ? right : left;
          parts[index] = { left: -1, right: -1 };
          let current = process(flippedInput, ( strength + left + right, length + 1 ), getMax, parts);
          parts[index] = { left, right };
          getMax(maxInLoop, current);
        } else {
          maxInLoop
        };

        loop(index + 1, newMax);
      }
    };

  loop(0, maxInProcess);
};

let strongest = ( ( maxStrength, _ ) as max, ( strength, _ ) as current ) =>
  strength > maxStrength ? current : max;

let longestStrongest = (( maxStrength, maxLength ) as max, ( strength, length ) as current ) =>
  length > maxLength || (length == maxLength && strength > maxStrength)
    ? current
    : max;

let part1 = parts =>
  parts
    |> process(0, ( 0, 0 ), strongest)
    |> fst;

let part2 = parts =>
  parts
    |> process(0, ( 0, 0 ), longestStrongest)
    |> fst;

let parse = input =>
  input
    |> Js.String.split("\n")
    |> Array.map(line =>
        Scanf.sscanf(line, "%d/%d", ( left, right ) => { left, right })
      );

let solve = ( ~input = Input.input, solver ) =>
  input
    |> parse
    |> solver;

Js.log2("Day 24, Part 1:", solve(part1));
Js.log2("Day 24, Part 2:", solve(part2));
