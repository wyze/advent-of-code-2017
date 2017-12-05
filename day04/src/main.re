let rec hasDuplicates = words =>
  switch words {
    | [] => false
    | [ word, ...rest ] =>
      switch ( List.filter((===)(word), rest) ) {
        | [] => hasDuplicates(rest)
        | _ => true
      };
  };

let sortWords = word =>
  word |> Js.String.split("") |> Js.Array.sortInPlace |> Js.Array.join;

let findDuplicates = ( mapWordsBy, row ) =>
  row
    |> Js.String.split(" ")
    |> Array.map(mapWordsBy)
    |> Array.to_list
    |> hasDuplicates
    |> (!);

let mapWordsBy = word => word;

let solve = ( ~input = Input.input, ~mapWordsBy = mapWordsBy, () ) =>
  input
    |> Js.String.split("\n")
    |> Js.Array.filter(findDuplicates(mapWordsBy))
    |> Array.length;

Js.log2("Day 04, Part 1:", solve());
Js.log2("Day 04, Part 2:", solve(~mapWordsBy=sortWords, ()));
