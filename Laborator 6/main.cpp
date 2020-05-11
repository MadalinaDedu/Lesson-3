#include <iostream>
using std::cout;
using std::cin;
using std::endl;
//using namespace std;
#include "complex.h"

 Complex operator*( const Complex& a,  const Complex& b)
{
    Complex c;
    double parteReala=a.getReal()*b.getReal()-a.getImaginar()*b.getImaginar();
    double parteImaginara=a.getReal()*b.getImaginar()+a.getImaginar()*b.getReal();

    c.setReal(parteReala);
    c.setImaginar(parteImaginara);

    return c;
}
std::ostream& operator<<(std::ostream& o, Complex& c)
 {
     o<<c.getReal()<<";"<<c.getImaginar();
     return o;
 }
std::istream& operator>>(std::istream& in, Complex& c)
{
    double real=0;
    double imaginar=0;

    in>>real>>imaginar;

    c.setReal(real);
    c.setImaginar(imaginar);

     return in;
}
int main()
{
 Complex n1(2,4);
 Complex n2(1,-4),n3(0,0);
 cin>>n3;
 cout<<"N3:"<<n3<<endl;
 cout<<n3.getReal()<<";"<<n3.getImaginar()<<endl;
 n2 = n1+n2;
 n2=n1*n2;
 n1=!n1;

 ++n1;//prefixare
 n1++;//postfixare

 cout<<n1.getReal()<<";"<<n1.getImaginar()<<endl;
 cout << n2.getReal() << ";" << n2.getImaginar() << endl;

 return 0;
}
