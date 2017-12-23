open Jest;

describe("day 21", () => {
  open Expect;

  describe("part 1", () => {
    test("pixels on after 5 iterations = `150`", () => {
      let actual = Main.(solve(part1));
      let expected = 150;

      expect(actual) |> toBe(expected);
    });
  });

  describe("part 2", () => {
    test("pixels on after 18 iterations = `2606275`", () => {
      let actual = Main.(solve(part2));
      let expected = 2606275;

      expect(actual) |> toBe(expected);
    });
  });
});
