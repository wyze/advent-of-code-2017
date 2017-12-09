type tower = {
  children: list(Js.String.t),
  name: string,
  weight: int,
};

type unbalanced = {
  index: int,
  balanced: int,
};

let weightAsInt = weight =>
  String.(sub(weight, 1, length(weight) - 2)) |> int_of_string;

let towerize = ( towers, input ) => [
  switch ( Js.String.split(" ", input) |> Array.to_list ) {
    | [ name, weight, _, ...children ] => {
        children: children |> List.map(Js.String.replace(",", "")),
        name,
        weight: weight |> weightAsInt,
      }
    | [ name, weight ] => { children: [], name, weight: weight |> weightAsInt }
    | _ => { children: [], name: "", weight: 0 }
  },
  ...towers
];

let lookupWeight = weights =>
  switch weights {
    | [ x, y, z, ..._ ] => x === y ? x : z;
    | _ => 0
  };

let unbalanced = weights => {
  let balanced = lookupWeight(weights);

  {
    index: Js.Array.findIndex(weight => weight !== balanced, weights |> Array.of_list),
    balanced,
  };
};

let sum = List.fold_left((+), 0);

let nthAt1 = weights => switch ( List.nth(weights, 1) ) {
  | exception _ => 0
  | v => v
};

let findWeights = childrenWeights =>
  switch ( List.find(weights => nthAt1(weights) !== 0, childrenWeights) ) {
    | [ _, weights ] => weights
    | exception _ => 0
    | _ => 0
  };

let rec findUnbalanced = ( towers, { children, weight } ) => {
  let filteredChildren = List.(
    map(child => find(({ name }) => name == child, towers), children)
  );
  let unbalancedChildren = List.map(findUnbalanced(towers), filteredChildren);
  let childrenWeights = List.(map(hd, unbalancedChildren));
  let weights = findWeights(unbalancedChildren);
  let { index, balanced } = unbalanced(childrenWeights);

  switch ( children, weights != 0 || index < 0 || balanced == 0 ) {
    | ( [], _ ) => [ weight, 0 ]
    | ( _, true ) => [ List.(weight + hd(childrenWeights) * length(childrenWeights)), weights ]
    | ( _, _ ) => {
      let subtower = List.(
        find(({ name }) => name == nth(filteredChildren, index).name, towers)
      );
      let wsi = -List.nth(childrenWeights, index);
      let left = [ weight, sum(childrenWeights), balanced, wsi ] |> sum;
      let right = [ subtower.weight, balanced, wsi ] |> sum;

      [ left, right ];
    }
  };
};

let getRootName = towers => {
  let children = List.(
    towers
      |> map(tower => tower.children)
      |> flatten
  );
  let names = List.(
    towers
      |> filter(tower => length(tower.children) !== 0)
      |> map(tower => tower.name)
  );

  List.(
    names
      |> find(tower => ! mem(tower, children))
  );
};

let getNeededWeight = towers => {
  let rootName = getRootName(towers);
  let root = List.find(tower => tower.name === rootName, towers);

  findUnbalanced(towers, root) |> List.rev |> List.hd;
};

let solve = ( ~input = Input.input, solver ) =>
  input
    |> Js.String.split("\n")
    |> Array.fold_left(towerize, [])
    |> solver;

Js.log2("Day 07, Part 1:", solve(getRootName));
Js.log2("Day 07, Part 2:", solve(getNeededWeight));
