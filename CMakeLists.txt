cmake_minimum_required(VERSION 3.8)
project(BookStore)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp Person.cpp Book.cpp BookStore.cpp)
add_executable(BookStore ${SOURCE_FILES})