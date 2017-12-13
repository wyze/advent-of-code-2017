let process = ( total, input ) =>
  switch input {
    | [ layer, depth ] =>
      switch ( layer mod (( depth - 1 ) * 2) ) {
        | 0 => total + ( layer * depth )
        | _ => total
      }
    | _ => 0
  };

let willGetCaught = ( delay, input ) =>
  switch input {
    | [ layer, depth ] => ( layer + delay ) mod ( 2 * depth - 2 ) == 0
    | _ => false
  };

let isCaught = ( delay, layers ) =>
  layers |> List.find(willGetCaught(delay));

let findPicoseconds = layers => {
  let rec checkDelay = delay =>
    switch ( isCaught(delay, layers) ) {
      | exception _ => delay
      | _ => checkDelay(delay + 1)
    };

  checkDelay(0);
};

let part1 = input =>
  input |> Array.fold_left(process, 0);

let part2 = input =>
  input |> Array.to_list |> findPicoseconds;

let parse = input =>
  input
    |> Js.String.split(": ")
    |> Array.map(int_of_string)
    |> Array.to_list;

let solve = ( ~input = Input.input, solver ) =>
  input
    |> Js.String.split("\n")
    |> Array.map(parse)
    |> solver;

Js.log2("Day 13, Part 1:", solve(part1));
Js.log2("Day 13, Part 2:", solve(part2));
