#include <iostream>
using namespace std;

class Stack
{
    int top;

  public:
    int a[10];
    Stack() : top(-1) {}
    void push(int x);
    int pop();
    bool isEmpty();
};

class Queue
{
  public:
    Stack s1;
    Stack s2;
    Queue()
    {
        Stack s1;
        Stack s2;
    }
    void enQueue(int x);
    int deQueue();
};

void Stack::push(int x)
{
    a[++top] = x;
}

int Stack::pop()
{
    if (isEmpty())
    {
        cout << "Underflow" << endl;
        return 0;
    }
    else
    {
        return a[top--];
    }
}

bool Stack::isEmpty()
{
    return (top == -1) ? true : false;
}

void Queue::enQueue(int x)
{
    s1.push(x);
}

int Queue::deQueue() {
    if(!s2.isEmpty()) {
        return s2.pop();
    }
    else {
        while(!s1.isEmpty()) {
            s2.push(s1.pop());
        }
        return s2.pop();
    }
}

int main()
{
    Queue q;
    q.enQueue(1);
    q.enQueue(2);
    q.enQueue(3);
    q.enQueue(4);
    cout << q.deQueue() << endl;
    q.enQueue(5);
    cout << q.deQueue() << endl;
    cout << q.deQueue() << endl;
}