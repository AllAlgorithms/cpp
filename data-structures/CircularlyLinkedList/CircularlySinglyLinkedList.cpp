
#include"CircularlySinglyLinkedList.h"



template<class T>
void CircularlySinglyLinkedList<T> :: Add_to_empty_list(T val)
{
        Node<T>* new_node = new Node<T>(val);

        Tail = new_node;
        Tail->next = new_node;

Size_++;
}


template<class T>
void CircularlySinglyLinkedList<T> ::Push_back( T val)
{
        if(Tail == NULL)
        {
          Add_to_empty_list(val);

        }
        else
        {
           Node<T>* new_node = new Node<T>(val);
           new_node->next = Tail->next;
           Tail->next = new_node;
           Tail= new_node;
           Size_++;
        }
}

template<class T>
void CircularlySinglyLinkedList<T> :: Clear()
{

      if(Size_ == 0 )
    {
         cout<<" all cleared linked list is empty"<<'\n';
    }
    else
    {
        Node<T>* tmp1 = Tail->next;
        Node<T>* tmp2 = tmp1;

         while(tmp1 != Tail)
         {
             tmp1 = tmp1->next;
             //free the memory of the node to delete it
             delete tmp2;
             tmp2=tmp1;
         }
         // after the loop we make Tail point to NULL because it points
         //to a deleted location in the memory (dangling pointer)
         delete Tail;
         tmp1 = NULL;
         tmp2 = NULL;
         Tail = NULL;
        Size_ = 0;
    }

}
template<class T>

void CircularlySinglyLinkedList<T> :: Display()
{
      if(Size_ == 0)
      {
        cout<<"List is empty"<<'\n';
        return;
      }
      Node<T>* tmp = Tail->next; //Head

      do
      {
         cout<<tmp->data<<" ";
         tmp = tmp->next;


      }
      while(tmp != Tail->next);



  cout<<'\n';
}
template<class T>
void CircularlySinglyLinkedList<T> :: Pop_back()
{
   if( Size_ == 0)
   {
      cout<<"Can't pop back. list is empty"<<'\n';
      return;

   }

   if(Size_ == 1)
   {
      delete Tail;
      Tail = NULL;


   }
   else
   {
       Node<T>* tmp = Tail->next;


       while(tmp->next != Tail)
       {
          tmp = tmp->next;
       }

       tmp->next = Tail->next;
       delete Tail;
       Tail = tmp;
   }

Size_--;
}


template<class T>
void CircularlySinglyLinkedList<T> :: Push_front(T val)
{
        if(Tail == NULL)
        {
          Add_to_empty_list(val);

        }
        else
        {
           Node<T>* new_node = new Node<T>(val);
           new_node->next = Tail->next;
           Tail->next = new_node;
           Size_++;
        }

}

template<class T>
void CircularlySinglyLinkedList<T> :: Pop_front()
{

  if(Size_ == 0)
  {
    cout<<"Can't pop front. List is empty "<<'\n';
    return;
  }


  if( Size_ == 1)
  {
     delete Tail;
     Tail = NULL;


  }
  else
  {

     Node<T>* tmp = Tail->next;
     Tail->next = Tail->next->next;
     delete tmp;

  }

Size_--;

}

template<class T>
void CircularlySinglyLinkedList<T> :: Insert_at(T val, int position,string afterOrbefore_flag)
{


    if(Size_ == 0)
    {
        cout<<"no existing nodes.Linked list is empty. ";
        return;
    }

    if(position >Size_ || position < 0)
    {
       cout<<"invalid position choose a position between 1 and size "<<'\n';
       cout<<"size is: "<<Size_<<'\n';
       return;

    }



    Node<T>* tmp;
    if(afterOrbefore_flag == "before")
    {

     if(position == 1)
     {
         Push_front(val);
         return;

     }
     else
     {
       tmp=Tail->next;
      for(int i = 1 ; i <position -1 ; i++,tmp = tmp->next);

     }


    }
    else if(afterOrbefore_flag == "after")
    {

          if(position == Size_)
          {
              Push_back(val);
              return;

          }
          else
          {
            tmp=Tail->next;
            for( int i = 1 ; i <position ; i++ ,tmp = tmp->next);

          }

    }

   Node<T>* new_node = new Node<T>(val);
   new_node->next = tmp->next;
   tmp->next = new_node;
   Size_++;

}
template<class T>

void CircularlySinglyLinkedList<T> :: Delete_at(int position)
{
    if(Size_ == 0)
    {
        cout<<"no existing nodes.Linked list is empty. ";
        return;
    }

    if(position >Size_ || position < 0)
    {
       cout<<"invalid position choose a position between 1 and size "<<'\n';
       cout<<"size is: "<<Size_<<'\n';
       return;

    }


    if(position == Size_)
    {
        Pop_back();
    }

    else if(position == 1)
    {
       Pop_front();
    }
    else
    {

        Node<T>* tmp = Tail->next;

       for(int i = 1 ; i < position-1; i++,tmp = tmp->next);

        Node<T>* node = tmp->next;

        tmp->next = node->next;

        delete node;


    Size_--;

    }


}
