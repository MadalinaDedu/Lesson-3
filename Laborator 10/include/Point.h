#ifndef POINT_H
#define POINT_H
#include <iostream>
using namespace std;
using std::ostream;
class Point
{

    friend ostream& operator<<(ostream&, const Point&);
public:
    virtual void area() const{
        cout<<"Aria unui punct este: 0"<<endl;
    }
    Point(int = 0, int = 0); //constructor implicit
    void setPoint(int, int); //seteaza coordonatele
    int getX() const
    {
        return x;    //returneaza x
    }
    int getY() const
    {
        return y;    //returneaza y
    }
protected: //accesibil din clasele derivate
    int x, y; //x si y coordonatele unui punct
};
#endif
