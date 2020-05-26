/*#include "Queue.h"


template<class T>
Queue<T>::Queue(int s)
{
    size=s>0 ? s : 10;
    top=-1;
    queuePtr=new T[size];

}
template<class T>
bool Queue<T>::push(const T& pushValue)
{
    if(!isFull())
    {
        queuePtr[++top]=pushValue;
        return true;
    }
    else
        return false;
}

template<class T>
 bool Queue<T>::pop(T& popValue)
{
    if(!isEmpty())
    {
        int first=1;
        popValue=queuePtr[first++];
        return true;
    }
    return false;
}
*/
