type pervasive('a) = ( int, int ) => 'a;

type condition = {
  amount: int,
  predicate: pervasive(bool),
  register: string,
};

type instruction = {
  amount: int,
  condition,
  op: pervasive(int),
  register: string,
};

let toInstruction = line => {
  let [| register, op, amount, _, cond_register, predicate, cond_amount |] =
    line |> Js.String.split(" ");

  {
    amount: amount |> int_of_string,
    condition: {
      amount: cond_amount |> int_of_string,
      register: cond_register,
      predicate: switch predicate {
        | "<" => (<)
        | ">" => (>)
        | "<=" => (<=)
        | ">=" => (>=)
        | "==" => (==)
        | "!=" => (!=)
        | _ => raise(Failure("Could not parse instruction"))
      },
    },
    op: switch op {
      | "inc" => (+)
      | "dec" => (-)
      | _ => raise(Failure("Could not parse instruction"))
    },
    register,
  };
};

let process = instructions => {
  let dict: Js.Dict.t(int) = Js.Dict.empty();
  let get = register => switch ( Js.Dict.get(dict, register) ) {
    | None => 0
    | Some(value) => value
  };
  let set = ( register, value ) => Js.Dict.set(dict, register, value);
  let highest = ref(0);

  instructions |> Array.iter(
    ({ amount, condition, op, register }) => {
      let existingValue = get(condition.register);

      if ( condition.predicate(existingValue, condition.amount) ) {
        let value = get(register);
        let newValue = op(value, amount);

        if ( newValue > highest^ ) {
          highest := newValue;
        };

        set(register, newValue);
      }
    }
  );

  ( Js.Dict.values(dict), highest^ );
};

let largestEndingRegister = instructions =>
  instructions
    |> process
    |> fst
    |> Js.Array.sortInPlaceWith((-))
    |> Js.Array.reverseInPlace
    |> Array.to_list
    |> List.hd;

let highestValuedRegister = instructions =>
  instructions
    |> process
    |> snd;

let solve = ( ~input = Input.input, solver ) =>
  input
    |> Js.String.split("\n")
    |> Array.map(toInstruction)
    |> solver;

Js.log2("Day 08, Part 1:", solve(largestEndingRegister));
Js.log2("Day 08, Part 2:", solve(highestValuedRegister));
