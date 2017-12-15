open Jest;

describe("day 14", () => {
  open Expect;

  describe("part 1", () => {
    test("`flqrgnkx` = 8108 squares", () => {
      let input = "flqrgnkx";
      let actual = Main.(solve(~input, part1));
      let expected = 8108;

      expect(actual) |> toBe(expected);
    });
  });

  describe("part 2", () => {
    test("`flqrgnkx` = 1242 regions", () => {
      let input = "flqrgnkx";
      let actual = Main.(solve(~input, part2));
      let expected = 1242;

      expect(actual) |> toBe(expected);
    });
  });
});
