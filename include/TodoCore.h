#ifndef TODOCORE_H
#define TODOCORE_H

#include <Task.h>
#include <map>
#include <fstream>
#include <chrono>
#include <Calendar.h>

/*
 */
class TodoCore
{
private:
public:
	// list of tasks.
	std::vector<Task> tasks;

	void create_task(const std::string& name, const time_t& due_date);
	void complete_task(int tsk);
	void delete_task(int tsk);

	void load_file(std::string filename);
	void save_file(std::string filename);
};

#endif
