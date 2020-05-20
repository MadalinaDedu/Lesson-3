#include "Student.h"
#include "Persoana.h"
#include <iostream>
#include<vector>

Student::Student(string nume,string specializare) : Persoana(nume, specializare)
{

}

bool Student::adaugaNotaCurs(string curs,int nota)
{
    if((int)listaCursuri.size()<NR_MAX_CURSURI)
    {
        listaCursuri.push_back(curs);
        note.push_back(nota);
        return true;
    }
    else
        return false;
}


void Student::tiparesteNote()
{
    cout<<"Student: "<<nume<<" ("<<afiliere<<") ";
   // vector<string>::const_iterator p1;
    for(int i=0; i<listaCursuri.size(); i++)
        cout<<listaCursuri[i]<<":"<<note[i]<<" ";
    cout<<endl;
}

double Student::mediaNotelor()
{
    int ok=0,m;
    double media=0;
    vector<int>::const_iterator p2;
    for(p2=note.begin(); p2!=note.end(); p2++)
    {
        ok++;
        m=*p2;
        media=media+m;
    }
    return media/ok;
}

ostream& operator<<(ostream& out,const Student& s)
{
    out<<"Nume:"<<s.nume<<endl
       <<"Specializare:"<<s.afiliere<<endl;
    return out;
}

