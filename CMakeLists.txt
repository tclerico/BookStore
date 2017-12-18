cmake_minimum_required(VERSION 3.8)
project(BookStore)


set(CMAKE_CXX_STANDARD 11)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})
set(SOURCE_FILES Book.cpp BookStore.cpp LinkedList.cpp LinkedQueue.cpp Person.cpp main.cpp)
add_executable(BookStore ${SOURCE_FILES})