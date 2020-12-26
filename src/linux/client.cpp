#include <chrono>
#include <thread>
#include <iostream>
#include <TodoCore.h>
#include <Task.h>
#include <fstream>
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
		// parse/tokenize command input
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
			if ( args.size() > 3 )
			{
				std::cout << "ls: incorrect usage";
				continue;
			}

			std::cout << std::left << std::setw(10) << "Name"
					  << std::left << std::setw(20) << "Due Date"
					  << std::endl;

			bool get_completed = true;
			TodoCore::SortBy sort_method;
			
			if ( args.size() < 3 || args[2] == "incomplete" )
				get_completed = false;
			else
			{
				std::cout << "you can only display complete or incomplete tasks";
				continue;
			}
			
			if ( args.size() == 1 || args[1] == "due_date" )
				sort_method = TodoCore::SortBy::DUE_DATE;
			else if ( args[1] == "name" )
				sort_method = TodoCore::SortBy::NAME;
			else if ( args[1] == "creation_date" )
				sort_method = TodoCore::SortBy::CREATION_DATE;
			else
			{
				std::cout << "please enter a proper sorting method.\ndue_date, creation_date, and name are currently supported" << std::endl;
				continue;
			}

			const std::vector<Task*> tasks = tdc.get_tasks(sort_method, get_completed);
			
			for ( Task* tsk : tasks )
			{
				char str_buf[512];
				struct tm* due_date_tm = localtime(&tsk->due_date);

				std::strftime(str_buf, 512, "%D @ %H%M", due_date_tm);

				std::cout << std::left << std::setw(10) << tsk->name
						  << std::left << std::setw(20) << str_buf
						  << std::endl;
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
