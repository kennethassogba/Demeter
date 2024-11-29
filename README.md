# Demeter

Demeter<sup>1</sup> is a modern and open source deterministic neutron transport code for reactor simulations. The code is designed to perform 3D fixe source and eigenvalue calculations by solving the multi-group neutron transport equation.

The physics is coded in C++, with Python as user interface for easy and fast usage.

<sub>1. DEterMinistic nEutron Transport solvER</sub>

## Roadmap

### Core

- [x] Setup Cmake.
- [x] Add and test Eigen.
- [x] Setup directory structure.
- [x] Code and test Material class.
- [x] Collect source and compile.
- [x] Setup nanobind and write Python bindings for Material.
- [x] Write a python test for Material class.
- [x] Code and test Geometry class.
  - [x] Cell
  - [x] Lattice.
- [ ] Code Solver module.
  - [ ] Base solver
  - [ ] Mesh.
  - [ ] Boundary conditions.
- [ ] Test Geometry and solver in python.
  - [ ] Geometry bindings
  - [ ] Solver bindings
  - [ ] Test
- [ ] Write full benchmark
  - [ ] In C++.
  - [ ] In Python.
- [ ] Mesh refiner, rings and sectors for cell
- [ ] Enable users to test the lib with codespace and notebooks.
- [ ] GPU offload.

### Clean code, testing and safety

- [x] Add AddressSanitizer, ThreadSanitizer, MemorySanitizer.
- [x] Setup Github Action.
- [x] Improve Github Action, by fixing OpenMP not found and with recent version of compiler and Eigen.
- [x] Setup clang-format with Google style.
- [x] Setup clang-tidy.
- [x] Fix how to launch clang-tidy locally and on action.
- [x] Move bindings elsewhere
- [ ] Choose how to handle asserts: thow user errors at runtime and assert internal error on debug build
- [ ] Add a Logger (spdlog, or nanolog or fmtlog) and std::format.
- [ ] Add a timer.
- [ ] Use doctest for unit tests in c++ and python.
- [ ] Doc style (eg doxygen) and the way to generate it automatically.
- [ ] Maybe switch to include/demeter, src, src/binding, test, extra directory structure
- [ ] Add -Werror flag
- [ ] Setup gcc analizer.
- [ ] Generate .clagn-tidy with --warnings-as-errors=<string>
- [ ] Peform cland-tidy in github action.

## Requirements

- A C++ compiler compatible with at least version 17 of the standard, eg:
  - GCC 8 and later `apt install build-essential`,
  - Clang 8 and later `apt install clang libomp-dev clang-tidy clang-format`.
- CMake 3.4 and newer `apt install cmake`.
- Eigen 3.3 and newer `apt install libeigen3-dev`.
- Python 3.8 and newer `apt install libpython3-dev`

## Build Python package

```bash
cd <project-directory>
python -m venv pyenv
source pyenv/bin/activate
pip install numpy matplotlib
pip install .
```

Following this, you should be able to  access the extension

```bash
>>> from demeter import *
>>> help(Material)
```

## Build and Run

```bash
git clone --recursive https://github.com/kennethassogba/Demeter
mkdir build && cd build
cmake ..
make -j
```

Then try

```bash
./main
```

### Configure the build type: Debug or Release

```bash
cmake -S . -B build/ -D CMAKE_BUILD_TYPE=Debug
cmake --build build/ # build the binaries
```

### Choose a compiler

```bash
cmake -S . -B build/ -D CMAKE_CXX_COMPILER=clang++-18
```

### Append compiler flags

```bash
cmake -S . -B build/ -D CMAKE_CXX_FLAGS=-fsanitize=memory
```

## Troubleshooting

## Reference

## License
