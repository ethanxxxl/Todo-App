#include <Calendar.h>
#include <ostream>

bool YearMonthDay::ok()
	{
		if ( month == January || month == March || month == May || month == July || month == August || month == October || month == December)
		{
			if ( day <= 31 )
				return true;
			else
				return false;
		}

		if ( month == April || month == June || month == September || month == November )
		{
			if ( day <= 30 )
				return true;
			else
				return false;
		}

		if ( month == Febuary )
		{
			if ( year%4 == 0 && day <= 29 )
				return true;
			else if ( day <= 28 )
				return true;
			else
				return false;
		}

		// if execution reaches here, then month is not one of the 12 months
		return false;
	}

std::ostream& operator<<(std::ostream& out, YearMonthDay& ymd)
{
	out << std::to_string(ymd.day) << " ";

	switch ( ymd.month )
	{
		case YearMonthDay::January:
			out << "January" << " ";
			break;
		case YearMonthDay::Febuary:
			out << "Febuary" << " ";
			break;
		case YearMonthDay::March:
			 out << "March" << " ";
			 break;
		case YearMonthDay::April:
			 out << "April" << " ";
			 break;
		case YearMonthDay::May:
			 out << "May" << " ";
			 break;
		case YearMonthDay::June:
			 out << "June" << " ";
			 break;
		case YearMonthDay::July:
			 out << "July" << " ";
			 break;
		case YearMonthDay::August:
			 out << "August" << " ";
			 break;
		case YearMonthDay::September:
			 out << "September" << " ";
			 break;
		case YearMonthDay::October:
			 out << "October" << " ";
			 break;
		case YearMonthDay::November:
			 out << "November" << " ";
			 break;
		case YearMonthDay::December:
			 out << "December" << " ";
			 break;
	}

	out << std::to_string(ymd.year) << " ";

	return out;
}

bool DayTime::ok()
	{
		if ( hours < 24 && minutes < 60 && seconds < 60 )
			return true;
		else
			return false;
	}
