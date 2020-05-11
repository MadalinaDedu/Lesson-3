#include "Punct3D.h"

Punct3D::Punct3D(double x,double y, double z)
    {
        setX(x);
        setY(y);
        setZ(z);
    }
Punct3D::Punct3D(){};

void Punct3D::setX(double x) { this->x=x;}
double Punct3D::getX(){return x;}

void Punct3D::setY(double y){this->y=y;}
double Punct3D::getY(){return y;}

void Punct3D::setZ(double z){this->z=z;}
double Punct3D::getZ(){return z;}

