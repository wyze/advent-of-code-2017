open Jest;

describe("day 1", () => {
  open Expect;

  describe("part 1", () => {
    let getModifier = (_) => 1;

    test("1122 = 3", () => {
      let actual = Main.getOutput(~input = "1122", getModifier);
      let expected = 3;

      expect(actual) |> toBe(expected);
    });

    test("1111 = 4", () => {
      let actual = Main.getOutput(~input = "1111", getModifier);
      let expected = 4;

      expect(actual) |> toBe(expected);
    });

    test("1234 = 0", () => {
      let actual = Main.getOutput(~input = "1234", getModifier);
      let expected = 0;

      expect(actual) |> toBe(expected);
    });

    test("91212129 = 9", () => {
      let actual = Main.getOutput(~input = "91212129", getModifier);
      let expected = 9;

      expect(actual) |> toBe(expected);
    });
  });

  describe("part 2", () => {
    let getModifier = s => String.length(s) / 2;

    test("1212 = 6", () => {
      let actual = Main.getOutput(~input = "1212", getModifier);
      let expected = 6;

      expect(actual) |> toBe(expected);
    });

    test("1221 = 0", () => {
      let actual = Main.getOutput(~input = "1221", getModifier);
      let expected = 0;

      expect(actual) |> toBe(expected);
    });

    test("123425 = 4", () => {
      let actual = Main.getOutput(~input = "123425", getModifier);
      let expected = 4;

      expect(actual) |> toBe(expected);
    });

    test("123123 = 12", () => {
      let actual = Main.getOutput(~input = "123123", getModifier);
      let expected = 12;

      expect(actual) |> toBe(expected);
    });

    test("12131415 = 4", () => {
      let actual = Main.getOutput(~input = "12131415", getModifier);
      let expected = 4;

      expect(actual) |> toBe(expected);
    });
  });
});
