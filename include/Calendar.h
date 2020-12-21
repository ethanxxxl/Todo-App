#ifndef CALENDAR_H
#define CALENDAR_H

#include <chrono>
#include <ios>
#include <ostream>

//
struct YearMonthDay
{
	//enum day_t {Monday, Tuesday, Wednesday, Thursday, Friday, Saturday, Sunday};
	enum month_t { January, Febuary, March, April, May, June, July, August, September, October, November, December };

	unsigned int year;
	month_t month;
	unsigned char day;

	// true if the contained date is valid
	bool ok();

	std::chrono::system_clock::time_point get_time_point();

	friend std::ostream& operator<<(std::ostream& out, YearMonthDay& ymd);
};

// the time of day in 24 hour format
struct DayTime
{
	unsigned char hours;
	unsigned char minutes;
	unsigned char seconds;
	
	bool ok();
	std::chrono::system_clock::time_point get_time_point();
};

#endif
