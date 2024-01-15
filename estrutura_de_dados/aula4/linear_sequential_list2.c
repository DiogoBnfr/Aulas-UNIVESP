#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#define MAX 50

typedef int key_type;

typedef struct {
  key_type key;
} _register;

typedef struct {
  _register data[MAX];
  int size;
} list;

void create_list(list *l) { l->size = 0; }

int size_list(list *l) { return l->size; }

void print_list(list *l) {
  printf("List: [ ");
  for (int i = 0; i < l->size; i++) printf("%i ", l->data[i].key);
  printf("]\n");
}

int binary_search_list(list *l, key_type key) {
  int left, right, mid;
  left = 0;
  right = l->size - 1;
  while (left <= right) {
    mid = (left + right) / 2;
    if (l->data[mid].key == key)
      return mid;
    else {
      if (l->data[mid].key > key)
        right = mid - 1;
      else
        left = mid + 1;
    }
  }
}

bool ordened_insert_list(list *l, _register reg) {
  if (l->size >= MAX) return false;
  int pos = l->size;
  while (pos > 0 && l->data[pos - 1].key > reg.key) {
    l->data[pos] = l->data[pos - 1];
    pos--;
  }
  l->data[pos] = reg;
  l->size++;
  return true;
}

bool delete_elem_list(list *l, key_type key) {
  int pos = binary_search_list(l, key);
  if (pos == -1) return false;
  for (int j = pos; j < l->size - 1; j++) l->data[j] = l->data[j + 1];
  l->size--;
  return true;
}

void restart_list(list *l) { l->size = 0; }

int main() {
  list l;
  create_list(&l);

  _register reg;
  reg.key = 10;
  ordened_insert_list(&l, reg);

  reg.key = 20;
  ordened_insert_list(&l, reg);

  reg.key = 30;
  ordened_insert_list(&l, reg);

  print_list(&l);
  printf("List size: %d\n", size_list(&l));
  printf("Index of 30: %d\n", binary_search_list(&l, 30));

  delete_elem_list(&l, 20);
  print_list(&l);
  printf("List size: %d\n", size_list(&l));
  printf("Index of 30: %d\n", binary_search_list(&l, 30));

  return 0;
}
