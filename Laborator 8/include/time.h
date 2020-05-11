#ifndef TIME_H
#define TIME_H
#include <iostream>
using namespace std;

class time
{
    friend ostream& operator<<(ostream&,const time&);
    public:
        time(int, int, int);
        time();
        void setTime(int, int, int);

       // void printLong();//tiparire in format lung

    protected:

         int hour; //0-23
         int minute; //0-59
         int second;


};

#endif // TIME_H
