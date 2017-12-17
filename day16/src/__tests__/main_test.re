open Jest;

describe("day 16", () => {
  open Expect;

  let programs = [| 'a', 'b', 'c', 'd', 'e' |];

  describe("part 1", () => {
    test("after dance = `baedc`", () => {
      let input = "s1,x3/4,pe/b";
      let actual = Main.(solve(~input, ~programs, part1));
      let expected = "baedc";

      expect(actual) |> toBe(expected);
    });
  });

  describe("part 2", () => {
    test("after 2 dances = `ceadb`", () => {
      let input = "s1,x3/4,pe/b";
      let actual = Main.(solve(~input, ~programs, part2(~iterations = 1)));
      let expected = "ceadb";

      expect(actual) |> toBe(expected);
    });
  });
});
