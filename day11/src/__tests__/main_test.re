open Jest;

describe("day 11", () => {
  open Expect;

  describe("part 1", () => {
    test("`ne,ne,ne` = 3 steps", () => {
      let input = "ne,ne,ne";
      let actual = Main.(solve(~input, part1));
      let expected = 3;

      expect(actual) |> toBe(expected);
    });

    test("`ne,ne,sw,sw` = 0 steps", () => {
      let input = "ne,ne,sw,sw";
      let actual = Main.(solve(~input, part1));
      let expected = 0;

      expect(actual) |> toBe(expected);
    });

    test("`ne,ne,s,s` = 2 steps", () => {
      let input = "ne,ne,s,s";
      let actual = Main.(solve(~input, part1));
      let expected = 2;

      expect(actual) |> toBe(expected);
    });

    test("`se,sw,se,sw,sw` = 3 steps", () => {
      let input = "se,sw,se,sw,sw";
      let actual = Main.(solve(~input, part1));
      let expected = 3;

      expect(actual) |> toBe(expected);
    });
  });

  describe("part 2", () => {
    test("`ne,ne,ne` = max 3 steps", () => {
      let input = "ne,ne,ne";
      let actual = Main.(solve(~input, part2));
      let expected = 3;

      expect(actual) |> toBe(expected);
    });

    test("`ne,ne,sw,sw` = max 2 steps", () => {
      let input = "ne,ne,sw,sw";
      let actual = Main.(solve(~input, part2));
      let expected = 2;

      expect(actual) |> toBe(expected);
    });

    test("`ne,ne,s,s` = max 2 steps", () => {
      let input = "ne,ne,s,s";
      let actual = Main.(solve(~input, part2));
      let expected = 2;

      expect(actual) |> toBe(expected);
    });

    test("`se,sw,se,sw,sw` = max 3 steps", () => {
      let input = "se,sw,se,sw,sw";
      let actual = Main.(solve(~input, part2));
      let expected = 3;

      expect(actual) |> toBe(expected);
    });
  });
});
