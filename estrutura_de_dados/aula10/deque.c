#include <malloc.h>
#include <stdbool.h>
#include <stdio.h>

typedef int KEY_TYPE;

typedef struct {
  KEY_TYPE key;
} REGISTER;

typedef struct aux {
  REGISTER reg;
  struct aux* prev;
  struct aux* next;
} NODE;

typedef struct {
  NODE* head;
} DEQUE;

void init_deque(DEQUE* d) {
  d->head = (NODE*)malloc(sizeof(NODE));
  d->head->prev = d->head;
  d->head->next = d->head;
}

// from start to the end
int size_deck_start(DEQUE* d) {
  NODE* addr = d->head->next;
  int size = 0;
  while (addr != d->head) {
    size++;
    addr = addr->next;
  }
  return size;
}

// from end to the start
int size_deck_end(DEQUE* d) {
  NODE* addr = d->head->prev;
  int size = 0;
  while (addr != d->head) {
    size++;
    addr = addr->prev;
  }
  return size;
}

void print_deque_start(DEQUE* d) {
  NODE* addr = d->head->next;
  printf("[ ");
  while (addr != d->head) {
    printf("%i ", addr->reg.key);
    addr = addr->next;
  }
  printf("]");
}

void print_deque_end(DEQUE* d) {
  NODE* addr = d->head->prev;
  printf("[ ");
  while (addr != d->head) {
    printf("%i ", addr->reg.key);
    addr = addr->prev;
  }
  printf("]");
}

bool insert_start(DEQUE* d, REGISTER reg) {
  NODE* new = (NODE*)malloc(sizeof(NODE));
  new->reg = reg;
  new->next = d->head->next;
  new->prev = d->head;
  d->head->next = new;
  new->next->prev = new;
  return true;
}

bool insert_end(DEQUE* d, REGISTER reg) {
  NODE* new = (NODE*)malloc(sizeof(NODE));
  new->reg = reg;
  new->next = d->head;
  new->prev = d->head->prev;
  d->head->prev = new;
  new->prev->next = new;
  return true;
}

bool remove_start(DEQUE* d, REGISTER* reg) {
  if (d->head->next == d->head) return false;
  NODE* garbage = d->head->next;
  *reg = garbage->reg;  // return the register to be removed
  d->head->next = garbage->next;
  garbage->next->prev = d->head;
  free(garbage);
  return true;
}

bool remove_end(DEQUE* d, REGISTER* reg) {
  if (d->head->prev == d->head) return false;
  NODE* garbage = d->head->prev;
  *reg = garbage->reg;
  d->head->prev = garbage->prev;
  garbage->prev = d->head;
  free(garbage);
  return true;
}

void reboot_deque(DEQUE* d) {
  NODE* addr = d->head->next;
  while (addr != d->head) {
    NODE* garbage = addr;
    addr = addr->next;
    free(garbage);
  }
  d->head->next = d->head;
  d->head->prev = d->head;
}