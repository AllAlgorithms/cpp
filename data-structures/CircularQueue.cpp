#include <stdio.h>

#define size 5

struct queue
{
  int front,rear,ins,nos;
  int arr[size];
};

typedef struct queue QUEUE;

void insert(QUEUE *q, int x)
{
  int t;
  t = q->rear + 1;
  if(t==size)
    t=0;
  if(t == q->front && q->ins == 1)
  {
    printf("Over flow\n");
    return;
  }
  q->rear++;
  if(q->rear == size)
    q->rear = 0;
  q->arr[q->rear]=x; 
  q->ins = 1;
  q->nos++;
}

int delete(QUEUE *q)
{
  int t;
  t = q->rear + 1;
  if(t==size)
    t=0;
  if(t == q->front && q->ins == 0)
  {
    printf("Under flow\n");
    return -1;
  }
  q->front++;
  if(q->front == size)
    q->front=0;
  q->ins = 0;
  q->nos--;
  return q->arr[q->front-1];  
} 

void display(QUEUE q)
{
  int i,j;
  for(j=0,i=q.front;j<q.nos;i++,j++)
  {
    if(i==size) i=0;
    printf("%d\n",q.arr[i]);
  }
}

int main()
{
  QUEUE q;
  q.rear = size-1;
  q.front = 0;
  q.ins = 0;
  q.nos = 0;
  int ch;
  while(1)
  {
    system("clear");
    printf("1. Insert an element into the circular queue.\n");
    printf("2. Delete an element from the circular queue.\n");
    printf("3. Display the contents of the circular queue.\n");
    printf("4. Quit\n");
    scanf("%d",&ch);
    switch(ch)
    {
      case 1: printf("Enter a element: ");
	      scanf("%d",&ch);
	      insert(&q,ch);
	break;
      case 2: ch = delete(&q);
	      if(ch != -1)
		printf("The removed element is: %d\n",ch);
        break;
      case 3: printf("Queue is: \n");
              display(q);
        break;
      case 4: printf("Bye..\n");
              return 0;
        break;
      default: printf("Wrong Input");
        break;
    }
    system("read -p \"Press Enter to continue\" </dev/tty");
  }
  return 0;
}
