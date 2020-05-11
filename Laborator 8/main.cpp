#include <iostream>
#include "time.h"
#include "DateTime.h"

using namespace std;


int main()
{
  time t1(12,30,58);
  cout<<t1;
  Datetime t2(15,17,45,9,4,2020);
  cout<<t2;
    return 0;
}
