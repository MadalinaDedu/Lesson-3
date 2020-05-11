#ifndef DATAANDTIME_H
#define DATAANDTIME_H


class DataAndTime
{
    public:
        DataAndTime(int =2000, int =1,int =1, int =0,int =0, int =0);
        void print_DataAndTime();
        void tick();
    private:
        int year;
        int month;
        int day;
        int hour;
        int minute;
        int second;
};

#endif // DATEANDTIME_H
