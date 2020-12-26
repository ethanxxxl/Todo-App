#include <Task.h>
#include <ios>
#include <sstream>
#include <chrono>

void to_json(json& j, const Task& tsk)
{
	j = json{
		{"name", tsk.name},
		{"category", tsk.category},
		{"due", tsk.due_date},
		{"created", tsk.creation_date},
		{"complete", tsk.completed}
	};
}

void from_json(const json& j, Task& tsk)
{
	j.at("name").get_to(tsk.name);
	j.at("category").get_to(tsk.category);
	j.at("created").get_to(tsk.creation_date);
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

void Task::complete()
{
	completed = true;
}
