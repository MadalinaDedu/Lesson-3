#ifndef TIME_H
#define TIME_H


class time
{
    public:
        time(int, int, int);
        time();
        void setTime(int, int, int);
        void print(); //tiparire in format scurt
        void printLong();//tiparire in format lung

    protected:

         int hour; //0-23
         int minute; //0-59
         int second;


};

#endif // TIME_H
