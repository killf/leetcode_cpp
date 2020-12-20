cmake_minimum_required(VERSION 3.14)
project(leetcode)

set(CMAKE_CXX_STANDARD 20)

include_directories(common)

file(GLOB_RECURSE FILES "src/*.cpp")
foreach (src ${FILES})
    STRING(REGEX REPLACE ".+/(.+)\\..*" "\\1" name ${src})
    add_executable(${name} ${src})
endforeach ()