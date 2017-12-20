open Jest;

describe("day 19", () => {
  open Expect;

  describe("part 1", () => {
    test("seen `ABCDEF`", () => {
      let input = "      |          \n      |  +--+    \n      A  |  C    \n  F---|----E|--+ \n      |  |  |  D \n      +B-+  +--+ ";
      let actual = Main.(solve(~input, part1));
      let expected = "ABCDEF";

      expect(actual) |> toBe(expected);
    });
  });

  describe("part 2", () => {
    test("steps made = 38", () => {
      let input = "      |          \n      |  +--+    \n      A  |  C    \n  F---|----E|--+ \n      |  |  |  D \n      +B-+  +--+ ";
      let actual = Main.(solve(~input, part2));
      let expected = 38;

      expect(actual) |> toBe(expected);
    });
  });
});
