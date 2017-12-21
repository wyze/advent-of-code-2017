open Jest;

describe("day 20", () => {
  open Expect;

  describe("part 1", () => {
    test("closest particle index", () => {
      let input = "p=<3,0,0>, v=<2,0,0>, a=<-1,0,0>\np=<4,0,0>, v=<0,0,0>, a=<-2,0,0>\np=<4,0,0>, v=<1,0,0>, a=<-1,0,0>\np=<2,0,0>, v=<-2,0,0>, a=<-2,0,0>\np=<4,0,0>, v=<0,0,0>, a=<-1,0,0>\np=<-2,0,0>, v=<-4,0,0>, a=<-2,0,0>\np=<3,0,0>, v=<-1,0,0>, a=<-1,0,0>\np=<-8,0,0>, v=<-6,0,0>, a=<-2,0,0>";
      let actual = Main.(solve(~input, part1));
      let expected = 0;

      expect(actual) |> toBe(expected);
    });
  });

  describe("part 2", () => {
    test("particles left after collision", () => {
      let input = "p=<3,0,0>, v=<2,0,0>, a=<-1,0,0>\np=<4,0,0>, v=<0,0,0>, a=<-2,0,0>\np=<4,0,0>, v=<1,0,0>, a=<-1,0,0>\np=<2,0,0>, v=<-2,0,0>, a=<-2,0,0>\np=<4,0,0>, v=<0,0,0>, a=<-1,0,0>\np=<-2,0,0>, v=<-4,0,0>, a=<-2,0,0>\np=<3,0,0>, v=<-1,0,0>, a=<-1,0,0>\np=<-8,0,0>, v=<-6,0,0>, a=<-2,0,0>";
      let actual = Main.(solve(~input, part2));
      let expected = 3;

      expect(actual) |> toBe(expected);
    });
  });
});
