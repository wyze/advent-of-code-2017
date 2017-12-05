open Jest;

describe("day 4", () => {
  open Expect;

  describe("part 1", () => {
    test("`aa bb cc dd ee` is valid", () => {
      let input = "aa bb cc dd ee";
      let actual = Main.(solve(~input, ()));
      let expected = 1;

      expect(actual) |> toBe(expected);
    });

    test("`aa bb cc dd aa` is not valid", () => {
      let input = "aa bb cc dd aa";
      let actual = Main.(solve(~input, ()));
      let expected = 0;

      expect(actual) |> toBe(expected);
    });

    test("`aa bb cc dd aaa` is valid", () => {
      let input = "aa bb cc dd aaa";
      let actual = Main.(solve(~input, ()));
      let expected = 1;

      expect(actual) |> toBe(expected);
    });
  });

  describe("part 2", () => {
    test("`abcde fghij` is valid", () => {
      let input = "abcde fghij";
      let actual = Main.(solve(~input, ~mapWordsBy = sortWords, ()));
      let expected = 1;

      expect(actual) |> toBe(expected);
    });

    test("`abcde xyz ecdab` is not valid", () => {
      let input = "abcde xyz ecdab";
      let actual = Main.(solve(~input, ~mapWordsBy = sortWords, ()));
      let expected = 0;

      expect(actual) |> toBe(expected);
    });

    test("`a ab abc abd abf abj` is valid", () => {
      let input = "a ab abc abd abf abj";
      let actual = Main.(solve(~input, ~mapWordsBy = sortWords, ()));
      let expected = 1;

      expect(actual) |> toBe(expected);
    });

    test("`iiii oiii ooii oooi oooo` is valid", () => {
      let input = "iiii oiii ooii oooi oooo";
      let actual = Main.(solve(~input, ~mapWordsBy = sortWords, ()));
      let expected = 1;

      expect(actual) |> toBe(expected);
    });

    test("`oiii ioii iioi iiio` is not valid", () => {
      let input = "oiii ioii iioi iiio";
      let actual = Main.(solve(~input, ~mapWordsBy = sortWords, ()));
      let expected = 0;

      expect(actual) |> toBe(expected);
    });
  });
});
