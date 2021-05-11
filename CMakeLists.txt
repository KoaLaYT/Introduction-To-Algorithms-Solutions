cmake_minimum_required(VERSION 3.19)

# My vcpkg root dir
set(ENV{VCPKG_ROOT} "/Users/koalayt/Library")
set(CMAKE_TOOLCHAIN_FILE "$ENV{VCPKG_ROOT}/Vcpkg/scripts/buildsystems/vcpkg.cmake"
    CACHE STRING "")

project(Introduction-To-Algorithm-Solutions)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

find_package(GTest CONFIG REQUIRED)

add_subdirectory("01-The-Role-Of-Algorithms-In-Computing")
add_subdirectory("02-Getting-Started")