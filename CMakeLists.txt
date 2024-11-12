cmake_minimum_required(VERSION 3.4...3.31) # specifying a minimum CMake version
project(demeter) # set the project name

set(CMAKE_CXX_STANDARD 14) # specifying the C++ Standard
set(GCC_COVERAGE_COMPILE_FLAGS "-Wall -Wextra -pedantic")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${GCC_COVERAGE_COMPILE_FLAGS}")
# add_compile_options(-Wall -Wextra -pedantic)

set(CMAKE_CXX_FLAGS_RELEASE "-O3 -march=native -funroll-loops -funroll-all-loops -DNDEBUG")
set(CMAKE_CXX_FLAGS_DEBUG "-g -fsanitize=address,undefined")

# include_directories(include)

# OpenMP
find_package(OpenMP)
if(OpenMP_CXX_FOUND)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${OpenMP_CXX_FLAGS}")
    set(LINK_LIBS ${LINK_LIBS} ${OpenMP_CXX_LIBRARIES})
endif()

# Eigen
find_package(Eigen3 3.3 REQUIRED NO_MODULE)
set(LINK_LIBS ${LINK_LIBS} Eigen3::Eigen)

# Verbose
include(CMakePrintHelpers)
cmake_print_variables(PROJECT_SOURCE_DIR CMAKE_BUILD_TYPE)
cmake_print_variables(CMAKE_CXX_COMPILER CMAKE_CXX_COMPILER_ID CMAKE_CXX_COMPILER_VERSION)
cmake_print_variables(CMAKE_CXX_FLAGS COMPILE_DEFINITIONS)
cmake_print_variables(CMAKE_CXX_COMPILER_RANLIB)
cmake_print_variables(OpenMP_CXX_FOUND OpenMP_CXX_FLAGS OpenMP_CXX_INCLUDE_DIRS)
cmake_print_variables(OpenMP::OpenMP_CXX OpenMP_CXX_VERSION)

# Including custom cmake rules
include(cmake/clang-cxx-dev-tools.cmake) # make clang-format and make clang-tidy

# Executables
add_executable(main examples/main.cpp) # create an executable using the specified file
target_link_libraries(main PUBLIC ${LINK_LIBS})

add_executable(simple examples/simple.cpp) # create an executable using the specified file
target_link_libraries(simple PUBLIC ${LINK_LIBS})

add_executable(test_omp examples/test_omp.cpp) # create an executable using the specified file
target_link_libraries(test_omp PUBLIC ${LINK_LIBS})