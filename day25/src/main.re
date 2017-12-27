module IntSet =
  Set.Make({
    type t = int;

    let compare = ( x, y ) =>
      switch ( x === y ) {
        | true => 0
        | false => x - y
      };
  });

type state =
  | A
  | B
  | C
  | D
  | E
  | F;

type machine = {
  cursor: int,
  tape: IntSet.t,
  state: state,
};

let transition = machine => {
  let advance = ({ cursor, state, tape }) => {
    let on = IntSet.mem(cursor, tape);

    IntSet.(
      switch state {
        | A when ! on => ( add, 1, B )
        | A => ( remove, (-1), C )
        | B when ! on => ( add, (-1), A )
        | B => ( add, 1, C )
        | C when ! on => ( add, 1, A )
        | C => ( remove, (-1), D )
        | D when ! on => ( add, (-1), E )
        | D => ( add, (-1), C )
        | E when ! on => ( add, 1, F )
        | E => ( add, 1, A )
        | F when ! on => ( add, 1, A )
        | F => ( add, 1, E )
      }
    );
  };
  let ( update, shift, next ) = advance(machine);
  let tape = update(machine.cursor, machine.tape);

  { tape, state: next, cursor: machine.cursor + shift };
};

let part1 = iterations => {
  let rec loop = ( n, machine ) =>
    switch n {
      | 0 => IntSet.cardinal(machine.tape)
      | _ => loop(n - 1, transition(machine))
    };

  loop(iterations, { tape: IntSet.empty, state: A, cursor: 0 });
};

let solve = ( ~iterations = 12261544, solver ) =>
  solver(iterations);

Js.log2("Day 25, Part 1:", solve(part1));
