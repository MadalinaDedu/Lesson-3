#include <iostream>
using std::cout;
using std::endl;
class Time
{
     public:
     Time(); //constructor
     void setTime(int, int, int); //asignarea valorilor
     void printShort(); //tiparire in format scurt
     void printLong (); //tiparire in format lung
     private:
     int hour; //0-23
     int minute; //0-59
     int second; //0-59
};

Time::Time()
{
 hour = minute = second = 0;
 cout << "S-a rulat constructorul clasei Time" << endl;
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
 cout << ((hour == 0 || hour == 12) ? 12 : hour % 12)
 << ":" << (minute < 10 ? "0" : "") << minute
 << ":" << (second < 10 ? "0" : "") << second
 << (hour < 12 ? " AM" : " PM");
}

int main()
{
     Time t; //instantiaza obiectul t de tip Time
     cout << "Valoarea initialia in format scurt este ";
     t.printShort();

     cout << "\nValoarea initialia in format lung este ";
     t.printLong();

     t.setTime(13, 27, 6);
     cout << "\n\nOra in format scurt dupa setTime este ";
     t.printShort();

     cout << "\nOra in format lung dupa setTime este ";
     t.printLong();

     //asignarea unor valori invalide membrilor obiectului
     t.setTime(99, 99, 99);
     cout << "\n\nDupa asignarea valorilor invalide:"
     << "\nOra in format scurt: ";
     t.printShort();

     cout << "\nOra in format lung: ";
     t.printLong();
     cout << endl;

   //  system("pause");
     return 0;
}
