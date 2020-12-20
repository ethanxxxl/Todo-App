#ifndef TASK_H
#define TASK_H

#include <chrono>
#include <string>
#include <ios>
#include <json.hpp>

using nlohmann::json;

struct Task;
void to_json(json& j, const Task& tsk);
void from_json(const json& j, Task& tsk);

struct Task
{
	std::chrono::system_clock::time_point due_date;
	std::string name;
	bool completed;

	friend void to_json(json& j, const Task& tsk);
	friend void from_json(const json& j, Task& tsk);
};


#endif
