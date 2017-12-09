open Jest;

describe("day 8", () => {
  open Expect;

  describe("part 1", () => {
    test("largest register value = 1", () => {
      let input = "b inc 5 if a > 1\na inc 1 if b < 5\nc dec -10 if a >= 1\nc inc -20 if c == 10";
      let actual = Main.(solve(~input, largestEndingRegister));
      let expected = 1;

      expect(actual) |> toBe(expected);
    });
  });

  describe("part 2", () => {
    test("highest ever register value = 10", () => {
      let input = "b inc 5 if a > 1\na inc 1 if b < 5\nc dec -10 if a >= 1\nc inc -20 if c == 10";
      let actual = Main.(solve(~input, highestValuedRegister));
      let expected = 10;

      expect(actual) |> toBe(expected);
    });
  });
});
