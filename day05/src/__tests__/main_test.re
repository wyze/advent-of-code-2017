open Jest;

describe("day 5", () => {
  open Expect;

  describe("part 1", () => {
    test("`0 3 0 1 -3` = 5 steps", () => {
      let input = "0\n3\n0\n1\n-3";
      let actual = Main.(solve(~input, addOne));
      let expected = 5;

      expect(actual) |> toBe(expected);
    });
  });

  describe("part 2", () => {
    test("`0 3 0 1 -3` = 10 steps", () => {
      let input = "0\n3\n0\n1\n-3";
      let actual = Main.(solve(~input, addOneOrSubtractOne));
      let expected = 10;

      expect(actual) |> toBe(expected);
    });
  });
});
