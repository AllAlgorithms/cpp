#include <stdio.h>

#define size 100

struct queue
{
  int front,rear;
  int arr[size];
};

typedef struct queue QUEUE;

void insert(QUEUE *q, int x, int rev)
{
  if(q->rear == size -1 || (q->front == 0 && rev != 0) )
  {
    printf("Over flow\n");
    return;
  }
  if(rev == 0) q->arr[++q->rear]=x;
  else q->arr[--q->front]=x;
}

int delete(QUEUE *q, int rev)
{
  if(q->rear < q->front)
  {
    printf("Under flow\n");
    return -1;
  }
  return (rev == 0 ? q->arr[q->front++] : q->arr[q->rear--]);
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
  int ch,t;
  while(1)
  {
    system("clear");
    printf("1. Insert an element into the double ended queue.\n");
    printf("2. Delete an element from the double ended queue.\n");
    printf("3. Display the contents of the double ended queue.\n");
    printf("4. Quit\n");
    scanf("%d",&ch);
    switch(ch)
    {
      case 1: printf("Enter a element: ");
	      scanf("%d",&ch);
	      printf("Enter 0 to insert at rear and 1 to insert at front\n");
              scanf("%d",&t);
	      insert(&q,ch,t);
	break;
      case 2: printf("Enter 0 to dequeue at front and 1 to dequeue at rear\n");
       	      scanf("%d",&t);
	      ch = delete(&q,t);
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
