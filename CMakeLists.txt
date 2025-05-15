cmake_minimum_required(VERSION 3.4...3.31)
project(demeter)

set(CMAKE_CXX_STANDARD 23)
# set(GCC_COVERAGE_COMPILE_FLAGS "-Wall -Wextra -pedantic")
# set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${GCC_COVERAGE_COMPILE_FLAGS}")

set(CMAKE_CXX_FLAGS_RELEASE "-O3 -ftree-vectorize -march=native -mtune=native -DNDEBUG")
set(CMAKE_CXX_FLAGS_DEBUG "-g -fsanitize=address,undefined")
# -fsanitize=thread is incompatible with -fsanitize=address
# -fsanitize=memory also
# -fanalizer is available for gcc

if (NOT CMAKE_BUILD_TYPE AND NOT CMAKE_CONFIGURATION_TYPES)
  set(CMAKE_BUILD_TYPE Release CACHE STRING "Choose the type of build." FORCE)
  set_property(CACHE CMAKE_BUILD_TYPE PROPERTY STRINGS "Debug" "Release" "MinSizeRel" "RelWithDebInfo")
endif()

include_directories(src)

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
cmake_print_variables(PROJECT_SOURCE_DIR CMAKE_BUILD_TYPE CMAKE_CURRENT_SOURCE_DIR)
cmake_print_variables(CMAKE_CXX_COMPILER CMAKE_CXX_COMPILER_ID CMAKE_CXX_COMPILER_VERSION)
cmake_print_variables(CMAKE_CXX_FLAGS COMPILE_DEFINITIONS)
cmake_print_variables(LINK_LIBS)
cmake_print_variables(CMAKE_CXX_COMPILER_RANLIB)
cmake_print_variables(OpenMP_CXX_FOUND OpenMP_CXX_FLAGS OpenMP_CXX_INCLUDE_DIRS)
cmake_print_variables(OpenMP::OpenMP_CXX OpenMP_CXX_VERSION)

# Include custom cmake rules
include(cmake/clang-cxx-dev-tools.cmake) # make clang-format and make clang-tidy

# Compile Demeter library
file(GLOB_RECURSE DEM_SOURCES src/demeter/*.cpp)
add_library(demeter ${DEM_SOURCES})
target_compile_options(demeter INTERFACE -Wall -Wextra -Wconversion
  -Wshadow -Wnon-virtual-dtor -Wold-style-cast
  -Woverloaded-virtual -Wzero-as-null-pointer-constant
  -pedantic -Werror)
target_link_libraries(demeter PUBLIC ${LINK_LIBS})
set_target_properties(demeter PROPERTIES POSITION_INDEPENDENT_CODE ON)

# Add demeter to LINK_LIBS
set(LINK_LIBS ${LINK_LIBS} demeter)

# Examples
add_subdirectory(examples)

# Tests
# enable_testing()
# add_subdirectory(tests) # add the tests subdirectory