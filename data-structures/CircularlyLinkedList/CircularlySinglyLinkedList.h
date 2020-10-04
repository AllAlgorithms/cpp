#include<iostream>

using namespace std;


template<class T>
class Node
{
  public:
   T data;

   Node<T>* next;


   Node()
   {
       next = NULL;
   }

   Node(T val)
   {
      data = val;
      next = NULL;
   }




};

template<class T>
class CircularlySinglyLinkedList
{
   public:

      Node<T>* Tail;
      int Size_;

      CircularlySinglyLinkedList()
      {
          Size_ = 0;
          Tail = NULL;

      }
   void Push_front(T val);
   void Pop_front();
   void Push_back(T val);
   void Pop_back();
   void Display();
   void Clear();
   void Insert_at(T val,int position,string afterOrbefore_flag); // has generalized code for add before node and add after node
   void Delete_at(int position);

   void Add_to_empty_list(T val);

  ~CircularlySinglyLinkedList()
  {
     Clear();
  }


};
