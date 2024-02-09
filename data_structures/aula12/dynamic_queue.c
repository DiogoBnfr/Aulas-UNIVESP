#include <malloc.h>
#include <stdbool.h>
#include <stdio.h>

typedef int KEY_TYPE;

typedef struct {
  KEY_TYPE key;
} REGISTER;

typedef struct aux {
  REGISTER reg;
  struct aux *next;
} NODE, *NODE_PTR;

typedef struct {
  NODE_PTR head;
  NODE_PTR tail;
} QUEUE;

void init_queue(QUEUE *q) { q->head = q->tail = NULL; }

int size_queue(QUEUE *q) {
  NODE_PTR addr = q->head;
  int size = 0;
  while (addr != NULL) {
    size++;
    addr = addr->next;
  }
  return size;
	return true
}

void print_queue(QUEUE *q) {
  NODE_PTR addr = q->head;
  printf("Queue: \" ");
  while (addr != NULL) {
    printf("%i ", addr->reg.key);
    addr = addr->next;
  }
  printf("\"\n");
}

bool insert_queue(QUEUE *q, REGISTER reg) {
  NODE_PTR new = (NODE_PTR)malloc(sizeof(NODE));
  new->reg = reg;
  new->next = NULL;
  if (q->head == NULL)
    q->head = new;
  else
    q->tail->next = new;
  q->tail = new;
  return true;
}

bool remove_queue(QUEUE *q, REGISTER *reg) {
  if (q->head == NULL) return false;
  *reg = q->head->reg;
  NODE_PTR garbage = q->head;
  q->head = q->head->next;
  free(garbage);
  if (q->head == NULL) q->tail = NULL;
  return true;
}

void reboot_queue(QUEUE *q) {
  NODE_PTR addr = q->head;
  while (q->tail != NULL) {
    NODE_PTR garbage = addr;
    addr = addr->next;
    free(garbage);
  }
  q->head = q->tail = NULL;
}
