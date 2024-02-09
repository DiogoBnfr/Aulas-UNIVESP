#include <stdbool.h>
#include <stdio.h>

#define MAX 50
#define INVALID -1

typedef int KEY_TYPE;

typedef struct {
  KEY_TYPE key;
} REGISTER;

typedef struct {
  REGISTER reg;
  int next;
} NODE;

typedef struct {
  NODE data[MAX];
  int head;
  int tail;
} LIST;

void initialize_list(LIST *l) {
  for (int i = 0; i < MAX - 1; i++) {
    l->data[i].next = i + 1;
  }
  l->data[MAX - 1].next = INVALID;
  l->head = INVALID;  // points to -1 because the list is empty
  l->tail = 0;
}

int size_list(LIST *l) {
  int i = l->head;
  while (l->data[i].reg.key != INVALID) i++;
  return i;
}

void print_list(LIST *l) {
  int i = l->head;
  printf("List: [ ");
  while (i != INVALID) {
    printf("%i ", l->data[i].reg.key);
    i = l->data[i].next;
  }
  printf("]\n");
}

int search_list(LIST *l, KEY_TYPE key) {
  int i = l->head;
  while (i != INVALID && l->data[i].reg.key < key) {
    i = l->data[i].next;
  }
  if (i != INVALID && l->data[i].reg.key == key)
    return i;
  else
    return INVALID;
}

int return_node(LIST *l) {
  int result = l->tail;
  if (l->tail != INVALID) {
    l->tail = l->data[l->tail].next;
  }
  return result;
}

bool ordened_insert_list(LIST *l, REGISTER reg) {
  if (l->tail == INVALID) return false;
  int previous = INVALID;
  int i = l->head;
  KEY_TYPE key = reg.key;
  while (i != INVALID && l->data[i].reg.key < key) {
    previous = i;
    i = l->data[i].next;
  }
  if (i != INVALID && l->data[i].reg.key == key) return false;
  i = return_node(l);
  l->data[i].reg = reg;
  if (previous == INVALID) {
    l->data[i].next = l->head;
    l->head = i;
  } else {
    l->data[i].next = l->data[previous].next;
    l->data[previous].next = i;
  }
  return true;
}

void free_node(LIST *l, int j) {
  l->data[j].next = l->tail;
  l->tail = j;
}

bool delete_node_list(LIST *l, KEY_TYPE key) {
  int previous = INVALID;
  int i = l->head;
  while (i != INVALID && l->data[i].reg.key < key) {
    previous = i;
    i = l->data[i].next;
  }
  if (i == INVALID || l->data[i].reg.key != key) return false;
  if (previous == INVALID)
    l->head = l->data[i].next;
  else
    l->data[previous].next = l->data[i].next;
  free_node(l, i);
  return true;
}

void restart_list(LIST *l) { initialize_list(l); }

int main(void) {
  LIST l;
  initialize_list(&l);
  print_list(&l);
  printf("List size: %d\n", size_list(&l));

  REGISTER reg;
  reg.key = 10;
  ordened_insert_list(&l, reg);
  reg.key = 20;
  ordened_insert_list(&l, reg);
  reg.key = 30;
  ordened_insert_list(&l, reg);

  print_list(&l);
  print_list(&l);

  return 0;
}
