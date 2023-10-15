cmake_minimum_required(VERSION 3.0)
project(MyCircularList)

# Define the source files for your project
set(SOURCES
    circularlist.cpp
    list.cpp
)

add_executable(MyCircularList ${SOURCES})
