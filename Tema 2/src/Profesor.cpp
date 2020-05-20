#include "Profesor.h"
#include<vector>
#include<iostream>
#include"Persoana.h"

Profesor::Profesor(string nume,string departament): Persoana( nume,departament)
{

}

bool Profesor::adaugaCurs(string curs)
{
   int i,ok=0;
    if(listaCursuri.size()<NR_MAX_CURSURI)
    {
        for(i=0;i<listaCursuri.size();i++)
             if(curs==listaCursuri[i]) ok=1;
         else ok==0;

   }
   if(ok==0)
     {
        listaCursuri.push_back(curs);
        return true;
    }
    else
        return false;



}

bool Profesor::stergeCurs(string curs)
{  int ok=1,j=0;
    for(int i=0; i<listaCursuri.size(); i++)

          if(curs==listaCursuri[i])
            {ok=0;
             j=i;
             break;}


      if(ok==0)
      {
             listaCursuri.erase(listaCursuri.begin()+j);
             return true;
      }
      else
        return false;

}

ostream& operator<<(ostream& out,  const Profesor& p)
{
    out<<"Profesor: "<<p.nume
       <<" ("<<p.afiliere<<") ";
       return out;
}
