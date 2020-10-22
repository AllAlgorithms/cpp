#include <cstdio>
#include <iostream>
#define MAX 30
using namespace std;

struct Dequeue
{
	int data[MAX];
	int rear,front;
};

void initialize(Dequeue *p);
int empty(Dequeue *p);
int full(Dequeue *p);
void enqueueR(Dequeue *p, int x);
void enqueueF(Dequeue *p, int x);
int dequeueF(Dequeue *p);
int dequeueR(Dequeue *p);
void print(Dequeue *p);

int main()
{
	int i, x, op, n;
	Dequeue q;

	initialize(&q);

	do
	{
		printf("\n1.Create\n2.Insert(rear)\n3.Insert(front)\n4.Delete(rear)\n5.Delete(front)");
		printf("\n6.Print\n7.Exit\n\nEnter your choice:");
		scanf("%d", &op);

		switch(op)
		{
			case 1: printf("\nEnter number of elements:");
					scanf("%d", &n);
					initialize(&q);
					printf("\nEnter the data:");

					for(i=0; i<n; i++)
					{
						scanf("%d", &x);
						if(full(&q))
						{
							printf("\nQueue is full!!");
							exit(0);
						}
						enqueueR(&q, x);
					}
					break;

			case 2: printf("\nEnter element to be inserted:");
					scanf("%d", &x);

					if(full(&q))
					{
						printf("\nQueue is full!!");
						exit(0);
					}

					enqueueR(&q, x);
					break;

			case 3: printf("\nEnter the element to be inserted:");
					scanf("%d", &x);

					if(full(&q))
					{
						printf("\nQueue is full!!");
						exit(0);
					}

					enqueueF(&q, x);
					break;

			case 4: if(empty(&q))
					{
						printf("\nQueue is empty!!");
						exit(0);
					}

					x=dequeueR(&q);
					printf("\nElement deleted is %d\n",x);
					break;

			case 5: if(empty(&q))
					{
						printf("\nQueue is empty!!");
						exit(0);
					}

					x=dequeueF(&q);
					printf("\nElement deleted is %d\n",x);
					break;

			case 6: print(&q);
					break;

			default: break;
		}
	} while(op!=7);
}

void initialize(Dequeue* P)
{
	P->rear=-1;
	P->front=-1;
}

int empty(Dequeue* P)
{
	if(P->rear==-1)
		return(1);

	return(0);
}

int full(Dequeue* P)
{
	if((P->rear+1)%MAX == P->front)
		return(1);

	return(0);
}

void enqueueR(Dequeue* P,int x)
{
	if(empty(P))
	{
		P->rear=0;
		P->front=0;
		P->data[0]=x;
	}
	else
	{
		P->rear=(P->rear+1)%MAX;
		P->data[P->rear]=x;
	}
}

void enqueueF(Dequeue* P,int x)
{
	if(empty(P))
	{
		P->rear=0;
		P->front=0;
		P->data[0]=x;
	}
	else
	{
		P->front=(P->front-1+MAX)%MAX;
		P->data[P->front]=x;
	}
}

int dequeueF(Dequeue* P)
{
	int x;

	x=P->data[P->front];

	if(P->rear==P->front)	//delete the last element
		initialize(P);
	else
		P->front=(P->front+1)%MAX;

	return(x);
}

int dequeueR(Dequeue* P)
{
	int x;

	x=P->data[P->rear];

	if(P->rear==P->front)
		initialize(P);
	else
		P->rear=(P->rear-1+MAX)%MAX;

	return(x);
}

void print(Dequeue* P)
{
	if(empty(P))
	{
		printf("\nQueue is empty.");
		exit(0);
	}

	int i;
	i=P->front;

	while(i!=P->rear)
	{
		printf("\n%d",P->data[i]);
		i=(i+1)%MAX;
	}

	printf("\n%d\n",P->data[P->rear]);
}
