#include<iostream>
#include<conio.h>

typedef struct node
{int data;
struct node* next=NULL;
}n;

n* temp=NULL;
n* head=NULL;
n* newn=NULL;

void linked_list(int d)
{
 newn->data=d;
 if(head==NULL)
 {head=newn;
 temp=head;
 }
 else
 {temp->next=newn;
  temp=newn;
 }
}
