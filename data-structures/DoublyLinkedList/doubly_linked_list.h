#include<iostream>

using namespace std;

template<class T>

class Node{


 //each node has a next pointer and a previous pinter
  public:
      T data;
      Node<T>* next;
      Node<T>* prev;


      Node()
      {
           next = NULL;
           prev = NULL;

      }

      Node( T value)
      {
        data = value;
        next = NULL;
        prev = NULL;
      }

};


template<class T>

class DoublyLinkedList{

    public:
       Node<T>* Head;
       Node<T>* Tail;
       int Size_;

    DoublyLinkedList()
    {
       Head = NULL;
       Tail = NULL;
       Size_ = 0;

    }

   void Push_back(T val); //append
   void Pop_back();
   void Push_front(T val); //prepend
   void Pop_front();
   void Display();
   void Clear();
   void Insert_at(T val,int position);
   void Delete_at(int position);
   void Add_before(Node<T>* node, T val);
   void Add_after(Node<T>* node,T val);

   ~DoublyLinkedList()
   {
     cout<<"destructor is called"<<'\n';
     Clear();
   }

};
