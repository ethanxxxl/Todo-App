cmake_minimum_required(VERSION 3.10)

project(TodoApp CXX)

set(SRC
	src/linux/main.cpp
	)

set(CMAKE_CXX_FLAGS -std=c++20)

include_directories(./include)
add_subdirectory(TaskCompounder)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_BUILD_TYPE Debug)

add_executable(client ${SRC})

target_link_libraries(client LINK_PUBLIC TaskCompounder)
