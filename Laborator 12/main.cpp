#include <iostream>
#include<cstring>
using namespace std;
//using std::cout;
//using std::endl;
#include<map>

int main()
{
     typedef std::map<string, int > mid;
      mid ob;
      ob.insert( mid::value_type("Maria", 10) );
      ob.insert( mid::value_type("Tiberiu", 9) );
      ob.insert( mid::value_type("Dana", 10) );
      ob.insert( mid::value_type("Sergiu", 10) );
      ob.insert( mid::value_type("Ana", 9) );


    map<string, int>::iterator it;
    for(it=ob.begin();it!=ob.end();++it)
        cout<<it->first<<'\t'<<it->second<<endl;
    return 0;
}
