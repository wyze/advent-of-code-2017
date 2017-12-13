module IntSet =
  Set.Make({
    type t = int;

    let compare = ( x, y ) =>
      switch ( x === y ) {
        | true => 0
        | false => x - y
      };
  });

let walkGraph = ( start, graph ) => {
  let rec walk = ( visited, queue ) => IntSet.(
    switch queue {
      | [ program, ...rest ] when ! mem(program, visited) =>
        walk(add(program, visited), rest @ Hashtbl.find(graph, program))
      | [ _, ...rest ] => walk(visited, rest)
      | [] => visited
    }
  );

  walk(IntSet.empty, [ start ]);
};

let makeGraph = input => {
  let graph = Hashtbl.create(List.length(input));

  List.iter((( program, connections )) =>
    Hashtbl.add(graph, program, connections),
    input
  );

  graph;
};

let part1 = programs =>
  programs |> makeGraph |> walkGraph(0) |> IntSet.cardinal;

let part2 = programs => {
  let graph = programs |> makeGraph;
  let rec count = ( seen, groups, index ) =>
    switch ( List.length(programs) == index ) {
      | true => groups
      | false => IntSet.(switch ( mem(index, seen) ) {
          | true => count(seen, groups, index + 1)
          | false => count((graph |> walkGraph(index) |> union(seen)), groups + 1, index + 1)
        })
    };

  count(IntSet.empty, 0, 0);
};

let parse = input => {
  let ( program, connections ) = switch ( Js.String.split(" <-> ", input) ) {
    | [| program, connections |] => ( program, connections )
    | _ => ( "", "" )
  };

  (
    int_of_string(program),
    connections
      |> Js.String.split(", ")
      |> Array.map(int_of_string)
      |> Array.to_list
  );
};

let solve = ( ~input = Input.input, solver ) =>
  input
    |> Js.String.split("\n")
    |> Array.map(parse)
    |> Array.to_list
    |> solver;

Js.log2("Day 12, Part 1:", solve(part1));
Js.log2("Day 12, Part 2:", solve(part2));
