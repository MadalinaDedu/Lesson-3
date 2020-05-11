#include "time.h"
#include<iostream>
using std::cout;
using std::endl;

time::time()
{
     hour = minute = second = 0;
}

time::time(int hr, int min, int sec)
{
 setTime(hr, min, sec);
}


void time::setTime(int h, int m, int s)
{
     hour = (h >= 0 && h < 24) ? h : 0;
     minute = (m >= 0 && m < 60) ? m : 0;
     second = (s >= 0 && s < 60) ? s : 0;
}

void time::printLong()
{
     cout << ((hour == 0 || hour == 12) ? 12 : hour % 12)
          << ":" << (minute < 10 ? "0" : "") << minute
          << ":" << (second < 10 ? "0" : "") << second
          << (hour < 12 ? " AM" : " PM");

}

void time::print()
{
    cout<<hour<<":"<<minute<<":"<<second<<endl;
}

