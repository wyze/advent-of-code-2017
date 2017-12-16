type generator = {
  divisor: int,
  factor: int,
  value: int,
};

let bitwiseEqual = ( a, b ) =>
  a land 65535 == b land 65535;

let moduloOfFactor: ( int, int ) => int = [%raw {|
  function ( factor, x ) {
    return ( x * factor ) % 2147483647
  }
|}];

let rec update = generator => {
  let next = { ...generator, value: moduloOfFactor(generator.factor, generator.value) };

  switch ( next.value mod generator.divisor ) {
    | 0 => next
    | _ => update(next)
  };
};

let rec count = ( matches, ( a, b ), index ) =>
  switch index {
    | 0 => matches
    | _ => {
      let ( nextA, nextB ) = ( update(a), update(b) );

      count(
        bitwiseEqual(nextA.value, nextB.value) ? matches + 1 : matches,
        ( nextA, nextB ),
        index - 1
      );
    }
  };

let part1 = (( a, b )) =>
  count(
    0,
    (
      { divisor: 1, factor: 16807, value: a },
      { divisor: 1, factor: 48271, value: b }
    ),
    40000000
  );

let part2 = (( a, b )) =>
  count(
    0,
    (
      { divisor: 4, factor: 16807, value: a },
      { divisor: 8, factor: 48271, value: b }
    ),
    5000000
  );

let parse = input => {
  let values = input
    |> Js.String.split("\n")
    |> Array.map(line =>
      switch ( line |> Js.String.split(" ") |> Js.Array.pop ) {
        | Some(n) => int_of_string(n)
        | None => 0
      }
    );

  switch values {
    | [| a, b |] => ( a, b )
    | _ => ( 0, 0 )
  };
};

let solve = ( ~input = Input.input, solver ) =>
  input
    |> parse
    |> solver;

Js.log2("Day 15, Part 1:", solve(part1));
Js.log2("Day 15, Part 2:", solve(part2));
