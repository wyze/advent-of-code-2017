open Jest;

describe("day 6", () => {
  open Expect;

  describe("part 1", () => {
    test("`0 2 7 0` = 5 cycles", () => {
      let input = "0\t2\t7\t0";
      let actual = Main.solve(~input, false);
      let expected = 5;

      expect(actual) |> toBe(expected);
    });
  });

  describe("part 2", () => {
    test("`0 2 7 0` = 4 cycles", () => {
      let input = "0\t2\t7\t0";
      let actual = Main.solve(~input, true);
      let expected = 4;

      expect(actual) |> toBe(expected);
    });
  });
});
