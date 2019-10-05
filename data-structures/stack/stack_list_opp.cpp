//
// Stack implemented on class (list inside)
// More documentation about the algorithm
//
// The All ▲lgorithms Project
//
// https://allalgorithms.com/
// https://github.com/allalgorithms/cpp
//
// Contributed by: Carlos Abraham Hernandez
// Github: @TheBestTvarynka
//

#include <iostream>

using namespace std;

template <typename T>
struct Node
{
    T Value;
    Node *Next;
};

template <typename T>
class Stack
{
    Node<T> *Head;
public:
    Stack();
    void push(T );
    bool pop(T &);
    bool top(T &);
    bool is_empty();
    int size();
    void print();
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
Stack<T>::~Stack()
{
    Node<T> *t = Head, *p = t;
    while (t != nullptr) 
    {
        p = p->Next;
        delete t;
        t = p;
    }
}

template <typename T>
Stack<T>::Stack()
{
    Head = new (Node<T>);
    Head->Next = nullptr;
}

template <typename T>
void Stack<T>::print()
{
    Node<T> *t;
    t = Head;
    t = t->Next;
    while (t != nullptr)
    {
        cout << t->Value << " ";
        t = t->Next;
    }
    cout << endl;
}

template <typename T>
bool Stack<T>::is_empty()
{
    if (Head->Next == nullptr)
        return true;
    return false;
}

template <typename T>
void Stack<T>::push(T Value)
{
    Node<T> *t;
    t = new (Node<T>);
    t->Value = Value;
    t->Next = Head->Next;
    Head->Next = t;
}

template <typename T>
bool Stack<T>::pop(T &out)
{
    if (is_empty())
        return false;
    Node<T> *t;
    t = Head->Next;
    Head->Next = t->Next;
    out = t->Value;
    delete t;
    return true;
}

template <typename T>
bool Stack<T>::top(T &out)
{
    if (is_empty())
        return false;
    out = (Head->Next)->Value;
    return true;
}

template <typename T>
int Stack<T>::size()
{
    int Size = 0;
    Node<T> *t;
    t = Head;
    while (t->Next != nullptr)
    {
        t = t->Next;
        Size++;
    }
    return Size;
}