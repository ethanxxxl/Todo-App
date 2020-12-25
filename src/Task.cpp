#include <Task.h>
#include <ios>
#include <sstream>
#include <chrono>

void to_json(json& j, const Task& tsk)
{
	j = json{
		{"name", tsk.name},
		{"due", tsk.due_date},
		{"completed", tsk.completed}
	};
}

void from_json(const json& j, Task& tsk)
{
	j.at("name").get_to(tsk.name);
	j.at("due").get_to(tsk.due_date);
	j.at("complete").get_to(tsk.completed);
}

void Task::complete_subtasks()
{
	for ( Task* tsk : subtasks )
	{
		tsk->complete_subtasks();
		tsk->completed = true;
	}
}
