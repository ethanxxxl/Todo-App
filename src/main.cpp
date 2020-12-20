
/*
 * this should be a library API, so that I can make it cross platform.
 *
 * no UI stuff here, pure functionality.
 * 
 * there needs to be a top level structure that manages basic things, like time
 * polling, etc.
 *
 * for generation 1, this is what needs to be included:
 *   - A way to get the time
 *   - regular tasks
 *   - compounding tasks
 *   
 */

#include <chrono>
#include <thread>
#include <iostream>
#include <TodoCore.h>
#include <Task.h>
#include <fstream>
#include <json.hpp>

int main()
{
	Task t1 = {	std::chrono::system_clock::now(), "Watch Lecture", false};
	Task t2 = {	std::chrono::system_clock::now(), "Do homework", false};
	Task t3 = {	std::chrono::system_clock::now(), "finish project", false};

	TodoCore core;
	core.tasks.push_back(t1);
	core.tasks.push_back(t2);
	core.tasks.push_back(t3);

	core.save_file("test_file.txt");

	return 0;
}
