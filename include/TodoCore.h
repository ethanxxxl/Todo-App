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

	// returns a constant vector of completed tasks, in the order specified by s
	const std::vector<Task*> get_completed(SortBy s);
	// returns a constant vector of incomplete tasks, in the order specified by s
	const std::vector<Task*> get_incomplete(SortBy s);

	void create_task(const std::string& name, const time_t& due_date);
	void complete_task(int tsk);
	void delete_task(int tsk);

	void load_file(std::string filename);
	void save_file(std::string filename);

	~TodoCore();
};

#endif
