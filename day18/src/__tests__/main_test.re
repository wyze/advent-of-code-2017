open Jest;

describe("day 18", () => {
  open Expect;

  describe("part 1", () => {
    test("last frequency played = 4", () => {
      let input = "set a 1\nadd a 2\nmul a a\nmod a 5\nsnd a\nset a 0\nrcv a\njgz a -1\nset a 1\njgz a -2";
      let actual = Main.(solve(~input, part1));
      let expected = 4;

      expect(actual) |> toBe(expected);
    });
  });

  describe("part 2", () => {
    test("program 1 sent count = 3", () => {
      let input = "snd 1\nsnd 2\nsnd p\nrcv a\nrcv b\nrcv c\nrcv d";
      let actual = Main.(solve(~input, part2));
      let expected = 3;

      expect(actual) |> toBe(expected);
    });
  });
});
