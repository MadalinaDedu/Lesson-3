#include "Sfera.h"
#include "Punct3D.h"
#include<math.h>

  Sfera::Sfera (Punct3D c,double r)
    {
        this->c=c;
        this->r=r;
    }


  void Sfera::setPct(Punct3D c) {this->c=c;}
  Punct3D Sfera::getPct(){return c;}

  void Sfera::setR(double r) { this->r=r;}
  double Sfera::getR(){return r;}

  double Sfera::volum()
{
     double raza;
     raza=r*r*r;

     return (4*3.14*raza)/3;
}

  double Sfera::distO()
{

     return sqrt(c.getX()*c.getX()+c.getY()*c.getY()+c.getZ()*c.getZ());

}


