#ifndef TASK_H
#define TASK_H

#include <chrono>
#include <string>
#include <ios>
#include <json.hpp>
#include <ctime>

using nlohmann::json;

struct Task;
void to_json(json& j, const Task& tsk);
void from_json(const json& j, Task& tsk);

struct Task
{
	std::string name;
	bool completed;
	
	std::time_t creation_date;
	std::time_t due_date;

	std::vector<Task*> subtasks;
	void complete_subtasks();

	friend void to_json(json& j, const Task& tsk);
	friend void from_json(const json& j, Task& tsk);
};

/* Your traditional annoying recurring task. When you complete it, it skips all previous
 *  would-have occurences of the task, and makes a new one in the future
 */
struct RecurringTask : public Task
{
};

/* A better recurring task. tasks actually represent real world tasks. It can either create a
 *  sub task or new regular task for every missed deadline.
 */
struct CompoundingTask : public Task
{
};



#endif
