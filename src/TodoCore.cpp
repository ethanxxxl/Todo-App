#include <TodoCore.h>

#include <fstream>
#include <json.hpp>
#include <iostream>

using nlohmann::json;

void TodoCore::save_file(std::string filename)
{
	std::ofstream file(filename);

	json jfile;

	for ( auto t : tasks )
	{
		json j = *t;
		jfile.push_back(j);
	}

	file << jfile;
	file.close();
}

void TodoCore::load_file(std::string filename)
{
	std::ifstream file(filename);
	json jfile;
	
	// load tasks into memory
	file >> jfile;

	// no old tasks should be in the list
	tasks.clear();

	// load new tasks into vector
	for ( auto j : jfile )
	{
		Task* t = new Task();
		*t = j;
		tasks.push_back(t);
	}

	file.close();
}

void TodoCore::create_task(const std::string& name, const time_t& due_date)
{
	Task* t = new Task();
	t->name = name;
	t->due_date = due_date;

	tasks.push_back(t);
}

void TodoCore::complete_task(int tsk)
{
	tasks[tsk]->complete_subtasks();
	tasks[tsk]->completed = true;
}

TodoCore::~TodoCore()
{
	for ( auto t : tasks )
	{
		delete(t);
	}
}
