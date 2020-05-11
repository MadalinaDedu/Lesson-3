#include <iostream>
using std::cout;
#include "time.h"
/*Time::Time(int hr, int min, int sec)
{
 setTime(hr, min, sec);
}*/

Time::Time()
{
   setTime(0, 0, 0);
}

Time::Time(int hr)
{
   setTime(hr, 0, 0);
}

Time::Time(int hr, int min)
{
   setTime(hr, min, 0);
}


Time::Time(int hr, int min, int sec)
{
   setTime(hr, min, sec);
}
void Time::tick()
{
    second=second+1;
    if(second==60)
    {
        minute=minute+1;
        second=0;
        if(minute==60)
           {
              hour=hour+1;
              minute=0;
        if(hour==24)
            hour=0;
           }
    }
}

void Time::setTime(int h, int m, int s)
{
     hour = (h >= 0 && h < 24) ? h : 0;
     minute = (m >= 0 && m < 60) ? m : 0;
     second = (s >= 0 && s < 60) ? s : 0;
}
void Time::printShort()
{
 cout << (hour < 10 ? "0" : "") << hour << ":"
 << (minute < 10 ? "0" : "") << minute;
}
void Time::printLong()
{
 cout << ((hour == 0 || hour == 12) ?
 12 : hour % 12)
 << ":" << (minute < 10 ? "0" : "") << minute
 << ":" << (second < 10 ? "0" : "") << second

 << (hour < 12 ? " AM" : " PM");
}
