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

	std::map<std::string, std::vector<Task*>> categories;

public:
	enum class SortBy { DUE_DATE, CREATION_DATE, NAME };

	// returns a constant vector of either completed, or incompleted tasks, depending on the value of completed
	const std::vector<Task*> get_tasks(SortBy s, bool completed=true);
	time_t get_next_due_date();

	void create_task(const std::string& name, const time_t& due_date, const std::string category="");
	void complete_task(int tsk);
	
	// make sure to add each task to its corresponding category. the "" category means no category
	void update_category(Task* tsk, std::string category);

	void delete_task(int tsk);

	void load_file(std::string filename);
	void save_file(std::string filename);

	~TodoCore();
};

#endif
