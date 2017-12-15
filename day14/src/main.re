[@bs.val] external parseInt : ( string, int ) => int = "parseInt";

let parseInt' = ( radix, num ) => parseInt(num, radix);

let rec padBin = num =>
  switch ( String.length(num) ) {
    | 4 => num
    | _ => padBin("0" ++ num)
  };

let hexToBin = char =>
  char
    |> Js.String.fromCharCode
    |> parseInt'(16)
    |> Js.Int.toStringWithRadix(~radix = 2)
    |> padBin;

let part1 = input =>
  input
    |> Array.map(char => char |> List.filter((===)('1')) |> List.length)
    |> Array.fold_left((+), 0);

let inRange = ( min: int, max: int, num: int ) =>
  num >= min && num <= max;

let rec visitRegion = ( x, y, board ) => {
  let inRange = inRange(0, 127);

  if ( inRange(x) && inRange(y) ) {
    if ( board[x][y] == '1' ) {
      board[x][y] = '0';

      visitRegion(x - 1, y, board);
      visitRegion(x + 1, y, board);
      visitRegion(x, y - 1, board);
      visitRegion(x, y + 1, board);
    };
  };
};

let rec countRegions = ( position, regions, board) =>
  switch ( position >= 128 * 128 ) {
    | true => regions
    | false => {
      let x = position / 128;
      let y = position mod 128;
      let next = board[x][y] |> Char.escaped |> int_of_string;

      visitRegion(x, y, board);
      countRegions(position + 1, regions + next, board);
    }
  };

let part2 = input =>
  input
    |> Array.(map(of_list))
    |> countRegions(0, 0);

let getBinaryCharListOfKnotHash = ( input, index ) => KnotHash.(
  Printf.sprintf("%s-%d", input, index)
    |> knotHash
    |> stringToCharList
    |> List.map(char => char |> Char.code |> hexToBin)
    |> Array.of_list
    |> Js.Array.joinWith("")
    |> stringToCharList
);

let solve = ( ~input = Input.input, solver ) =>
  Array.init(128, getBinaryCharListOfKnotHash(input))
    |> solver;

Js.log2("Day 14, Part 1:", solve(part1));
Js.log2("Day 14, Part 2:", solve(part2));
