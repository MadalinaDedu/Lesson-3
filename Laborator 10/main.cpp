#include <iostream>
#include "point.h"
#include "circle.h"
#include "cylinder.h"
using namespace std;

int main()
{
  cout<<"Functii apelate print pointer la Point"<<endl;
  Point* pointPct= new Point(2,5);
  pointPct->area();

  cout<<endl<<"Functii apelate prin pointer la Point"
      <<" initializate prin pointer la Circle:"<<endl;
  Point* pointC=new Circle(3,2,5);
  pointPct=pointC;

  cout<<"Comportament polimorfic"<<endl;
  pointPct->area();

  cout<<endl<<"Functie apelata prin obiect de tip Point"<<endl;
  Point p(2,5);
  p.area();

  cout<<endl<<"Functie apelata prin obiect de tip Circle"<<endl;
  Circle c(3,2,5);
  c.area();

  cout<<endl<<"Functie apelata prin obiect de tip Cylinder"<<endl;
  Cylinder ci(4,3,2,5);
  ci.area();
    return 0;

}
