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
    
    
    
    
    // Another way of writing queue data structure in C++
    // remove comments to run program 
/*    class Queue { 
public: 
    int front, rear, size; 
    unsigned capacity; 
    int* array; 
}; 
  
// function to create a queue 
// of given capacity. 
// It initializes size of queue as 0 
Queue* createQueue(unsigned capacity) 
{ 
    Queue* queue = new Queue(); 
    queue->capacity = capacity; 
    queue->front = queue->size = 0; 
  
    // This is important, see the enqueue 
    queue->rear = capacity - 1; 
    queue->array = new int[( 
        queue->capacity * sizeof(int))]; 
    return queue; 
} 
  
// Queue is full when size 
// becomes equal to the capacity 
int isFull(Queue* queue) 
{ 
    return (queue->size == queue->capacity); 
} 
  
// Queue is empty when size is 0 
int isEmpty(Queue* queue) 
{ 
    return (queue->size == 0); 
} 
  
// Function to add an item to the queue. 
// It changes rear and size 
void enqueue(Queue* queue, int item) 
{ 
    if (isFull(queue)) 
        return; 
    queue->rear = (queue->rear + 1) 
                  % queue->capacity; 
    queue->array[queue->rear] = item; 
    queue->size = queue->size + 1; 
    cout << item << " enqueued to queue\n"; 
} 
  
// Function to remove an item from queue. 
// It changes front and size 
int dequeue(Queue* queue) 
{ 
    if (isEmpty(queue)) 
        return INT_MIN; 
    int item = queue->array[queue->front]; 
    queue->front = (queue->front + 1) 
                   % queue->capacity; 
    queue->size = queue->size - 1; 
    return item; 
} 
  
// Function to get front of queue 
int front(Queue* queue) 
{ 
    if (isEmpty(queue)) 
        return INT_MIN; 
    return queue->array[queue->front]; 
} 
  
// Function to get rear of queue 
int rear(Queue* queue) 
{ 
    if (isEmpty(queue)) 
        return INT_MIN; 
    return queue->array[queue->rear]; 
} 
  
// Driver code 
int main() 
{ 
    Queue* queue = createQueue(1000); 
  
    enqueue(queue, 10); 
    enqueue(queue, 20); 
    enqueue(queue, 30); 
    enqueue(queue, 40); 
  
    cout << dequeue(queue) 
         << " dequeued from queue\n"; 
  
    cout << "Front item is "
         << front(queue) << endl; 
    cout << "Rear item is "
         << rear(queue) << endl; 
  
    return 0; 
} 
*/
  return 0;
}
