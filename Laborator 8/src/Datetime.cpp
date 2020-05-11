#include "Datetime.h"

Datetime::Datetime(int h, int min, int s,int d, int m, int y)
     :time(h,min,s)
{

     day = d;
     month = m;
     year = y;

}

ostream& operator<<(ostream& out, const Datetime& d)
{
    out << endl << "Se executa DateTime::print()"<< endl;
   out << d.day << '-' << d.month << '-' << d.year<<endl<<static_cast<time>(d);
   return out;



}

