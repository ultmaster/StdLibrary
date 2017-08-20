cmake_minimum_required(VERSION 3.6)
project(Stdtest)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -DULTMASTER")

set(SOURCE_FILES test/main.cpp)
add_executable(Test ${SOURCE_FILES})
