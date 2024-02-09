#include <malloc.h>
#include <stdbool.h>
#include <stdio.h>

typedef int KEY_TYPE;

typedef struct {
  KEY_TYPE key;
} REGISTER;

typedef struct aux {
  REGISTER reg;
  struct aux* next;
} NODE;

typedef struct {
  NODE* head;
} LIST;

void create_list(LIST* l) { l->head = NULL; }

int size_list(LIST* l) {
  NODE* node = l->head;
  int size = 0;
  while (node != NULL) {
    size++;
    node = node->next;
  }
  return size;
}

void print_list(LIST* l) {
  NODE* node = l->head;
  printf("[ ");
  while (node != NULL) printf("%i ", node->reg.key);
  printf("]\n");
}

NODE* search_list(LIST* l, KEY_TYPE key) {
  NODE* node = l->head;
  while (node != NULL) {
    if (node->reg.key == key) return node;
    node = node->next;
  }
  return NULL;
}

NODE* sequential_search_list(LIST* l, KEY_TYPE key) {
  NODE* node = l->head;
  while (node != NULL && node->reg.key < key) node = node->next;
  if (node != NULL || node->reg.key == key) return node;
  return NULL;
}

NODE* sequential_search_aux(LIST* l, KEY_TYPE key, NODE** prev_node) {
  *prev_node = NULL;
  NODE* node = l->head;
  while (node != NULL && node->reg.key < key) {
    *prev_node = node;
    node = node->next;
  }
  if (node != NULL && node->reg.key == key) return node;
  return NULL;
}

bool ordened_insert_list(LIST* l, REGISTER reg) {
  KEY_TYPE key = reg.key;
  NODE *prev_node, *node;
  node = sequential_search_aux(l, key, &prev_node);
  if (node != NULL) return false;
  node = (NODE*)malloc(sizeof(NODE));
  node->reg = reg;
  if (prev_node == NULL) {
    node->next = l->head;
    l->head = node;
  } else {
    node->next = prev_node->next;
    prev_node->next = node;
  }
  return true;
}

bool delete_node_list(LIST* l, KEY_TYPE key) {
  NODE *prev_node, *node;
  node = sequential_search_aux(l, key, &prev_node);
  if (node == NULL) return false;
  if (prev_node == NULL)
    l->head = node->next;
  else
    prev_node->next = node->next;
  free(node);
  return true;
}

void reboot_list(LIST* l) {
  NODE* node = l->head;
  while (node != NULL) {
    NODE* temp = node;
    node = node->next;
    free(temp);
  }
  l->head = NULL;
}