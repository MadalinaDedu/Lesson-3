#include "DateTime.h"

DateTime::DateTime(int h, int min, int s,int d, int m, int y)
{
     hour=h;
     minute=min;
     second=s;
     day = d;
     month = m;
     year = y;

}

void DateTime::print()
{
    cout << endl << "Se executa DateTime::print()"<< endl;
    time::print();
    cout << day << '-' << month << '-' << year;



}

