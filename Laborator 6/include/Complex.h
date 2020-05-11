#ifndef COMPLEX_H
#define COMPLEX_H

#include <iostream>

class Complex
{
 public:
     Complex(double=0, double=0);
     void setReal(double);
     double getReal() const;
     void setImaginar(double);
     double getImaginar()const;

     Complex operator+(Complex);
     Complex operator!();

     Complex operator++();//prefixare
     Complex operator++(int);//post-fixare

     friend Complex operator*( const Complex&,const Complex& );
     friend std::istream& operator>>(std::istream&, Complex&);
     friend std::ostream& operator<<(std::ostream&, Complex&);





 private:
 double real;
 double imaginar;
};
#endif
