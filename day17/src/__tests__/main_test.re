open Jest;

describe("day 17", () => {
  open Expect;

  describe("part 1", () => {
    test("value after 2017 = 638", () => {
      let input = 3;
      let actual = Main.(solve(~input, part1));
      let expected = 638;

      expect(actual) |> toBe(expected);
    });
  });

  describe("part 2", () => {
    test("value after 0 = 1222153", () => {
      let input = 3;
      let actual = Main.(solve(~input, part2));
      let expected = 1222153;

      expect(actual) |> toBe(expected);
    });
  });
});
