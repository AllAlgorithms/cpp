#include <stdio.h>

#define size 100

struct queue
{
  int front,rear;
  int arr[size];
};

typedef struct queue QUEUE;

void swap(int *a,int *b)
{
  int t;
  t=*a;
  *a=*b;
  *b=t;
}

void insert(QUEUE *q, int x)
{
  if(++q->rear == size)
  {
    q->rear--;
    printf("Over flow\n");
    return;
  }
  q->arr[q->rear] = x;
  int i,j;
  for(i=q->front;i<=q->rear;i++)
  {
    for(j=i+1;j<=q->rear;j++)
    {
      if(q->arr[i]<q->arr[j])
	swap(&q->arr[i],&q->arr[j]);
    }
  }
}

int delete(QUEUE *q)
{
  if(q->rear < q->front)
  {
    printf("Under flow\n");
    return -1;
  }
  return q->arr[q->front++];  
} 

void display(QUEUE q)
{
  int i;
  for(i=q.front; i <= q.rear;i++)
  {
    printf("%d\n",q.arr[i]);
  }
}

int main()
{
  QUEUE q;
  q.rear = -1;
  q.front = 0;
  q.arr[0] = -1;
  int ch;
  while(1)
  {
    system("clear");
    printf("1. Insert an element into the priority queue.\n");
    printf("2. Delete an element from the priority queue.\n");
    printf("3. Display the contents of the priority queue.\n");
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
