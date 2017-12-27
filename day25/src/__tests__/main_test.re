open Jest;

describe("day 25", () => {
  open Expect;

  describe("part 1", () => {
    test("diagnostic checksum after 10 iterations = `5`", () => {
      let actual = Main.(solve(~iterations = 10, part1));
      let expected = 5;

      expect(actual) |> toBe(expected);
    });
  });
});
