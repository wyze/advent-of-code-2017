type coord = {
  x: int,
  y: int,
  z: int,
};

type particle = {
  acceleration: coord,
  index: int,
  position: coord,
  velocity: coord,
};

let (+=) = ( coord1, coord2 ) => {
  x: coord1.x + coord2.x,
  y: coord1.y + coord2.y,
  z: coord1.z + coord2.z,
};

let tick = particle => {
  let velocity = particle.velocity += particle.acceleration;

  { ...particle, position: particle.position += velocity, velocity };
};

let distance = ({ position: { x, y, z } }) => abs(x) + abs(y) + abs(z);

let rec removeCollisions = particles =>
  switch particles {
    | [] => []
    | [ particle, ...rest ] => {
      let filtered = List.filter(({ position }) => position != particle.position, rest);

      switch ( List.(length(rest) == length(filtered)) ) {
        | true => [ particle, ...removeCollisions(rest) ]
        | false => removeCollisions(filtered)
      }
    }
  };

let part1 = input => {
  let rec simulate = ( count, particles ) =>
    switch count {
      | 0 => {
        let sorted = List.sort(( part1, part2 ) => distance(part1) - distance(part2), particles);

        switch sorted {
          | [ particle, ..._ ] => particle.index
          | _ => raise(Failure("Invalid sorted list"))
        };
      }
      | _ => simulate(count - 1, List.map(tick, particles))
    };

  simulate(10000, input);
};

let part2 = input => {
  let rec simulate = ( count, particles ) =>
    switch count {
      | 0 => List.length(particles)
      | _ => simulate(count - 1, List.map(tick, particles |> removeCollisions))
    };

  simulate(100, input);
};

let stringToParticle = ( index, line ) =>
  Scanf.sscanf(
    line,
    "p=<%d,%d,%d>, v=<%d,%d,%d>, a=<%d,%d,%d>",
    ( px, py, pz, vx, vy, vz, ax, ay, az ) => {
      acceleration: { x: ax, y: ay, z: az },
      index,
      position: { x: px, y: py, z: pz },
      velocity: { x: vx, y: vy, z: vz },
    }
  );

let parse = input =>
  input
    |> Js.String.split("\n")
    |> Array.mapi(stringToParticle)
    |> Array.to_list;

let solve = ( ~input = Input.input, solver ) =>
  input
    |> parse
    |> solver;

Js.log2("Day 20, Part 1:", solve(part1));
Js.log2("Day 20, Part 2:", solve(part2));
