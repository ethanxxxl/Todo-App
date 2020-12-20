#ifndef TODOCORE_H
#define TODOCORE_H

#include <Task.h>
#include <vector>
#include <fstream>


class TodoCore
{
private:
public:
	// list of task sorted by due date
	std::vector<Task> tasks;

	void load_file();

	void save_file(std::string filename);

};

#endif
