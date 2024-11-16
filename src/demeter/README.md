# Source general spec

A good way to get early adopters might be to be a drop-in replacement for OpenMOC or OpenMC.
But we choose to design a simplified interface.

## Directory structure

vector-of-bool/pitchfork

demeter/
├── src/
│   ├── model/
│   │   ├── cell.hpp
│   │   ├── cell.cpp
│   │   ├── material.hpp
│   │   └── material.cpp
│   ├── model.hpp
│   └── solve/
│       ├── solver.hpp
│       └── solver.cpp
└── tests/
    ├── unit/
    ├── benchmark/
    └── regress/

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
