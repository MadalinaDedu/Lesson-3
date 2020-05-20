#ifndef PROFESOR_H
#define PROFESOR_H
#include"Persoana.h"
#include<vector>



class Profesor: public Persoana
{
    public:
        Profesor (string , string);
        bool adaugaCurs(string curs);
        bool stergeCurs(string curs);

        friend ostream& operator<<(ostream&,const Profesor&);


    private:
        vector<string> listaCursuri;
        const int NR_MAX_CURSURI=5;
};

#endif // PROFESOR_H
