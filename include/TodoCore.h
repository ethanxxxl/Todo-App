#ifndef TODOCORE_H
#define TODOCORE_H

#include <Task.h>
#include <map>
#include <fstream>
#include <chrono>

/*
 */
class TodoCore
{
private:
	// list of tasks.
	std::vector<Task*> tasks;

public:
	enum class SortBy { DUE_DATE, CREATION_DATE, NAME };

	// returns a constant vector of either completed, or incompleted tasks, depending on the value of completed
	const std::vector<Task*> get_tasks(SortBy s, bool completed=true);

	void create_task(const std::string& name, const time_t& due_date);
	void complete_task(int tsk);
	void delete_task(int tsk);

	void load_file(std::string filename);
	void save_file(std::string filename);

	~TodoCore();
};

#endif
