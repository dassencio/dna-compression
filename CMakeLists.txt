cmake_minimum_required(VERSION 2.8.7)

project(dna)

add_executable(dna dna.cpp)

# activate C++11 and all warnings
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -Wall -Wextra -Werror")
