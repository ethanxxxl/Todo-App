cmake_minimum_required(VERSION 3.10)

project(TodoApp CXX)

set(SRC
	src/main.cpp
	src/TodoCore.cpp
	src/Task.cpp
	)

set(CMAKE_CXX_FLAGS -std=c++20)

include_directories(./include)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_BUILD_TYPE Debug)

add_executable(run ${SRC})

target_link_libraries(run)
