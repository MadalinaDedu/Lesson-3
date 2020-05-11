#ifndef DATE_H
#define DATE_H


class Date
{
 public:
 //constructor implicit
 Date(int = 1, int = 1, int = 1990);
 void print();
 private:
 int day;
 int month;
 int year;
};

#endif // DATE_H
