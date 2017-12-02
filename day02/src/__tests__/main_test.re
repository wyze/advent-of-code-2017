open Jest;

describe("day 2", () => {
  open Expect;

  describe("part 1", () => {
    test("checksum = 18", () => {
      let input = "5	1	9	5\n7	5	3\n2	4	6	8";
      let actual = Main.(getOutput(~input, diff));
      let expected = 18;

      expect(actual) |> toBe(expected);
    });
  });

  describe("part 2", () => {
    test("sum = 9", () => {
      let input = "5	9	2	8\n9	4	7	3\n3	8	6	5";
      let actual = Main.(getOutput(~input, divisible));
      let expected = 9;

      expect(actual) |> toBe(expected);
    });
  });
});
