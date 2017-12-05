open Jest;

describe("day 1", () => {
  open Expect;

  describe("part 1", () => {
    test("1122 = 3", () => {
      let actual = Main.solve(~input = "1122", ());
      let expected = 3;

      expect(actual) |> toBe(expected);
    });

    test("1111 = 4", () => {
      let actual = Main.solve(~input = "1111", ());
      let expected = 4;

      expect(actual) |> toBe(expected);
    });

    test("1234 = 0", () => {
      let actual = Main.solve(~input = "1234", ());
      let expected = 0;

      expect(actual) |> toBe(expected);
    });

    test("91212129 = 9", () => {
      let actual = Main.solve(~input = "91212129", ());
      let expected = 9;

      expect(actual) |> toBe(expected);
    });
  });

  describe("part 2", () => {
    test("1212 = 6", () => {
      let actual = Main.(solve(~input = "1212", ~getInputModifier = halfOfString, ()));
      let expected = 6;

      expect(actual) |> toBe(expected);
    });

    test("1221 = 0", () => {
      let actual = Main.(solve(~input = "1221", ~getInputModifier = halfOfString, ()));
      let expected = 0;

      expect(actual) |> toBe(expected);
    });

    test("123425 = 4", () => {
      let actual = Main.(solve(~input = "123425", ~getInputModifier = halfOfString, ()));
      let expected = 4;

      expect(actual) |> toBe(expected);
    });

    test("123123 = 12", () => {
      let actual = Main.(solve(~input = "123123", ~getInputModifier = halfOfString, ()));
      let expected = 12;

      expect(actual) |> toBe(expected);
    });

    test("12131415 = 4", () => {
      let actual = Main.(solve(~input = "12131415", ~getInputModifier = halfOfString, ()));
      let expected = 4;

      expect(actual) |> toBe(expected);
    });
  });
});
