open Jest;

describe("day 13", () => {
  open Expect;

  describe("part 1", () => {
    test("severity of trip = 24", () => {
      let input = "0: 3\n1: 2\n4: 4\n6: 4";
      let actual = Main.(solve(~input, part1));
      let expected = 24;

      expect(actual) |> toBe(expected);
    });
  });

  describe("part 2", () => {
    test("fewest number of picoseconds delayed = 10", () => {
      let input = "0: 3\n1: 2\n4: 4\n6: 4";
      let actual = Main.(solve(~input, part2));
      let expected = 10;

      expect(actual) |> toBe(expected);
    });
  });
});
