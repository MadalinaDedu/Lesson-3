#ifndef PERSOANA_H
#define PERSOANA_H
#include<string>
using namespace std;

class Persoana
{
    public:
        Persoana(string,string);
        string getNume();
        string getAfiliere();
        void setNume(string);


    protected:
        string nume;
        string afiliere;



};

#endif // PERSOANA_H
