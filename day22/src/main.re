type direction =
  | Left
  | Right
  | Reverse;

type flag =
  | Clean
  | Flagged
  | Infected
  | Weakened;

let makeKey = ( row, col ) =>
  Printf.sprintf("%d,%d", row, col);

let (+=) = (( r1, c1 ), ( r2, c2 )) =>
  ( r1 + r2, c1 + c2 );

let flagToChar = flag =>
  switch flag {
    | Clean => '.'
    | Flagged => 'F'
    | Infected => '#'
    | Weakened => 'W'
  };

let charToFlag = char =>
  switch char {
    | '.' => Clean
    | 'F' => Flagged
    | '#' => Infected
    | 'W' => Weakened
    | _ => raise(Failure("Unable to parse character"))
  };

let update = ( tbl, key, flag ) =>
  switch flag {
    | Clean => {
      Hashtbl.replace(tbl, key, Weakened |> flagToChar);

      false;
    }
    | Flagged => {
      Hashtbl.remove(tbl, key);

      false;
    }
    | Infected => {
      Hashtbl.replace(tbl, key, Flagged |> flagToChar);

      false;
    }
    | Weakened => {
      Hashtbl.replace(tbl, key, Infected |> flagToChar);

      true;
    }
  };

let turn = ( direction, ( row, col ) ) =>
  switch direction {
    | Left => ( ~-col, row )
    | Right => ( col, ~-row )
    | Reverse => ( ~-row, ~-col )
  };

let getFlag = ( tbl, key ) =>
  switch ( Hashtbl.find(tbl, key) ) {
    | value => value
    | exception _ => Clean |> flagToChar
  }
    |> charToFlag;

let move = ( direction, flag ) =>
  switch flag {
    | Clean => turn(Left, direction)
    | Flagged => turn(Reverse, direction)
    | Infected => turn(Right, direction)
    | Weakened => direction
  };

let part1 = (( tbl, position )) => {
  let rec loop = ( iterations, ( row, col ) as p, d, count ) =>
    switch iterations {
      | 10000 => count
      | _ => {
        let key = makeKey(row, col);
        let ( dir, cnt ) = switch ( Hashtbl.mem(tbl, key) ) {
          | true => {
            Hashtbl.remove(tbl, key);

            ( turn(Right, d), count );
          }
          | false => {
            Hashtbl.add(tbl, key, Infected |> flagToChar);

            ( turn(Left, d), count + 1 );
          }
        };

        loop(iterations + 1, p += dir, dir, cnt);
      }
    };

  loop(0, position, ( -1, 0 ), 0);
};

let part2 = (( tbl, position )) => {
  let rec loop = ( iterations, ( row, col ) as p, d, count ) =>
    switch iterations {
      | 10000000 => count
      | _ => {
        let key = makeKey(row, col);
        let state = getFlag(tbl, key);
        let infected = update(tbl, key, state);
        let dir = move(d, state);

        loop(iterations + 1, p += dir, dir, infected ? count + 1 : count);
      }
    };

  loop(0, position, ( -1, 0 ), 0);
};

let parse = input => {
  let tbl = Hashtbl.create(100000);
  let half = arr => (Array.length(arr) / 2);
  let grid = input
    |> Js.String.split("\n")
    |> Array.mapi(( row, line ) =>
        line
          |> Js.String.split("")
          |> Array.mapi(( col, char ) =>
              if ( char == "#" ) {
                Hashtbl.add(tbl, makeKey(row, col), Infected |> flagToChar)
              }
            )
      );

  ( tbl, ( half(grid), half(grid[0]) ) );
};

let solve = ( ~input = Input.input, solver ) =>
  input
    |> parse
    |> solver;

Js.log2("Day 22, Part 1:", solve(part1));
Js.log2("Day 22, Part 2:", solve(part2));
