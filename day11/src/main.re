let distance = (( x, y )) =>
  (abs(x) + abs(y) + abs(x + y)) / 2;

let process = ( (( x, y ), max ), direction ) => {
  let coord = switch direction {
    | "n" => ( x, y + 1 )
    | "ne" => ( x + 1, y )
    | "se" => ( x + 1, y - 1 )
    | "s" => ( x, y - 1 )
    | "sw" => ( x - 1, y )
    | "nw" => ( x - 1, y + 1 )
    | _ => raise(Failure("Invalid direction"))
  };

  (coord, Js.Math.max_int(distance(coord), max));
};

let part1 = input =>
  input |> fst |> distance;

let part2 = input =>
  input |> snd;

let solve = ( ~input = Input.input, solver ) =>
  input
    |> Js.String.split(",")
    |> Array.fold_left(process, (( 0, 0 ), 0 ))
    |> solver;

Js.log2("Day 10, Part 1:", solve(part1));
Js.log2("Day 10, Part 2:", solve(part2));
