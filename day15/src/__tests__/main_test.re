open Jest;

describe("day 15", () => {
  open Expect;

  describe("part 1", () => {
    test("judges final count = 588", () => {
      let input = "Generator A starts with 65\nGenerator B starts with 8921";
      let actual = Main.(solve(~input, part1));
      let expected = 588;

      expect(actual) |> toBe(expected);
    });
  });

  describe("part 2", () => {
    test("judges final count = 309", () => {
      let input = "Generator A starts with 65\nGenerator B starts with 8921";
      let actual = Main.(solve(~input, part2));
      let expected = 309;

      expect(actual) |> toBe(expected);
    });
  });
});
