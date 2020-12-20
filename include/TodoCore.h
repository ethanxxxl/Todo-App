#ifndef TODOCORE_H
#define TODOCORE_H

#include <Task.h>
#include <vector>
#include <fstream>
#include <chrono>


class TodoCore
{
private:
public:
	// list of task sorted by due date
	std::vector<Task> tasks;

	//void create_task(std::string name, std::chrono::system_clock::time_point )

	void load_file(std::string filename);
	void save_file(std::string filename);

};

#endif
