# Demeter

Demeter<sup>1</sup> is a modern and open source deterministic neutron transport code for reactor simulations. The code is designed to perform 3D fixe source and eigenvalue calculations by solving the multi-group neutron transport equation.

The physics is coded in C++, with Python as user interface for easy and fast usage.

<sub>1. DEterMinistic nEutron Transport solvER</sub>

## Roadmap

### Core

- [x] Setup Cmake.
- [x] Add and test Eigen.
- [x] Setup directory structure vector-of-bool/pitchfork.
- [x] Code and test Material class.
- [x] Collect source and compile.
- [ ] Setup pybind11 and write a Python API.
- [ ] Write a python test for Material class.
- [ ] Code and test Geometry class.
  - [ ] Cell
  - [ ] PinCell
  - [ ] Lattice.
- [ ] Test Geometry in python.
- [ ] Code Solver class.
- [ ] Write full benchmark in C++.
- [ ] Write full benchmark in Python.
- [ ] Talk about doc style (eg doxygen) and the way to generate it automatically.
- [ ] Enable users to test the lib with codespace and notebooks.
- [ ] GPU offload.

### Clean code, testing and safety

- [x] Add AddressSanitizer, ThreadSanitizer, MemorySanitizer.
- [x] Setup Github Action.
- [x] Improve Github Action, by fixing OpenMP not found and with recent version of compiler and Eigen.
- [x] Setup clang-format with Google style.
- [x] Setup clang-tidy.
- [x] Fix how to launch clang-tidy locally and on action.
- [ ] Add a Logger (spdlog, or nanolog or fmtlog) and std::format.
- [ ] Use docstest unit tests.
- [ ] Maybe switch to include/demeter, src, src/binding, test, extra directory structure
- [ ] Add -Werror flag
- [ ] Setup gcc analizer.
- [ ] Generate .clagn-tidy with --warnings-as-errors=<string>
- [ ] Peform cland-tidy in github action.

## Requirements

- A C++ compiler compatible with at least version 17 of the standard, eg:
  - GCC 8 and later `apt install build-essential`,
  - Clang 8 and later `apt install clang libomp-dev clang-tidy clang-format`.
- CMake `apt install cmake`.
- Eigen `apt install libeigen3-dev`.

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
