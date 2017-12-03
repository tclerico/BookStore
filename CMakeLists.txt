cmake_minimum_required(VERSION 3.8)
project(BookStore)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp Book.cpp BookStore.cpp LinkedList.cpp LinkedQueue.cpp Person.cpp)
add_executable(BookStore ${SOURCE_FILES})