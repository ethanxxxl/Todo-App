#include <TodoCore.h>

#include <atomic>
#include <fstream>
#include <json.hpp>
#include <iostream>
#include <algorithm>

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

const std::vector<Task*> TodoCore::get_tasks(TodoCore::SortBy s, bool completed)
{
	std::vector<Task*> filtered_tasks;
	filtered_tasks.reserve(tasks.size());
	
	// weed out unwanted tasks
	for ( auto t : tasks )
	{
		if ( t->completed == !completed )
			continue;

		filtered_tasks.push_back(t);
	}

	// sort functor
	struct sort_tasks
	{
		sort_tasks(SortBy s) : sort_method(s) {}

		bool operator()(Task* a, Task* b)
		{
			switch ( sort_method )
			{
			case SortBy::DUE_DATE:
				if ( a->due_date < b->due_date )
					return true;
				else
					return false;
			case SortBy::CREATION_DATE:
				if ( a->creation_date < b->creation_date )
					return true;
				else
					return false;
			case SortBy::NAME:
				if ( (a->name <=> b->name) < 0 ) // a < b
					return true;
				else
					return false;
			}
		}

	private:
		SortBy sort_method;
	};

	sort_tasks sorter(s);

	std::sort(filtered_tasks.begin(), filtered_tasks.end(), sorter);
	
	return filtered_tasks;
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
