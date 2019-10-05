#include <iostream>

using namespace std;

template <typename T>
class Stack
{
    T *ArrayStack;
    int Capasity;
    int Size;
    void resize(int );
public:
    Stack();
    Stack(int);
    void push(T );
    bool pop(T &);
    bool top(T &);
    bool is_empty();
    int size();
    ~Stack();
};

int main()
{
    char a;
    Stack<char > exapmle;
    exapmle.push('d');
    exapmle.push('b');
    exapmle.push('q');
    exapmle.push('k');
    exapmle.pop(a);
    cout << a << endl;
    cout << exapmle.size() << endl;
    return 0;
}

template <typename T>
Stack<T>::Stack()
{
    Capasity = 5;
    ArrayStack = new T[Capasity];
    Size = 0;
}
template <typename T>
Stack<T>::Stack(int s)
{
    Capasity = s;
    ArrayStack = new T[Capasity];
    Size = 0;
}
template <typename T>
Stack<T>::~Stack()
{
    delete [] ArrayStack;
}

template <typename T>
void Stack<T>::push(T value)
{
    if (Size == Capasity)
        resize(Capasity * 2);
    ArrayStack[Size] = value;
    Size++;
}

template <typename T>
void Stack<T>::resize(int newSize)
{
    // int newSize = (int)(Size * 1.5);
    T *NewStack = new T[newSize];
    for (int i = 0; i < Size; i++)
        NewStack[i] = ArrayStack[i];
    delete ArrayStack;
    Capasity = newSize;
    ArrayStack = NewStack;
}

template <typename T>
bool Stack<T>::pop(T &out)
{
    if (is_empty())
        return false;
    if (Size <= Capasity/4)
        resize(Capasity/2);
    Size--;
    out = ArrayStack[Size];
    return true;
}

template <typename T>
bool Stack<T>::top(T &out)
{
    if (is_empty())
        return false;
    out = ArrayStack[Size - 1];
    return true;
}

template <typename T>
bool Stack<T>::is_empty()
{
    if (Size == 0)
        return  true;
    return false;
}

template <typename T>
int Stack<T>::size()
{
    return Size;
}