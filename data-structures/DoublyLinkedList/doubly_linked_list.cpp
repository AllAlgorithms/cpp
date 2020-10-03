#include"doubly_linked_list.h"

template<class T>
void DoublyLinkedList<T> :: Push_back(T val)
{

   Node<T>* new_node  = new Node<T>(val);

   if(Tail != NULL) //or if(Size != 0)
   {
       Tail->next = new_node;
       new_node->prev = Tail;
       Tail = new_node;

   }
   else
   {
      Tail = new_node;
      Head = new_node;
   }

  Size_++;
}


template<class T>
void DoublyLinkedList<T> :: Pop_back()
{
    //if list is empty
   if(Tail == NULL) //or Head == NULL
   {
      cout<<"Can't pop back the DLS is empty"<<'\n';
      return;
   }

  if(Tail == Head) // if there's only one element in the DLS
   {
      delete Tail;
      Tail = NULL;
      Head = NULL;

   }
   else
   {
      Node<T>* previous_node = Tail->prev;

      delete Tail;

      Tail = previous_node;
      Tail->next = NULL;
   }

 Size_--;

}

template <class T>
void DoublyLinkedList<T> :: Push_front(T val)
{

  Node<T>* new_node = new Node<T>(val);

  new_node->next = Head;
  if(Head != NULL)
  {
      Head->prev = new_node;

  }
  Head = new_node;
  if(Tail == NULL)
  {
     Tail = Head;
  }

 Size_++;

}

template<class T>
void DoublyLinkedList<T> :: Pop_front()
{
  if(Head == NULL) //if dls is empty can't pop
  {
     cout<<"Can't pop front the DLS is empty"<<'\n';
     return;
  }

  Node<T>* next_node = Head->next;
  delete Head;
  Head = next_node;

  if(Head == NULL) //if we popped the last element
  {
   Tail = NULL;
  }
  else
  {
     Head->prev = NULL;
  }

Size_--;

}

template<class T>
void DoublyLinkedList<T> :: Add_before(Node<T>* node, T val)
{

     Node<T>* new_node = new Node<T>(val);
     new_node->next = node;
     new_node->prev = node->prev;
     node->prev = new_node;

     if(new_node->prev != NULL)
     {
         new_node->prev->next = new_node;
     }

     if(Head == node)
     {
       Head = new_node;

     }
  Size_++;
}



template <class T>
void DoublyLinkedList<T> :: Add_after(Node<T>* node,T val)
{

   Node<T>* new_node = new Node<T>(val);
   new_node->prev = node;
   new_node->next = node->next;
   node->next = new_node;


   if(new_node->next != NULL)
   {
       new_node->next->prev = new_node;

   }

   if(Tail == node)
   {
      Tail = new_node;
   }

Size_++;

}

template <class T>
void DoublyLinkedList<T> :: Display()
{

     if(Size_ == 0)
     {
       cout<<"Linked List is empty";
     }
     else
     {
        for(Node<T>* tmp_ptr = Head;tmp_ptr!= NULL; tmp_ptr= tmp_ptr->next)
        {
             cout<<tmp_ptr->data<<" ";

        }
     }
cout<<'\n';
}



template<class T>
void DoublyLinkedList<T> :: Clear()
{

    Node<T>* tmp = Head;
    if(Size_ == 0 )
    {
         cout<<" all cleared linked list is empty"<<'\n';
         return;
    }

    while(Head != NULL)
    {

         Head = Head->next;
         delete tmp;
         tmp = Head;

    }
  cout<<" all cleared linked list is empty"<<'\n';
Tail = NULL;
Size_ = 0;
}
template <class T>
void DoublyLinkedList<T> :: Insert_at(T val ,int position)
{
  if(position >Size_ || position <= 0)
    {
       cout<<"invalid position choose a position between 1 and size "<<'\n';
       cout<<"size is: "<<Size_<<'\n';

    }
 else
 {
       Node<T>* tmp = Head;
      //get a pointer of that position that position
      for(int i =1 ; i<=position-1 ; i++,tmp = tmp->next);
      Add_before(tmp,val);
 }


 }

template<class T>
void DoublyLinkedList<T> :: Delete_at(int position)
{


  if(Size_ ==0)
  {
      cout<<"Can't delete DLS is empty "<<'\n';
      return;
  }

  if(position >Size_ || position < 0)
    {
       cout<<"invalid position choose a position between 1 and size "<<'\n';
       cout<<"size is: "<<Size_<<'\n';
       return;

    }


   //general deletion of nodes in DLS
      Node<T>* tmp = Head;

      for(int i = 1; i <= position-1; i++,tmp = tmp->next);

       if(tmp->next != NULL)
       {
           tmp->next->prev = tmp->prev;
       }

       if(tmp->prev != NULL)
       {
            tmp->prev->next = tmp->next;

       }

       if(Head == tmp)
       {
         Head = tmp->next;

       }

       if(Tail == tmp)
       {
          Tail = Tail->prev;
       }

delete tmp;
Size_--;


}



