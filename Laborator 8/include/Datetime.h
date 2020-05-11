#ifndef DATETIME_H
#define DATETIME_H
#include "time.h"
#include<iostream>
using std::cout;
using std::endl;

class Datetime: public time
{
    friend ostream& operator<<(ostream& ,const Datetime&);

    public:
        Datetime(int, int, int, int, int, int);

    private:
        int day;
        int month;
        int year;
    };

#endif // DATETIME_H
