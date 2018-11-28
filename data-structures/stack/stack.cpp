//
//  A Stack is an abstract data type that serves as a collection
// of elements, with two principal operations are push & pop
//
// The All ▲lgorithms Project
//
// https://allalgorithms.com/data-scructures/
// https://github.com/allalgorithms/cpp
//
// Contributed by: ANUJ MODI
// Github: @descifrado
//
#include<stdio.h>
#define max 50
struct stack
{
	int ch[max];
	int top;
};
typedef struct stack Stack;
void push(Stack *s, int x)
{
	if(s->top==max-1)
		printf("ERROR: Stack Overflow\n");
	else
		s->ch[++s->top]=x;
}
int pop(Stack *s)
{
	if(s->top==-1)
	{
		printf("ERROR: Stack Underflow\n");
	}
	else
		return (s->ch[s->top--]);
}
int main()
{
	printf("Stack Has Been Initiated...\n");
	Stack s;
	s.top=-1;
	int c;
	while(1)
	{
		printf("\nEnter 1 to push an element\nEnter 2 to pop an element\nEnter 3 to display all the content of stack\nEnter 0 to exit\n");
		scanf("%d",&c);
		switch(c)
		{
			case 0: return 0;
			case 1:
			{
				printf("Enter element to be pushed\n");
				int x;
				scanf("%d",&x);
				push(&s,x);
				printf("Element successfully pushed\n");
				break;
			}
			case 2:
			{
				printf("Poped Element Is %d\n",pop(&s));
				break;
			}
			case 3:
			{
				printf("Stack has the following content in order LIFO\n");
				int i;
				for(i=s.top;i>=0;i--)
				{
					printf("%d ",s.ch[i]);
				}
				break;
			}
			default:
			{
				printf("Wrong Choice\n");
			}
		}
	}
}
