open Jest;

describe("day 24", () => {
  open Expect;

  describe("part 1", () => {
    test("strongest bridge = `31`", () => {
      let input = "0/2\n2/2\n2/3\n3/4\n3/5\n0/1\n10/1\n9/10";
      let actual = Main.(solve(~input, part1));
      let expected = 31;

      expect(actual) |> toBe(expected);
    });
  });

  describe("part 2", () => {
    test("strength of longest bridge = `19`", () => {
      let input = "0/2\n2/2\n2/3\n3/4\n3/5\n0/1\n10/1\n9/10";
      let actual = Main.(solve(~input, part2));
      let expected = 19;

      expect(actual) |> toBe(expected);
    });
  });
});
