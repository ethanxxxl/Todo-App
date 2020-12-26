cmake_minimum_required(VERSION 3.10)

set (SRC
	 src/TodoCore.cpp
	 src/Task.cpp
	 )

add_library(TaskCompounder ${SRC})
target_include_directories(TaskCompounder PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
