cmake_minimum_required(VERSION 3.4...3.31) # specifying a minimum CMake version
project(demeter) # set the project name

set(CMAKE_CXX_STANDARD 14) # specifying the C++ Standard
set(GCC_COVERAGE_COMPILE_FLAGS "-Wall -Wextra -pedantic") # probably not the best variable name
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${GCC_COVERAGE_COMPILE_FLAGS}")

set(CMAKE_CXX_FLAGS_RELEASE "-O3 -march=native -DNDEBUG")
set(CMAKE_CXX_FLAGS_DEBUG "-g -fsanitize=address,undefined")

# Eigen
find_package(Eigen3 3.3 REQUIRED NO_MODULE)
set(LINK_LIBS ${LINK_LIBS} Eigen3::Eigen)

# Executables
add_executable(main examples/main.cpp) # create an executable using the specified file
target_link_libraries(main PUBLIC ${LINK_LIBS})

add_executable(matrix_eigen examples/matrix_eigen.cpp) # create an executable using the specified file
target_link_libraries(matrix_eigen PUBLIC ${LINK_LIBS})

find_package(OpenMP)
add_executable(loop_omp examples/loop_omp.cpp) # create an executable using the specified file
target_compile_options(loop_omp PRIVATE ${OpenMP_CXX_FLAGS})
target_link_libraries(loop_omp PUBLIC ${LINK_LIBS} OpenMP::OpenMP_CXX)
