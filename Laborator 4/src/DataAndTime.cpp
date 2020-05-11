#include "DataAndTime.h"
#include <iostream>
using std::cout;
using std::endl;


DataAndTime::DataAndTime(int _year, int _month,int _day, int _hour,int _minute, int _second)
{
    year=_year;
    month=_month;
    day=_day;
    hour=_hour;
    minute=_minute;
    second=_second;
}
void DataAndTime::print_DataAndTime()
{
    cout<<"an:"<<year<<"  "<<"luna:"<<month<<"  "<<"zi:"<<day<<endl;
    cout << (hour < 10 ? "0" : "") << hour << ":"
 << (minute < 10 ? "0" : "") << minute<< ":" << (second < 10 ? "0" : "") << second;
}
void DataAndTime::tick()
{
    second=second+1;
    if(second>=60)
    {
        minute=minute+1;
        second=0;
        if(minute>=60)
           {
              hour=hour+1;
              minute=0;
              if(hour>=24)
           { day=day+1;
             hour=0;

            if(month==1 && day==31)
                month=month+1;
            if(month==2 && year%4==0 && day>=29)
                month++;
            if(month==3 && day>=31)
                month++;
            if(month==4 && day>=30)
                month++;
            if(month==5 && day>=31)
                month++;
            if(month==6 && day>=30)
                month++;
            if(month==7 && day>=31)
                month++;
            if(month==8 && day>=31)
                month++;
            if(month==9 && day>=30)
                month++;
            if(month==10 && day>=31)
                month++;
            if(month==11 && day>=30)
                month++;
            if(month==12 && day>=31)
               {
                   year++;
                   month=1;
                   day=1;
               }
}

          }

    }
}
