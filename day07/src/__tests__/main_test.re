open Jest;

describe("day 7", () => {
  open Expect;

  describe("part 1", () => {
    test("bottom program = `tknk`", () => {
      let input = "pbga (66)\nxhth (57)\nebii (61)\nhavc (66)\nktlj (57)\nfwft (72) -> ktlj, cntj, xhth\nqoyq (66)\npadx (45) -> pbga, havc, qoyq\ntknk (41) -> ugml, padx, fwft\njptl (61)\nugml (68) -> gyxo, ebii, jptl\ngyxo (61)\ncntj (57)";
      let actual = Main.(solve(~input, getRootName));
      let expected = "tknk";

      expect(actual) |> toBe(expected);
    });
  });

  describe("part 2", () => {
    test("unbalanced weight = 60", () => {
      let input = "pbga (66)\nxhth (57)\nebii (61)\nhavc (66)\nktlj (57)\nfwft (72) -> ktlj, cntj, xhth\nqoyq (66)\npadx (45) -> pbga, havc, qoyq\ntknk (41) -> ugml, padx, fwft\njptl (61)\nugml (68) -> gyxo, ebii, jptl\ngyxo (61)\ncntj (57)";
      let actual = Main.(solve(~input, getNeededWeight));
      let expected = 60;

      expect(actual) |> toBe(expected);
    });
  });
});
