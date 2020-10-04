#pragma once
#include<iostream>

template<class T>
class Node{


    //each node has a next pointer and a previous pinter
public:
    T data;
    Node<T>* next;
    Node<T>* prev;


    Node()
    {
        next = nullptr;
        prev = nullptr;

    }

    explicit Node(T&& value) :
            data(std::move(value)),
            next(nullptr),
            prev(nullptr)
    {
    }

};


template<class T>
class DoublyLinkedList{

private:
    Node<T>* Head;
    Node<T>* Tail;
    int Size_;

public:

    DoublyLinkedList():
            Head(nullptr),
            Tail(nullptr),
            Size_(0)
    {
    }

    void Push_back(T val); //append
    void Pop_back();
    void Push_front(T val); //prepend
    void Pop_front();
    void Display() const;
    void Clear();
    void Insert_at(T val, int position);
    void Delete_at(int position);
    void Add_before(Node<T>* node, T val);
    void Add_after(Node<T>* node,T val);

    ~DoublyLinkedList()
    {
        std::cout<<"destructor is called"<<'\n';
        Clear();
    }

};
