#include <iostream>
#include "time.h"
#include "DateTime.h"

using namespace std;

int main()
{
  time t1(12,30,58);
  t1.print();
  DateTime t2(15,17,45,9,4,2020);
  t2.print();
    return 0;
}
