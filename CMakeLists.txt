cmake_minimum_required(VERSION 3.6)
project(ModernCppChallenge LANGUAGES CXX)

set(CMAKE_STANDARD 11)
set(CMAKE_STANDARD_REQUIRED ON)

# set boost directory from CLI:
# cmake -D BOOST_DIR=/path/to/boost/dir .
set(BOOST_DIR "" CACHE FILEPATH "Path to boost")

include_directories(${BOOST_DIR})
include_directories(${PROJECT_SOURCE_DIR}/StringsAndRegex)

add_executable(test test.cpp ${PROJECT_SOURCE_DIR}/StringsAndRegex/license_plates.cpp)