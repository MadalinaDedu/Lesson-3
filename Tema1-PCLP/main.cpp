#include <iostream>
#include"Sfera.h"

using namespace std;

ostream& operator<<(ostream& o, Punct3D &p)
{
    o<<"["<<p.getX()<<";"<<p.getY()<<";"<<p.getZ()<<"]";
    return o;
}


 ostream& operator<<(ostream& o, Sfera &s)
{
    o<<"["<<"["<<s.getPct().getX()<<";"<<s.getPct().getY()<<";"<<s.getPct().getZ()<<"]"<<";"<<s.getR()<<"]";
    return o;
}

int main()
{

 Punct3D pct(-1.1, 2.2, 3.3);
 Sfera sfr(pct, 4.1);

cout << "Punct3D: " << pct << endl
     << "Sfera: " << sfr << endl
     << "Volumul: " << sfr.volum() << endl
     << "Distanta de la centru la origine: " << sfr.distO() << endl;
 return 0;

}
