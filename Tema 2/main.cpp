#include <iostream>
#include "Persoana.h"
#include "Student.h"
#include "Profesor.h"
using namespace std;
int main()
{
    /**
    * Testeaza clasa Persoana si clasele derivate din aceasta.
    */
    /** Testeaza clasa Student */
    Student s1("Andrei Popescu", "ETTI1");
    s1.adaugaNotaCurs("TST.8.09", 9);
    s1.adaugaNotaCurs("TST.8.10", 8);
    s1.adaugaNotaCurs("TST.8.11", 10);
    s1.adaugaNotaCurs("TST.8.12", 6);
    s1.tiparesteNote();
    /** Student: Andrei Popescu (ETTI1) TST.8.09:9 TST.8.10:8 TST.8.11:10
    TST.8.12:6*/
    cout << "Media este " << s1.mediaNotelor() << endl << endl;
    /** Media este 8.25 */
    /** Testeaza clasa Profesor */
    Profesor p1("Paul Constantinescu", "UnitBv/DEC");
    cout << p1 << endl;
    /** Profesor: Paul Constantinescu (UnitBv/DEC) */
    vector<string> cursuri = {"CALC.8.11", "EA813", "ETTI210", "CALC.8.11",
                              "TST.6.16"
                             };
    for (string curs : cursuri)
    {
        if (p1.adaugaCurs(curs))
        {
            cout << curs << " adaugat" << endl;
        }
        else
        {
            cout << curs << " nu poate fi adaugat" << endl;
        }
    }
    cout << endl;
    /**
    CALC.8.11 adaugat
    EA813 adaugat
    ETTI210 adaugat
    CALC.8.11 nu poate fi adaugat
    TST.6.16 adaugat
    */
    for (string curs : cursuri)
    {
        if (p1.stergeCurs(curs))
        {
            cout << curs << " sters" << endl;
        }
        else
        {
            cout << curs << " nu poate fi sters" << endl;
        }
    }
    /**
    CALC.8.11 sters
    EA813 sters
    ETTI210 sters
    CALC.8.11 nu poate fi sters
    TST.6.16 sters
    */
    return 0;
}
