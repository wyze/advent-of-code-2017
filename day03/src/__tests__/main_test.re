open Jest;

describe("day 3", () => {
  open Expect;

  describe("part 1", () => {
    test("square 1 = 0 steps", () => {
      let input = 1;
      let actual = Main.(getOutput(~input, numberOfSteps));
      let expected = 0;

      expect(actual) |> toBe(expected);
    });

    test("square 12 = 3 steps", () => {
      let input = 12;
      let actual = Main.(getOutput(~input, numberOfSteps));
      let expected = 3;

      expect(actual) |> toBe(expected);
    });

    test("square 23 = 2 steps", () => {
      let input = 23;
      let actual = Main.(getOutput(~input, numberOfSteps));
      let expected = 2;

      expect(actual) |> toBe(expected);
    });

    test("square 1024 = 31 steps", () => {
      let input = 1024;
      let actual = Main.(getOutput(~input, numberOfSteps));
      let expected = 31;

      expect(actual) |> toBe(expected);
    });
  });

  describe("part 2", () => {
    test("input 1 = 2", () => {
      let input = 1;
      let actual = Main.(getOutput(~input, nextLargerValue));
      let expected = 2;

      expect(actual) |> toBe(expected);
    });

    test("input 2 = 4", () => {
      let input = 2;
      let actual = Main.(getOutput(~input, nextLargerValue));
      let expected = 4;

      expect(actual) |> toBe(expected);
    });

    test("input 3 = 4", () => {
      let input = 3;
      let actual = Main.(getOutput(~input, nextLargerValue));
      let expected = 4;

      expect(actual) |> toBe(expected);
    });

    test("input 4 = 5", () => {
      let input = 4;
      let actual = Main.(getOutput(~input, nextLargerValue));
      let expected = 5;

      expect(actual) |> toBe(expected);
    });

    test("input 5 = 10", () => {
      let input = 5;
      let actual = Main.(getOutput(~input, nextLargerValue));
      let expected = 10;

      expect(actual) |> toBe(expected);
    });
  });
});
