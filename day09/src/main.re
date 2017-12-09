let rec process = ( score, garbages, garbage, group, input ) =>
  switch input {
    | [] => ( score, garbages )
    | [ "{", ...rest ] when ! garbage =>
      process(score, garbages, garbage, group + 1, rest)
    | [ "}", ...rest ] when ! garbage =>
      process(score + group, garbages, garbage, group - 1, rest)
    | [ "<", ...rest ] when ! garbage =>
      process(score, garbages, true, group, rest)
    | [ ">", ...rest ] => process(score, garbages, false, group, rest)
    | [ "!", _, ...rest ] => process(score, garbages, garbage, group, rest)
    | [ _, ...rest ] when garbage =>
      process(score, garbages + 1, garbage, group, rest)
    | [ _, ...rest ] => process(score, garbages, garbage, group, rest)
  };

let solve = ( ~input = Input.input, solver ) =>
  input
    |> Js.String.split("")
    |> Array.to_list
    |> process(0, 0, false, 0)
    |> solver;

Js.log2("Day 09, Part 1:", solve(fst));
Js.log2("Day 09, Part 2:", solve(snd));
