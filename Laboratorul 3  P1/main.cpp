#include <iostream>
using std::cout;
using std::endl;

struct Time //definitia structurii
  {
    int hour; //0-23
    int minute; //0-59
    int second; //0-59
  };

void printShort(const Time&);
void printLong (const Time&);

int main()
{
 Time dinnerTime; //obiect de tip Time
 //asignarea unor valori valide membrilor obiectului
    dinnerTime.hour = 18;
    dinnerTime.minute = 30;
    dinnerTime.second = 0;
 cout << "Cina va avea loc la ora ";

 printShort(dinnerTime);
 cout << " (format scurt), \nadica la ora ";

 printLong(dinnerTime);
 cout << " (format lung).\n" << endl;

 //asignarea unor valori invalide membrilor obiectului
 dinnerTime.hour = 29;
 dinnerTime.minute = 73;
 cout << "Obiect de tip Time cu valori invalide: ";
 printShort(dinnerTime);
 cout << endl;

// system("pause");

 return 0;
}
void printShort(const Time &t)
{
 cout << (t.hour < 10 ? "0" : "") << t.hour << ":"<< (t.minute < 10 ? "0" : "") << t.minute;
}
void printLong(const Time &t)
{
 cout << ((t.hour == 0 || t.hour == 12) ? 12 : t.hour % 12)
 << ":" << (t.minute < 10 ? "0" : "") << t.minute
 << ":" << (t.second < 10 ? "0" : "") << t.second
 << (t.hour < 12 ? " AM" : " PM");
}

