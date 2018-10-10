#include <stdbool.h>
#include <stdlib.h>

// Tipo dos elementos na fila de prioridades.
typedef float Type;

// Tipo de dado priority_queue (fila de prioridade).
// Para garantir o ecapsulamento, 'struct priority_queue_t' só é definido em priority_queue.c.
typedef struct priority_queue_t* priority_queue;

// Cria uma fila vazia.
priority_queue new_priority_queue();

// Testa se a fila está vazia.
bool empty(priority_queue q);

// Retorna o número de elementos na fila.
int size(priority_queue q);

// Retorna o menor elemento da fila.
// Precondição: a fila não pode estar vazia.
Type top(priority_queue q);

// Insere k na fila.
void push(Type k, priority_queue q);

// Remove o menor elemento da fila.
// Precondição: a fila não pode estar vazia.
void pop(priority_queue q);

// Faz a fila p ter os mesmos elementos que a fila q.
void copy(priority_queue q, priority_queue p);

// Troca o conteúdo da fila p com o da fila q.
void swap(priority_queue q, priority_queue p);

// Libera a memória alocada para a fila.
void delete_priority_queue(priority_queue q);
// Os elementos da fila estão distribuídos do maior para o menor no vetor,
// ou seja, o maior elemento está necessariamente no índice 0 do vetor.
struct priority_queue_t{
  Type* array;  // Vetor que contém os elementos da fila.
  int capacity; // Número de elementos alocados no vetor array.
  int size;  // Número de elementos na fila.
};

void reserve(int m, priority_queue q) {
  if (m > q->capacity) {
    q->capacity = m;
    Type* aux = malloc(sizeof(struct priority_queue_t) * q->capacity);
    for (int i = 0; i < q->size; i++) {
      aux[i] = q->array[i];
    }
    free(q->array);
    q->array = aux;
  }
}
priority_queue new_priority_queue() {
  priority_queue q = malloc(sizeof(struct priority_queue_t));
  q->size = 0;
  q->capacity = 16;
  q->array = malloc(sizeof(Type) * q->capacity);
  return q;
}

bool empty(priority_queue q) {
  return q->size == 0;
}

int size(priority_queue q) {
  return q->size;
}

Type top(priority_queue q) {
  return q->array[q->size - 1];
}

void push(Type k, priority_queue q) {
  if (q->size == q->capacity) {
    reserve(2 * q->capacity, q);
  }
  int i;
  for (i = q->size; i > 0 && q->array[i - 1] <= k; i--) {
    q->array[i] = q->array[i - 1];
  }
  q->array[i] = k;
  q->size++;
}

void pop(priority_queue q) {
  q->size--;
}

void copy(priority_queue q, priority_queue p) {
  reserve(q->capacity, p);
  p->size = q->size;
  for (int i = 0; i < q->size; i++) {
    p->array[i] = q->array[i];
  }
}

void swap(priority_queue q, priority_queue p) {
  struct priority_queue_t aux = *p;
  *p = *q;
  *q = aux;
}

void delete_priority_queue(priority_queue q) {
  free(q->array);
  free(q);
}
