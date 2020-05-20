#include "Persoana.h"

Persoana::Persoana(string nume, string afiliere)
{
    this->nume=nume;
    this->afiliere=afiliere;

}

 string Persoana::getNume()
 {
     return nume;
 }

string Persoana::getAfiliere()
{
    return afiliere;

}

void Persoana::setNume(string afiliere)
{
    afiliere=afiliere;
}
