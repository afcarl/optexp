cmake_minimum_required(VERSION 2.8)
project(expdesign)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -O3 -g")
# set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fopenmp")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pedantic -Wall -Wextra -Werror -Wfatal-errors")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wno-unused -Wno-unused-parameter -Wno-unknown-pragmas")

INCLUDE_DIRECTORIES ( "src" "extern/eigen3" )

set(EXPDESIGN_SOURCES
    src/RandomGenerator.cpp
    src/MultivariateNormal.cpp
    src/MultivariateT.cpp
    src/Utilities.cpp
    src/ExpectedInformationEstimator.cpp
    src/LinearGaussianExperiment.cpp)

add_executable(Example-1 src/Example-1.cpp ${EXPDESIGN_SOURCES})
add_executable(Example-2 src/Example-2.cpp ${EXPDESIGN_SOURCES})
