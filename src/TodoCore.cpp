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
		json j = t;
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
		Task t = j;
		tasks.push_back(t);
	}

	file.close();
}
