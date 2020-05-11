#include "complex.h"

Complex:: Complex(double r, double i)
{
     real = r;
     imaginar = i;
}

void Complex::setReal(double r)
{
    real = r;
}

double Complex::getReal() const
{
    return real;
}

void Complex::setImaginar(double i)
{
    imaginar = i;
}

double Complex::getImaginar() const
{
    return imaginar;
}

Complex Complex::operator+(Complex c)
{
 Complex nc;
 nc.setReal(real+c.real);
 nc.setImaginar(imaginar+c.imaginar);
 return nc;
}

Complex Complex::operator!()
{
    imaginar=imaginar*(-1);
    return Complex(real,imaginar);
}


 //prefixare
 Complex Complex::operator++()
 {
     ++real;
     return Complex(real,imaginar);
 }

 //post-fixare
  Complex Complex::operator++(int)
 {
     ++real;
     return Complex(real,imaginar);
 }
