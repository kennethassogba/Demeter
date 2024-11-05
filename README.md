# Demeter

Demeter<sup>1</sup> is a modern and open source deterministic neutron transport code for reactor simulations. The code is designed to perform 3D fixe source and eigenvalue calculations by solving the multi-group neutron transport equation.

Numerically, the physics part is coded in C++ with Python as a user interface for easy and fast utilisations. Cmake is used to build configurations. 

<sub>1. DEterMinistic nEutron Transport solvER</sub>

## Roadmap

- [x] Run a simple main.cpp.
- [x] Setup Cmake (overkill for now but usefull in the future).
- [ ] Choose a code style (Google style eg) and setup a linter.
- [ ] Setup directory structure.
- [ ] Write a first real but simple code.
- [ ] Talk about doc style (eg doc string) and the way to generate it automatically.
- [ ] Talk about tests (use eg catch or gtest).
- [ ] Setup Github Action.
- [ ] Design a logo.
- [ ] Add with [AddressSanitizer](https://clang.llvm.org/docs/AddressSanitizer.html), MemorySanitizer, LeakSanitizer, ....

## Build and Run

```bash
mkdir build && cd build
cmake ..
make -j
```

or

```bash
cmake -B build
cmake --build build
```

Then try

```bash
./main
```

### Debug or Release build
- Configure a debug build
`cmake -S . -B build/ -D CMAKE_BUILD_TYPE=Debug`
- Actually build the binaries
`cmake --build build/`

- Configure a release build
`cmake -S . -B build/ -D CMAKE_BUILD_TYPE=Release`
- Build release binaries
`cmake --build build/`

## Dependencies

## Troubleshooting

## Reference

## License
