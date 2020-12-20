#include <Task.h>
#include <ios>
#include <sstream>
#include <chrono>

void to_json(json& j, const Task& tsk)
{
	j = json{
		{"name", tsk.name},
		{"due", std::chrono::system_clock::to_time_t(tsk.due_date)},
		{"completed", tsk.completed}
	};
}

void from_json(const json& j, Task& tsk)
{
	j.at("name").get_to(tsk.name);

	std::time_t tmp_due;
	j.at("due").get_to(tmp_due);
	tsk.due_date = std::chrono::system_clock::from_time_t(tmp_due);

	j.at("complete").get_to(tsk.completed);
}
