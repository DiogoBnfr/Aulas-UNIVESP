#include <stdbool.h>
#include <stdio.h>

#define MAX 50

typedef int KEY_TYPE;

typedef struct {
  KEY_TYPE key;
} REGISTER;

typedef struct {
  REGISTER data[MAX];
  int head;
  int size;
} QUEUE;

void init_queue(QUEUE* q) {
  q->head = 0;
  q->size = 0;
}

int size_queue(QUEUE* q) { return q->size; }

void print_queue(QUEUE* q) {
  printf("Queue: \" ");
  int i = q->head;
  for (int temp = 0; temp < q->size; temp++) {
    printf("%i ", q->data[i].key);
    i = (i + 1) % MAX;  // if i == MAX then return to 0;
  }
  printf("\"\n");
}

bool insert_queue(QUEUE* q, REGISTER reg) {
  if (q->size >= MAX) return false;
  int index = (q->head + q->size) % MAX;
  q->data[index] = reg;
  q->size++;
  return true;
}

bool remove_queue(QUEUE* q, REGISTER* reg) {
  if (q->size == 0) return false;
  *reg = q->data[q->head];
  q->head = (q->head + 1) % MAX;
  q->size--;
  return true;
}

void reboot_queue(QUEUE* q) { init_queue(q); }