type variables = {
  array: array(array(int)),
  arraySize: int,
  input: int,
};

let getArraySize = num =>
  num |> float |> sqrt |> ceil |> truncate;

let numberOfSteps = input => {
  let arraySize = getArraySize(input);
  let arraySizeAdjusted = arraySize != 1 && arraySize mod 2 != 0 ? arraySize : arraySize + 1;
  let middlePoint = (arraySizeAdjusted - 1) / 2;
  let cycle = input - truncate((float(arraySizeAdjusted - 2) ** 2.0));
  let innerOffset = cycle mod (arraySizeAdjusted - 1);

  middlePoint + abs(innerOffset - middlePoint);
};

let adjacentSquares = [
  ( (-1), (-1) ),
  ( (-1), 0 ),
  ( (-1), 1 ),
  ( 0, (-1) ),
  ( 0, 1 ),
  ( 1, (-1) ),
  ( 1, 0 ),
  ( 1, 1 )
];

let adjacentSquaresValue = ( x, y, array ) =>
  adjacentSquares
    |> List.map((( dx, dy )) =>
        switch array[x + dx][y + dy] {
          | value => value
          | exception ( Invalid_argument("index out of bounds") ) => 0
        }
      )
    |> List.fold_left((+), 0);

let createOutOfBounds = input => xOrY => xOrY < 0 || xOrY >= input;

let shouldTurn = ( ( x, y ), array, outOfBounds ) =>
  outOfBounds(x) || outOfBounds(y) || array[x][y] == 0;

let step = ( x, y, ( dx, dy ) ) => ( x + dx, y + dy );

let turn = (( x, y )) => ( -y, x );

let rec calculate = ( ( x, y ), point, pass, variables ) => {
  let { array, arraySize, input } = variables;
  let value = pass === 1 ? 1 : adjacentSquaresValue(x, y, array);
  let valueGreaterThanInput = value > input;
  let passLessThanMaxArraySize = pass < arraySize * arraySize - 1;
  let returnValueOrRecurse = ( valueGreaterThanInput, passLessThanMaxArraySize );

  switch array[x][y] {
    | _ => array[x][y] = value
    | exception ( Invalid_argument("index out of bounds") ) => ()
  };

  switch returnValueOrRecurse {
    | ( true, _ ) => value
    | ( _, true ) => {
        let stepXY = step(x, y);
        let turned = turn(point);
        let next = shouldTurn(stepXY(turned), array, createOutOfBounds(input))
          ? turned : point;

        calculate(stepXY(next), next, pass + 1, variables);
      }
    | ( _, _ ) => value + 1
  };
};

let nextLargerValue = input => {
  let arraySize = getArraySize(input) + 1;
  let array = Array.make_matrix(arraySize, arraySize, 0);
  let half = arraySize / 2;
  let variables = { array, arraySize, input };

  calculate(( half, half ), ( 1, 0 ), 1, variables);
};

let solve = ( ~input: int = Input.input, process ) =>
  process(input);

Js.log2("Day 03, Part 1:", solve(numberOfSteps));
Js.log2("Day 03, Part 2:", solve(nextLargerValue));
