open Jest;

describe("day 23", () => {
  open Expect;

  describe("part 1", () => {
    test("number of times `mul` was invoked = `3025`", () => {
      let actual = Main.(solve(part1));
      let expected = 3025;

      expect(actual) |> toBe(expected);
    });
  });

  describe("part 2", () => {
    test("value of register `h` = `915`", () => {
      let actual = Main.(solve(part2));
      let expected = 915;

      expect(actual) |> toBe(expected);
    });
  });
});
