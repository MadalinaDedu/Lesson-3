#ifndef QUEUE_H
#define QUEUE_H

template <class T>

class Queue
{
    public:
        Queue( int n);
        bool push(const T&);
        bool pop(T&);

    private:
        int size;
        int top;
        T* queuePtr;
        bool isEmpty() const {return top==-1;}
        bool isFull() const {return top==size-1;}
};

template <class T>
Queue<T>::Queue(int s)
{
    size = s > 0 ? s : 10;
    top = -1;
    queuePtr = new T[size];
}

template <class T>
bool Queue<T>::push(const T& pushValue)
{
    if (!isFull())
    {
        queuePtr[++top] = pushValue;
        return true;
    }
    return false;
}

template <class T>
bool Queue<T>::pop(T& popValue)
{
    //int first=1;
    int i=0;
    if (!isEmpty())
    {   popValue=queuePtr[0];
        while(i<top)
       {
           queuePtr[i]=queuePtr[i+1];
           i++;
       }
       top--;
        return true;
    }
    return false;
}

#endif // QUEUE_H

