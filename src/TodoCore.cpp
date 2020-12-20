#include <TodoCore.h>

#include <fstream>
#include <json.hpp>
#include <iostream>

using nlohmann::json;

void TodoCore::save_file(std::string filename)
{
	std::ofstream file(filename);

	json jfile;

	for (auto t = tasks.begin(); t != tasks.end(); t++)
	{
		json j = *t;
		jfile.push_back(j);
	}

	file << jfile;
	file.close();

}
