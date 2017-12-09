open Jest;

describe("day 9", () => {
  open Expect;

  describe("part 1", () => {
    test("`{}` = score of 1", () => {
      let input = "{}";
      let actual = Main.(solve(~input, fst));
      let expected = 1;

      expect(actual) |> toBe(expected);
    });

    test("`{{{}}}` = score of 6", () => {
      let input = "{{{}}}";
      let actual = Main.(solve(~input, fst));
      let expected = 6;

      expect(actual) |> toBe(expected);
    });

    test("`{{},{}}` = score of 5", () => {
      let input = "{{},{}}";
      let actual = Main.(solve(~input, fst));
      let expected = 5;

      expect(actual) |> toBe(expected);
    });

    test("`{{{},{},{{}}}}` = score of 16", () => {
      let input = "{{{},{},{{}}}}";
      let actual = Main.(solve(~input, fst));
      let expected = 16;

      expect(actual) |> toBe(expected);
    });

    test("`{<a>,<a>,<a>,<a>}` = score of 1", () => {
      let input = "{<a>,<a>,<a>,<a>}";
      let actual = Main.(solve(~input, fst));
      let expected = 1;

      expect(actual) |> toBe(expected);
    });

    test("`{{<ab>},{<ab>},{<ab>},{<ab>}}` = score of 9", () => {
      let input = "{{<ab>},{<ab>},{<ab>},{<ab>}}";
      let actual = Main.(solve(~input, fst));
      let expected = 9;

      expect(actual) |> toBe(expected);
    });

    test("`{{<!!>},{<!!>},{<!!>},{<!!>}}` = score of 9", () => {
      let input = "{{<!!>},{<!!>},{<!!>},{<!!>}}";
      let actual = Main.(solve(~input, fst));
      let expected = 9;

      expect(actual) |> toBe(expected);
    });

    test("`{{<a!>},{<a!>},{<a!>},{<ab>}}` = score of 3", () => {
      let input = "{{<a!>},{<a!>},{<a!>},{<ab>}}";
      let actual = Main.(solve(~input, fst));
      let expected = 3;

      expect(actual) |> toBe(expected);
    });
  });

  describe("part 2", () => {
    test("`<>` = 0 characters", () => {
      let input = "<>";
      let actual = Main.(solve(~input, snd));
      let expected = 0;

      expect(actual) |> toBe(expected);
    });

    test("`<random characters>` = 17 characters", () => {
      let input = "<random characters>";
      let actual = Main.(solve(~input, snd));
      let expected = 17;

      expect(actual) |> toBe(expected);
    });

    test("`<<<<>` = 3 characters", () => {
      let input = "<<<<>";
      let actual = Main.(solve(~input, snd));
      let expected = 3;

      expect(actual) |> toBe(expected);
    });

    test("`<{!>}>` = 2 characters", () => {
      let input = "<{!>}>";
      let actual = Main.(solve(~input, snd));
      let expected = 2;

      expect(actual) |> toBe(expected);
    });

    test("`<!!>` = 0 characters", () => {
      let input = "<!!>";
      let actual = Main.(solve(~input, snd));
      let expected = 0;

      expect(actual) |> toBe(expected);
    });

    test("`<!!!>>` = 0 characters", () => {
      let input = "<!!!>>";
      let actual = Main.(solve(~input, snd));
      let expected = 0;

      expect(actual) |> toBe(expected);
    });

    test("`<{o\"i!a,<{i<a>` = 10 characters", () => {
      let input = "<{o\"i!a,<{i<a>";
      let actual = Main.(solve(~input, snd));
      let expected = 10;

      expect(actual) |> toBe(expected);
    });
  });
});
