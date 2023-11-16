cmake_minimum_required(VERSION 3.1)

#set the project name
project ("stlvectortest")

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

include_directories(../../include)

# add the executables
add_executable (stlvectortest "stlvectortest")
