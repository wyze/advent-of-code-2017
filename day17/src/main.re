let rec take = ( count, nlst, lst ) =>
  switch ( lst, List.length(nlst) == count ) {
    | ( _, true )
    | ( [], _ ) => nlst |> List.rev
    | ( [ hd, ...rest ], _ ) => take(count, [ hd, ...nlst ], rest)
  };

let rec drop = ( count, nlst, lst ) =>
  switch ( lst, List.length(nlst) == count ) {
    | ( _, true )
    | ( [], _ ) => lst
    | ( [ hd, ...rest ], _ ) => drop(count, [ hd, ...nlst ], rest)
  };

let rec findIndex = ( value, lst ) =>
  switch lst {
    | [] => raise(Failure("Not Found"))
    | [ hd, ...rest ] => switch ( value === hd ) {
      | true => 0
      | false => findIndex(value, rest) |> succ
    }
  };

let part1 = input => {
  let spinlock = steps => {
    let rec step = ( position, index, lst ) => {
      let nextPosition = ( position + steps ) mod index;
      let front = take(nextPosition + 1, [], lst);
      let back = drop(nextPosition + 1, [], lst);
      let nextLst = front @ [ index, ...back ];

      switch index {
        | 2017 => nextLst
        | _ => step(nextPosition + 1, index + 1, nextLst)
      };
    };

    step(0, 1, [0]);
  };
  let lst = spinlock(input);
  let indexAfter2017 = lst |> findIndex(2017) |> (+)(1);

  List.nth(lst, indexAfter2017);
};

let part2 = input => {
  let spinlock = steps => {
    let rec step = ( position, index, after0 ) => {
      let nextPosition = ( position + steps ) mod index;

      switch index {
        | 50000000 => after0
        | _ => step(nextPosition + 1, index + 1, (nextPosition == 0 ? index : after0))
      };
    };

    step(0, 1, 0);
  };

  spinlock(input);
};

let solve = ( ~input = Input.input, solver ) =>
  input
    |> solver;

Js.log2("Day 17, Part 1:", solve(part1));
Js.log2("Day 17, Part 2:", solve(part2));
