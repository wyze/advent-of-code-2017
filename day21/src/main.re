type rule = {
  input: array(string),
  output: array(string),
};

type op =
  | Rotate
  | Flip;

let reverse = str =>
  str |> Js.String.split("") |> Js.Array.reverseInPlace |> Js.Array.joinWith("");

let rotate = arr =>
  arr
    |> Js.Array.reverseInPlace
    |> Array.fold_left(
        ( acc, image ) => {
          image
            |> Js.String.split("")
            |> Array.mapi(( n, char ) => {
                acc[n] ++ char
              });
        },
        Array.init(Array.length(arr), (_) => "")
      );

let makeTransforms = ( transforms, { input, output } ) => {
  let hash = Js.Array.joinWith("");
  let set = value => Js.Dict.set(transforms, hash(value), hash(output));
  let rec loop = ( ops, input ) =>
    switch ops {
      | [] => ()
      | [ hd, ...tl ] => {
        let inp = switch hd {
          | Rotate => rotate(input)
          | Flip => Array.map(reverse, input)
        };

        set(inp);
        loop(tl, inp);
      }
    };

  set(input);
  loop([ Rotate, Rotate, Rotate, Flip, Rotate, Rotate, Rotate ], input);
};

let rec move = ( iterations, arr, transforms ) => {
  switch iterations {
    | 0 => arr
    | _ => {
      let size = 2 + Array.length(arr) mod 2;
      let sizePlus1 = size + 1;
      let len = Array.length(arr) / size;
      let chunks = Array.init(len, (_) => Array.init(len, (_) => ""));
      let transformed = Array.init(Array.length(chunks) * sizePlus1, (_) => "");
      let get = key =>
        switch ( Js.Dict.get(transforms, key) ) {
          | None => ""
          | Some(value) => value
        };

      let _ = arr
        |> Array.iteri(
            ( y, row ) =>
              row
                |> Js.String.split("")
                |> Array.iteri(( x, col ) =>
                    chunks[y / size][x / size] = chunks[y / size][x / size] ++ col
                  )
          );

      let _ = chunks
        |> Array.map(row => Array.map(get, row))
        |> Array.mapi(( y, row ) =>
            row
              |> Array.mapi(( _, col ) =>
                  col
                    |> Js.String.split("")
                    |> Array.iteri(( n, char ) => {
                        let pos = y * sizePlus1 + ( n / sizePlus1 );

                        transformed[pos] = transformed[pos] ++ char;
                      })
            )
          );

      move(iterations - 1, transformed, transforms);
    }
  };
};

let init = [| ".#.", "..#", "###" |];

let part1 = move(5, init);

let part2 = move(18, init);

let build = input => {
  let transforms = Js.Dict.empty();
  let _ = input |> List.iter(makeTransforms(transforms));

  transforms;
};

let count = input =>
  input
    |> Array.fold_left(
      ( cnt, row ) => cnt + (
        row
          |> Js.String.replaceByRe([%re "/\\./g"], "")
          |> String.length
      ),
      0
    );

let stringToRule = line =>
  Scanf.sscanf(
    line,
    "%s => %s",
    ( input, output ) => {
      input: Js.String.split("/", input),
      output: Js.String.split("/", output),
    }
  );

let parse = input =>
  input
    |> Js.String.split("\n")
    |> Array.map(stringToRule)
    |> Array.to_list;

let solve = ( ~input = Input.input, solver ) =>
  input
    |> parse
    |> build
    |> solver
    |> count;

Js.log2("Day 21, Part 1:", solve(part1));
Js.log2("Day 21, Part 2:", solve(part2));
