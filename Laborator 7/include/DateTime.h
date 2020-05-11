#ifndef DATETIME_H
#define DATETIME_H
#include "time.h"
#include<iostream>
using std::cout;
using std::endl;

class DateTime: public time
{
    public:
        DateTime(int, int, int, int, int, int);
        void print();

    private:
        int day;
        int month;
        int year;
    };

#endif // DATETIME_H
