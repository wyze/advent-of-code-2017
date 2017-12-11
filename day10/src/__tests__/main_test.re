open Jest;

describe("day 10", () => {
  open Expect;

  describe("part 1", () => {
    test("3, 4, 1, 5 = 2", () => {
      let input = "3,4,1,5";
      let actual = Main.(solve(~input, part1));
      let expected = 2;

      expect(actual) |> toBe(expected);
    });
  });

  describe("part 2", () => {
    test("`\"\"` = `a2582a3a0e66e6e86e3812dcb672a272`", () => {
      let input = "";
      let actual = Main.(solve(~input, part2));
      let expected = "a2582a3a0e66e6e86e3812dcb672a272";

      expect(actual) |> toBe(expected);
    });

    test("`AoC 2017` = `33efeb34ea91902bb2f59c9920caa6cd`", () => {
      let input = "AoC 2017";
      let actual = Main.(solve(~input, part2));
      let expected = "33efeb34ea91902bb2f59c9920caa6cd";

      expect(actual) |> toBe(expected);
    });

    test("`1,2,3` = `3efbe78a8d82f29979031a4aa0b16a9d`", () => {
      let input = "1,2,3";
      let actual = Main.(solve(~input, part2));
      let expected = "3efbe78a8d82f29979031a4aa0b16a9d";

      expect(actual) |> toBe(expected);
    });

    test("`1,2,4` = `63960835bcdc130f0b66d7ff4f6a5a8e`", () => {
      let input = "1,2,4";
      let actual = Main.(solve(~input, part2));
      let expected = "63960835bcdc130f0b66d7ff4f6a5a8e";

      expect(actual) |> toBe(expected);
    });
  });
});
