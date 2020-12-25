
/*
 * this should be a library API, so that I can make it cross platform.
 *
 * no UI stuff here, pure functionality.
 * 
 * there needs to be a top level structure that manages basic things, like time
 * polling, etc.
 *
 * for generation 1, this is what needs to be included:
 *   - A way to get the time
 *   - regular tasks
 *   - compounding tasks
 *   
 */

#include <chrono>
#include <thread>
#include <iostream>
#include <TodoCore.h>
#include <Task.h>
#include <fstream>
#include <Calendar.h>
#include <iostream>
#include <vector>
#include <sstream>
#include <iomanip>
#include <ctime>

int main()
{
	bool exit = false;

	TodoCore tdc = TodoCore();
	while ( !exit )
	{
		std::cout << ">>> ";
		std::string input;
		std::getline(std::cin, input);

		if ( input == "" )
			continue;

		std::stringstream input_stream(input);
		std::vector<std::string> args;

		std::string arg;
		do
		{
			input_stream >> arg;
			args.push_back(arg);
			
			// check if eof was reached
			if ( input_stream.eof() )
				break;
		} while ( arg.size() != 0 );
		
		if ( args[0] == "exit" )
		{
			exit = true;
		}
		else if ( args[0] == "load" )
		{
			if ( args.size() != 2 )
			{
				std::cout << "save: invalid usage.\ncorrect usage: save [filename]";
				continue;
			}

			std::cout << "loading from file \"" << args[1] << "\"...";
			tdc.load_file(args[1]);
		}
		else if ( args[0] == "save" )
		{
			if ( args.size() != 2 )
			{
				std::cout << "save: invalid usage.\ncorrect usage: save [filename]";
				continue;
			}

			std::cout << "saving to file \"" << args[1] << "\"...";
				tdc.save_file(args[1]);
		}
		else if ( args[0] == "ls" )
		{
			if ( args.size() > 2 )
			{
				std::cout << "ls: incorrect usage";
				continue;
			}

			std::cout << "Name" << std::setw(20) << "Due Date" << std::endl;
			for ( Task tsk : tdc.tasks )
			{
				if ( args.size() == 1 ) // list incomplete tasks
					{if ( tsk.completed ) continue;}
				else if ( args[1] == "completed" )
					{if ( !tsk.completed ) continue;}

				char str_buf[512];
				struct tm* due_date_tm = localtime(&tsk.due_date);

				std::strftime(str_buf, 512, "%D @ %H%M", due_date_tm);

				std::cout << tsk.name << std::setw(20) << str_buf << std::endl;
			}
		}
		else if ( args[0] == "add" )
		{
			if ( args.size() != 3 )
			{
				std::cout << "add: incorrect usage\ncorrect usage: add [name] [%D.%H%M]\nall in their numerical form" << std::endl;;
				continue;
			}
			// build the time from user input
			struct tm due_date = {0};

			std::stringstream due_date_input(args[2]);
			due_date_input >> std::get_time(&due_date, "%D.%H%M");

			if ( due_date_input.fail() )
			{
				std::cout << "incorrect date format! correct format is \"%m/%d/%y.%H%M\"" << std::endl;
				continue;
			}
			else
			{
				// create the task in the core.
				tdc.create_task(args[1], mktime(&due_date));
			}
		}
		else
		{
			std::cout << "unrecognized command \"" << args[0] << "\"";
		}

		std::cout << std::endl;

	}
	return 0;
}
