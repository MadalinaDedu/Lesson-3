#include <iostream>
using std::cout;
#include "date.h"

Date::Date(int d, int m, int y)
{
 day = d;
 month = m;
 year = y;
}
//Tipareste data in forma zi-luna-an
void Date::print()
{
 cout << day << '-' << month << '-' << year;
}
