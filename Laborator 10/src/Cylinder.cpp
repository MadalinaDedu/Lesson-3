#include "cylinder.h"
Cylinder::Cylinder(double h, double r, int x, int y)
    : Circle(r, x, y)
{
    setHeight(h);
}
void Cylinder::setHeight(double h)
{
    height = (h >= 0 ? h : 0);
}

double Cylinder::getHeight() const
{
    return height;
}


ostream& operator<<(ostream& output, const Cylinder& c)
{
    output << static_cast<Circle>(c)
           << "; Inaltimea = " << c.height;
    return output;
}

void Cylinder::area()
{
    double a;
    a=2*3.14*radius*height;
    cout<<"Aria cilindrului este: "<<a<<endl;
}
