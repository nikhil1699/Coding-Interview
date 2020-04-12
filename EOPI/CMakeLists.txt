cmake_minimum_required(VERSION 3.16)
project(EOPI)

set(CMAKE_CXX_STANDARD 14)

add_library(EOPI library.cpp library.h Recursion/toweOfHanoi.cpp Recursion/nQueen.cpp Recursion/generatePermutations.cpp Recursion/generatePowerSet.cpp Recursion/generateSubsetsOfSizeK.cpp Recursion/stringsOfMatchingParenthesis.cpp Recursion/generatePallindromicDecompositions.cpp Recursion/generateBTrees.cpp Recursion/sudoKuSolver.cpp Recursion/diameterOfTree.cpp)
add_executable(toweOfHanoi Recursion/toweOfHanoi.cpp)