type move =
  | Exchange(int, int)
  | Partner(char, char)
  | Spin(int);

let swap = ( arr, a, b ) => {
  let temp = arr[a];

  arr[a] = arr[b];
  arr[b] = temp;
};

let move = ( program, input ) => {
  Array.iter(
    move => switch move {
      | Exchange(a, b) => swap(program, a, b)
      | Partner(a, b) =>
        Js.Array.(swap(program, indexOf(a, program), indexOf(b, program)))
      | Spin(n) =>
        Js.Array.(Array.append(
          sliceFrom(Array.length(program) - n, program),
          slice(~start=0, ~end_=Array.length(program) - n, program)
        ))
        |> Array.iteri(( i, v ) => { program[i] = v });
    },
    input
  );

  program;
};

let part1 = ( program, input ) =>
  move(program, input);

let programToString = program =>
  program |> Array.map(Char.escaped) |> Js.Array.joinWith("");

let part2 = ( ~iterations = 1000000000, program, input ) => {
  let history = Hashtbl.create(100000);
  let rec process = ( program, index ) =>
    switch ( index < iterations ) {
      | false => program
      | true => switch ( Hashtbl.find(history, program |> programToString) ) {
        | exception _ => {
          Hashtbl.add(history, program |> programToString, index);

          process(move(program, input), index + 1);
        }
        | idx => {
          let size = index - idx;
          let next = index + (((iterations - index) / size) * size) + 1;

          next < iterations ? process(move(program, input), next) : program;
        }
      }
    };

  process(program, 0);
};

let stringToMove = line =>
  switch ( Js.String.split("", line)[0] ) {
    | "s" => Scanf.sscanf(line, "s%d", n => Spin(n))
    | "x" => Scanf.sscanf(line, "x%d/%d", ( a, b ) => Exchange(a, b))
    | "p" => Scanf.sscanf(line, "p%c/%c", ( a, b ) => Partner(a, b))
    | _ => raise(Failure("Unable to parse dance move"))
  };

let parse = input =>
  input
    |> Js.String.split(",")
    |> Array.map(stringToMove);

let defaultPrograms = Array.init(16, x => Char.chr(97 + x));

let solve = ( ~input = Input.input, ~programs = defaultPrograms, solver ) =>
  input
    |> parse
    |> solver(programs)
    |> programToString;

Js.log2("Day 16, Part 1:", solve(part1));
Js.log2("Day 16, Part 2:", solve(part2));
