open Jest;

describe("day 12", () => {
  open Expect;

  describe("part 1", () => {
    test("constains Program ID 0 = 6 programs", () => {
      let input = "0 <-> 2\n1 <-> 1\n2 <-> 0, 3, 4\n3 <-> 2, 4\n4 <-> 2, 3, 6\n5 <-> 6\n6 <-> 4, 5";
      let actual = Main.(solve(~input, part1));
      let expected = 6;

      expect(actual) |> toBe(expected);
    });
  });

  describe("part 2", () => {
    test("2 total groups", () => {
      let input = "0 <-> 2\n1 <-> 1\n2 <-> 0, 3, 4\n3 <-> 2, 4\n4 <-> 2, 3, 6\n5 <-> 6\n6 <-> 4, 5";
      let actual = Main.(solve(~input, part2));
      let expected = 2;

      expect(actual) |> toBe(expected);
    });
  });
});
