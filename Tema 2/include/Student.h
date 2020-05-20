#ifndef STUDENT_H
#define STUDENT_H
#include "Persoana.h"
#include<vector>
#include<string>
using namespace std;

class Student: public Persoana
{
    public:
        Student(string,string);
        bool adaugaNotaCurs(string,int);
        void tiparesteNote();
        double mediaNotelor();

        friend ostream& operator<<(ostream&,const Student&);




    private:
        vector<string> listaCursuri;
        vector<int> note;
        const int NR_MAX_CURSURI=30;
};

#endif // STUDENT_H
