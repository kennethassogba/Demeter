cmake_minimum_required(VERSION 3.4...3.31) # specifying a minimum CMake version
project(demeter) # set the project name

set(CMAKE_CXX_STANDARD 11) # specifying the C++ Standard
set(GCC_COVERAGE_COMPILE_FLAGS "-Wall -Wextra -pedantic") # flags for all build ? (to verify)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${GCC_COVERAGE_COMPILE_FLAGS}")

set(CMAKE_CXX_FLAGS_RELEASE "-O3 -march=native -funroll-loops -funroll-all-loops -DNDEBUG")
set(CMAKE_CXX_FLAGS_DEBUG "-g") # flagss for `cmake -DCMAKE_BUILD_TYPE=Debug ..`

# include_directories(include)

# OpenMP
find_package(OpenMP)
if(OpenMP_CXX_FOUND)
    set(LINK_LIBS ${LINK_LIBS} ${OpenMP_CXX_LIBRARIES})
endif()

# MPI
# find_package(MPI)
# set(LINK_LIBS ${LINK_LIBS} MPI::MPI_CXX)


# Executables

add_executable(main examples/main.cpp) # create an executable using the specified file
target_link_libraries(main PUBLIC ${LINK_LIBS})