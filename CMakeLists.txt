cmake_minimum_required (VERSION 2.8)
project (Filters)

set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fPIC -std=c++1y")
set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Werror -Wnon-virtual-dtor -Wno-unused-variable -g")
set (CMAKE_XCODE_ATTRIBUTE_CLANG_CXX_LANGUAGE_STANDARD "c++0x")
set (CMAKE_XCODE_ATTRIBUTE_CLANG_CXX_LIBRARY "libc++")

#version number
set (Filters_VERSION_MAJOR 1)
set (Filters_VERSION_MINOR 0)

# configure a header file to pass some of the CMake settings
# to the source code
configure_file (
  "${PROJECT_SOURCE_DIR}/src/Config.h.in"
  "${PROJECT_BINARY_DIR}/Config.h"
  )


# source and includes
include_directories (${PROJECT_SOURCE_DIR}/src)
add_subdirectory (src)


#indicate the entry point for the executable
add_executable (Filters Filters src/main.cpp)

SET(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/CMakeModules)
set (EXTRA_LIBS ${EXTRA_LIBS} filters)

# V8
find_package(V8 REQUIRED)
set (EXTRA_LIBS ${EXTRA_LIBS} ${V8_LIBRARY})

# External projects
add_subdirectory (ext)
#include_directories (${PROJECT_BINARY_DIR}/ext/include)
#link_directories (${PROJECT_BINARY_DIR}/ext/lib)

# Find system LOG4CXX
find_package(PkgConfig)
pkg_check_modules(FILTERS_SYSTEM REQUIRED liblog4cxx)
include_directories(${FILTERS_SYSTEM_INCLUDE_DIRS})
link_directories(${FILTERS_SYSTEM_LIBRARY_DIRS})

# gtest include and link directories
externalproject_get_property (gtest-1.7.0 source_dir)
externalproject_get_property (gtest-1.7.0 binary_dir)
include_directories (${source_dir}/include)
link_directories (${binary_dir})

# gmock include and link directories
externalproject_get_property (gmock-1.7.0 source_dir)
externalproject_get_property (gmock-1.7.0 binary_dir)
include_directories (${source_dir}/include)
link_directories (${binary_dir})

target_link_libraries (Filters ${EXTRA_LIBS})
install (TARGETS Filters DESTINATION bin)


# Test
#include_directories(ext/gmock/include)
#add_subdirectory(ext/gmock)

enable_testing(true)
add_subdirectory(test)

# Add custom targets for tools

add_custom_target (cpplint
  COMMAND find src \\\( -iname "*.cpp" -o -iname "*.hpp" \\\) ! -iname "*cmake*" | xargs python tools/cpplint.py --linelength=120
  WORKING_DIRECTORY ${PROJECT_SOURCE_DIR}
  COMMENT "Running cpplint")

add_custom_target (cppcheck
  COMMAND cppcheck src
  WORKING_DIRECTORY ${PROJECT_SOURCE_DIR}
  COMMENT "Running cppcheck")
