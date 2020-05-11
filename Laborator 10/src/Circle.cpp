#include "circle.h"
//Constructorul clasei Circle apeleaza
//constructorul pentru Point si apoi
//initializeaza raza
Circle::Circle(double r, int a, int b)
    : Point(a, b)
{
    setRadius(r);
}
//Seteaza raza cercului
void Circle::setRadius(double r)
{
    radius = (r > 0 ? r : 0);
}
//Returneaza raza cercului
double Circle::getRadius() const
{
    return radius;
}


//Afiseaza datele despre cerc in forma
//Centrul = [x, y]; Raza = #.##
ostream& operator<<(ostream& output, const Circle& c)
{
    output << "Centrul = " << static_cast<Point>(c)
           << "; Raza = "
           << setiosflags(ios::fixed | ios::showpoint)
           << setprecision(2) << c.radius;
    return output;
}

void Circle::area()
{
    double a;
    a=3.14*3.14*radius;
    cout<<"Aria cercului este: "<<a<<endl;
}
