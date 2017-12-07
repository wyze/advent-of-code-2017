let highestWithIndex = numbers =>
  numbers
    |> Array.mapi(( index, number ) => ( number, index ))
    |> Array.fold_left(( highest, current ) =>
        fst(highest) < fst(current) ? current : highest,
        ( 0, 0 )
      );

let zeroAt = index =>
  Array.mapi(( idx, number ) => index === idx ? 0 : number);

let keyify = Js.Array.joinWith("-");

let rec increase = ( remaining, index, numbers ) => {
  let exists = index < Array.length(numbers);

  switch ( ( remaining, exists ) ) {
    | ( 0, _ ) => numbers
    | ( _, false ) => increase(remaining, 0, numbers)
    | ( _, _ ) => {
      numbers[index] = numbers[index] + 1;

      increase(remaining - 1, index + 1, numbers);
    }
  };
};

let rec cycle = ( previous, again, numbers ) => {
  let ( highest, index ) = highestWithIndex(numbers);
  let next = increase(highest, index + 1, zeroAt(index, numbers));
  let lookup = keyify(next);
  let found = switch ( List.find(item => fst(item) === lookup, previous) ) {
    | exception _ => ( "", 0 )
    | item => item
  };

  switch ( ( List.length(previous), fst(found), snd(found), again ) ) {
    | ( 0, _, _, _ ) => cycle([ ( keyify(numbers), 0 ), ( lookup, 1 ) ], again, next)
    | ( _, "", _, _ ) => cycle([ ( lookup, List.length(previous) ), ...previous ], again, next)
    | ( _, _, _, false ) => List.length(previous)
    | ( _, _, cycles, true ) => List.length(previous) - cycles
  };
};

let solve = ( ~input = Input.input, again ) =>
  input
    |> Js.String.split("\t")
    |> Array.map(int_of_string)
    |> cycle([], again);

Js.log2("Day 06, Part 1:", solve(false));
Js.log2("Day 06, Part 2:", solve(true));
