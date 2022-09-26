#include <bits/stdc++.h>
using namespace std;
class MyCircularQueue
{
public:
    int cap;
    deque<int> q;

    MyCircularQueue(int k)
    {

        cap = k;
    }

    bool enQueue(int value)
    {

        if (isFull())
            return false;
        q.push_back(value);
        return true;
    }

    bool deQueue()
    {

        if (isEmpty())
            return false;
        q.pop_front();
        return true;
    }

    int Front()
    {
        if (isEmpty())
            return -1;

        return q.front();
    }

    int Rear()
    {
        if (isEmpty())
            return -1;

        return q.back();
    }

    bool isEmpty()
    {
        return (q.size() == 0);
    }

    bool isFull()
    {
        return (q.size() == cap);
    }
};
int main()
{
    MyCircularQueue q(5);
    for (int i=1;i<=5;i++){
        q.enQueue(i);
    }
    

    return 0;
}