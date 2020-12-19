#ifndef TODOCORE_H
#define TODOCORE_H

#include <Task.h>
#include <vector>

/* Things to consider:
 *  - what file format for tasks?
 *  - how to handle current time? for recurring/compounding tasks, and overdue tasks
 */

class TodoCore
{
private:
	std::vector<Task> tasks;



};
#endif
