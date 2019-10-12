//Stack is a data structure based on a last in first out (LIFO) method
//This code defines and implements stack's functions using linked list


#include<stdio.h>
#include<stdlib.h>
void pop();
void push();
void display();
struct node{
  int value;
  struct node *link;
  }*top=NULL;

void main(){
  int choice;
  do{
  printf("*****Menu*****");
  printf("\n1.Push\n2.Pop\n3.Display\n4.Exit");
  printf("\nEnter you choice number::\t");
  scanf("%d",&choice");
  switch(choice){
        case 1: push();
                break;
        case 2: pop();
                break;
        case 3: display();
                break;
        case 4: exit(0);
        default:printf("\nWrong choice, Try entering again");
        }
    }while(1);
    getch();
    }

 void push(){
      int n;
      ptr=(struct node *)malloc(sizeof(struct node));
      if (!ptr)
          {
          printf("\nMemory Overflow");
          return;
          }

      printf("\nEnter the number to be pushed");
      scanf("%d",n);
      ptr->value=n;
      top->link=ptr;
      top=ptr;
      printf("\nElement pushed Successfully");
      }
void pop(){
     struct node *ptr=top;
     if(!top)
          {
          printf("\nMemory Underflow");
          return;
          }
     top=top->link;
     free(ptr);
     printf("\nElement popped succefully");
     }
 void display(){
       struct node *ptr=top;
       printf("\n");
       if(!top)
             {
             printf("The stack is Empty");
             return;
             }
       while(!ptr)
              {
              printf("\t%d",ptr->value");
              ptr=ptr->link;
              }
       }



