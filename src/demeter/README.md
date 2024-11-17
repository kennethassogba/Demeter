# Source general spec

A good way to get early adopters might be to be a drop-in replacement for OpenMOC or OpenMC.
But we choose to design a simplified interface.

## Directory structure

Pitchfork Layout vector-of-bool/pitchfork

- [x] build/: Used for storing ephemeral build results. Must be ignored in .gitignore.

- [ ] src/: Main compilable source location. In the presence of include/, also contains private headers.

- [ ] include/: Directory for public headers. May be present. May be omitted for projects that do not distinguish between private/public headers. May be omitted for projects that use submodules.

- [x] tests/: Directory for tests.

- [x] examples/: Directory for samples and examples.

- [x] external/: Directory for packages/projects to be used by the project, but not edited as part of the project.

- [ ] data/: Directory containing non-source code aspects of the project.

- [ ] tools/: Directory containing development utilities, such as build and refactoring scripts

- [ ] docs/: Directory for project documentation.

## Material and Cross section

- Material : describe a material with its cross-sections
  - vec sigma_t total or transport cross-section
  - vec sigma_a absorption cross-section
  - mat sigma_s scattering cross-section
  - vec sigma_f fission cross-section
  - vec nu_sigma_f nu*fission
  - vec chi
  - bool fissible
  - str name (optional)

## Geometry

- Cell
- PinCell : cell with concentric annular regions
- Lattice : set or PinCell or set of Lattice
  - Mesh
  - Symetry
    - 1/2
    - 1/8
  - Boundary counditions
    - Vaccum
    - Reflexion

## Usage example

Na

## Solvers

Na
