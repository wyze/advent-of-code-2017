type point = {
  x: int,
  y: int,
};

type direction =
  | Up
  | Down
  | Left
  | Right;

type state = {
  position: point,
  direction,
  letters: string,
  steps: int,
};

let getString = ( input, { x, y } ) =>
  switch input[y][x] {
    | exception _ => " "
    | item => item
  };

let step = ( { x, y }, direction ) =>
  switch direction {
    | Up => { x, y: y - 1 }
    | Down => { x, y: y + 1 }
    | Left => { x: x + 1, y }
    | Right => { x: x - 1, y }
  };

let possibleTurns = ({ x }) =>
  switch ( x == 0 ) {
    | true => [ Left, Right ]
    | false => [ Up, Down ]
  };

let turn = ( get, { position, direction } ) =>
  step({ x: 0, y: 0 }, direction)
    |> possibleTurns
    |> List.find(direction =>
        switch ( get(step(position, direction)) ) {
          | " " => false
          | exception _ => false
          | _ => true
        }
      );

let up = state =>
  { ...state, steps: state.steps |> succ };

let rec move = (( input, state )) => {
  let position = step(state.position, state.direction);
  let get = getString(input);
  let char = get(position) |> Js.String.charCodeAt(0) |> truncate |> Char.chr;

  switch ( char ) {
    | 'A'..'Z' => move(( input, up({ ...state, position, letters: state.letters ++ get(position) }) ))
    | ' ' =>
      switch ( turn(get, state) ) {
        | direction => move(( input, { ...state, direction } ))
        | exception _ => up(state)
      }
    | _ => move(( input, up({ ...state, position }) ))
  };
};

let part1 = ({ letters }) => letters;

let part2 = ({ steps }) => steps;

let parse = input =>
  input
    |> Js.String.split("\n")
    |> Array.map(Js.String.split(""));

let init = input =>
  (
    input,
    {
      position: {
        x: Js.Array.indexOf("|", input[0]),
        y: 0,
      },
      direction: Down,
      letters: "",
      steps: 0,
    }
  );

let solve = ( ~input = Input.input, solver ) =>
  input
    |> parse
    |> init
    |> move
    |> solver;

Js.log2("Day 19, Part 1:", solve(part1));
Js.log2("Day 19, Part 2:", solve(part2));
