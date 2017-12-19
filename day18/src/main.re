type registers = Js.Dict.t(Int64.t);

type name = Js.Dict.key;

type value =
  | Name(name)
  | Number(Int64.t);

type instruction =
  | Send(value)
  | Sound(name)
  | Set(name, value)
  | Add(name, value)
  | Multiply(name, value)
  | Modulo(name, value)
  | Recover(name)
  | Receive(name)
  | Jump(value, value)
  | Done;

type program = {
  position: int,
  queue: list(Int64.t),
  registers,
  sound: Int64.t,
  sent: int,
};

let makeProgram = pid => {
  let registers = Js.Dict.empty();

  Js.Dict.set(registers, "p", Int64.of_int(pid));

  {
    position: 0,
    queue: [],
    registers,
    sound: Int64.zero,
    sent: 0,
  }
};

let getRegister = ( registers, value ) =>
  switch value {
    | Number(num) => num
    | Name(name) =>
      switch ( Js.Dict.get(registers, name) ) {
        | Some(num) => num
        | None => Int64.zero
      }
  };

let move = ( program, num ) =>
  { ...program, position: program.position + num };

let send = ( program, num ) =>
  { ...program, queue: program.queue @ [ num ] };

let rec process = ( input, lastSound, program ) => {
  let { position, registers } = program;
  let get = getRegister(registers);
  let set = Js.Dict.set(registers);

  switch ( List.nth(input, position) ) {
    | Send(Name(reg)) =>
      ( Send(Number(get(Name(reg)))), { ...move(program, 1), sent: program.sent + 1 } )
    | Sound(reg) =>
      process(input, get(Name(reg)), move(program, 1))
    | Set(reg, value) => {
      set(reg, get(value));

      process(input, lastSound, move(program, 1));
    }
    | Add(reg, value) => {
      set(reg, Int64.add(get(Name(reg)), get(value)));

      process(input, lastSound, move(program, 1));
    }
    | Multiply(reg, value) => {
      set(reg, Int64.mul(get(Name(reg)), get(value)));

      process(input, lastSound, move(program, 1));
    }
    | Modulo(reg, value) => {
      set(reg, Int64.rem(get(Name(reg)), get(value)));

      process(input, lastSound, move(program, 1));
    }
    | Recover(reg) when get(Name(reg)) > Int64.zero => ( Done, { ...program, sound: lastSound } )
    | Recover(_) =>
      process(input, lastSound, move(program, 1))
    | Receive(reg) when List.length(program.queue) == 0 => ( Receive(reg), program )
    | Receive(reg) => {
      let ( head, tail ) = switch program.queue {
        | [] => ( Int64.zero, [] )
        | [ head, ...tail ] => ( head, tail )
      };

      set(reg, head);

      process(input, lastSound, { ...move(program, 1), queue: tail });
    }
    | Jump(reg, value) => {
      let jump = Int64.(get(reg) > zero ? to_int(get(value)) : 1);

      process(input, lastSound, move(program, jump));
    }
    | _ => raise(Failure("Unhandled operation"))
  };
};

let part1 = input => {
  let ( _, program ) = process(input, Int64.zero, makeProgram(0));

  Int64.to_int(program.sound);
};

let part2 = input => {
  let input2 =
    input |> List.map(
      instruction => switch instruction {
        | Sound(name) => Send(Name(name))
        | Recover(reg) => Receive(reg)
        | ins => ins
      }
    );

  let rec run = ( program0, program1 ) => {
    let ( ins0, program0 ) = process(input2, Int64.zero, program0);
    let ( ins1, program1 ) = process(input2, Int64.zero, program1);

    switch ( ins0, ins1 ) {
      | ( Done, Done )
      | ( Receive(_), Receive(_) ) => program1.sent
      | ( Send(Number(num0)), Send(Number(num1)) ) =>
        run(send(program0, num1), send(program1, num0))
      | ( Send(Number(num0)), _ ) => run(program0, send(program1, num0))
      | ( _, Send(Number(num1)) ) => run(send(program0, num1), program1)
      | _ => 0
    };
  };

  run(makeProgram(0), makeProgram(1));
};

let toValue = str =>
  switch ( String.get(str, 0) ) {
    | 'a'..'z' => Name(str)
    | _ => Number(Int64.of_string(str))
  };

let stringToInstruction = line =>
  switch ( Js.String.split(" ", line) ) {
    | [| "snd", reg |] => Sound(reg)
    | [| "set", reg, value |] => Set(reg, toValue(value))
    | [| "rcv", reg |] => Recover(reg)
    | [| "add", reg, value |] => Add(reg, toValue(value))
    | [| "mul", reg, value |] => Multiply(reg, toValue(value))
    | [| "mod", reg, value |] => Modulo(reg, toValue(value))
    | [| "jgz", reg, value |] => Jump(toValue(reg), toValue(value))
    | _ => raise(Failure("Unable to parse instruction"))
  };

let parse = input =>
  input
    |> Js.String.split("\n")
    |> Array.map(stringToInstruction)
    |> Array.to_list;

let solve = ( ~input = Input.input, solver ) =>
  input
    |> parse
    |> solver;

Js.log2("Day 18, Part 1:", solve(part1));
Js.log2("Day 18, Part 2:", solve(part2));
