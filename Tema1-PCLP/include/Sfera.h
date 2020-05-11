#ifndef SFERA_H
#define SFERA_H
#include "Punct3D.h"

class Sfera
 {
     public:
      Sfera(Punct3D ,double );
      void setPct(Punct3D ) ;
      Punct3D getPct();

      void setR(double );
      double getR();
      double volum();
      double distO();
     private:

        Punct3D c;
        double r;

 };

#endif // SFERA_H

