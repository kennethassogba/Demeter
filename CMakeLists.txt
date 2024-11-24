cmake_minimum_required(VERSION 3.4...3.31) # specifying a minimum CMake version
project(demeter) # set the project name

set(CMAKE_CXX_STANDARD 17) # specifying the C++ Standard
# set(GCC_COVERAGE_COMPILE_FLAGS "-Wall -Wextra -pedantic")
# set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${GCC_COVERAGE_COMPILE_FLAGS}")

set(CMAKE_CXX_FLAGS_RELEASE "-O3 -march=native -DNDEBUG")
set(CMAKE_CXX_FLAGS_DEBUG "-g -fsanitize=address,undefined")
# -fsanitize=thread is incompatible with -fsanitize=address
# -fsanitize=memory also
# -fanalizer is also available for gcc
# -funroll-loops Premature optimization is the root of all evil
# -funroll-all-loops is not supported by Clang

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

# Python >= 3.8 and Development.Module
if (CMAKE_VERSION VERSION_LESS 3.18)
  set(DEV_MODULE Development)
else()
  set(DEV_MODULE Development.Module)
endif()

find_package(Python 3.8
  REQUIRED COMPONENTS Interpreter ${DEV_MODULE}
  OPTIONAL_COMPONENTS Development.SABIModule)
include_directories(${Python_INCLUDE_DIRS})

# nanobind
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/external/nanobind)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/external/nanobind/include)

# Verbose
include(CMakePrintHelpers)
cmake_print_variables(PROJECT_SOURCE_DIR CMAKE_BUILD_TYPE CMAKE_CURRENT_SOURCE_DIR)
cmake_print_variables(CMAKE_CXX_COMPILER CMAKE_CXX_COMPILER_ID CMAKE_CXX_COMPILER_VERSION)
cmake_print_variables(CMAKE_CXX_FLAGS COMPILE_DEFINITIONS)
cmake_print_variables(LINK_LIBS)
cmake_print_variables(CMAKE_CXX_COMPILER_RANLIB)
cmake_print_variables(OpenMP_CXX_FOUND OpenMP_CXX_FLAGS OpenMP_CXX_INCLUDE_DIRS)
cmake_print_variables(OpenMP::OpenMP_CXX OpenMP_CXX_VERSION)
cmake_print_variables(PYTHON_INCLUDE_DIRS Python_INCLUDE_DIRS Python_LIBRARY_DIRS)


# Including custom cmake rules
include(cmake/clang-cxx-dev-tools.cmake) # make clang-format and make clang-tidy

# Compile Demeter sources as a library
file(GLOB_RECURSE DEM_SOURCES src/demeter/*.cpp)
add_library(demeter ${DEM_SOURCES})
target_compile_options(demeter PRIVATE -Wall -Wextra -Wconversion -pedantic)
target_link_libraries(demeter PUBLIC ${LINK_LIBS})
set_target_properties(demeter PROPERTIES POSITION_INDEPENDENT_CODE ON)

# Add demeter to LINK_LIBS
set(LINK_LIBS ${LINK_LIBS} demeter)

# nanobind extension
# Compile extension module with size optimization and add demeter library
nanobind_add_module(_demeter # Name of the extension
                    STABLE_ABI  # Target the stable ABI for Python 3.12+
                    NB_DOMAIN demeter
                    # Extension source code
                    src/demeter/model/material.bind.cpp)
target_link_libraries(_demeter PRIVATE demeter)

# Executables
add_executable(main examples/main.cpp) # create an executable using the specified file
target_link_libraries(main PRIVATE ${LINK_LIBS})
target_compile_options(main PRIVATE -Wall -Wextra -Wconversion -pedantic)

# Install directive for scikit-build-core
if (SKBUILD)
  install(TARGETS _demeter LIBRARY DESTINATION ${SKBUILD_PROJECT_NAME})
  # install(TARGETS _demeter LIBRARY DESTINATION demeterpy)
endif()

# Tests
# enable_testing()
# add_subdirectory(tests) # add the tests subdirectory