#include <iostream>

using namespace std;

#include "Queue.h"

int main()
{
    Queue<double> doubleQueue(5);
    double f = 1.1;
    cout << "Inserarea elementelor in doubleQueue\n";

    while(doubleQueue.push(f))
    {
        cout << f << " ";
        f += 1.1;
    }

    cout << "\nCoada este plina. " << "\nNu se mai poate insera elementul " << f
         << "\n\nExtragerea elementelor din doubleQueue\n";

    while (doubleQueue.pop(f))
        cout << f << " ";

    cout << "\nCoada este goala. " << "\nNu se mai pot extrage elemente\n";

    return 0;
}
