//
// Queue: the entities in the collection are kept in
// order and the principal (or only) operations on the
// collection are the addition of entities to the rear
// terminal position
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
#define qsize 5
struct queue
{
  int arr[qsize];
  int f, r;
};
typedef struct queue Queue;
void
enqueue (Queue * q, int x)
{
  if (q->r == qsize - 1)
    printf ("QUEUE OVERFLOW\n");
  else
    q->arr[++q->r] = x;
}

int
dequeue (Queue * q)
{
  if (q->f - q->r == 1)
    printf ("Queue Underflow");
  else
    return (q->arr[q->f++]);
}

int
main ()
{
  Queue q;
  q.f = 0;
  q.r = -1;
  while (1)
	{
      printf("Enter 1 to Enqueue\nEnter 2 to Dequeue\nEnter 3 to Display All Elements\nEnter 0 to Exit\n");
      int c;
      scanf ("%d", &c);
      switch (c)
	{
	case 0:
	  printf("Ended\n");
	  return 0;
	case 1:
	  printf ("Enter Element to Enqueue\n");
	  int x;
	  scanf ("%d", &x);
	  enqueue (&q, x);
	  break;
	case 2:
	  if (q.f - q.r == 1)
	    printf ("Queue Undeflow\n");
	  else
	    printf ("Dequeued Element is %d\n", dequeue (&q));
	  break;
	case 3:
	  printf ("Elements of Queue Are\n");
	  if (q.f - q.r == 1)
	    {
	      printf ("Queue is Empty\n");
	      break;
	    }
	  int i;
	  for (i = q.f; i <= q.r; i++)
	    printf ("%d ", q.arr[i]);
	  printf ("\n");
	  break;
	default:
	  printf ("Wrong Choice\n");
	}
    }
  return 0;
}
