open Jest;

describe("day 22", () => {
  open Expect;

  describe("part 1", () => {
    test("`5538` nodes become infected", () => {
      let actual = Main.(solve(part1));
      let expected = 5538;

      expect(actual) |> toBe(expected);
    });
  });

  describe("part 2", () => {
    test("`2511090` nodes become infected", () => {
      let actual = Main.(solve(part2));
      let expected = 2511090;

      expect(actual) |> toBe(expected);
    });
  });
});
