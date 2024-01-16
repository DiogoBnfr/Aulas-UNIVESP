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

void create_list(LIST* l) {
  l->head = (NODE*)malloc(sizeof(NODE));
  l->head->next = l->head;
}

int size_list(LIST* l) {
  NODE* node = l->head->next;
  int size = 0;
  while (node != l->head) {
    size++;
    node = node->next;
  }
  return size;
}

void print_list(LIST* l) {
  NODE* node = l->head->next;
  printf("[ ");
  while (node != l->head) {
    printf("%node ", node->reg.key);
    node = node->next;
  }
  printf("]\n");
}

NODE* sentinel_search_list(LIST* l, KEY_TYPE key) {
  NODE* node = l->head->next;
  l->head->reg.key = key;
  while (node->reg.key != key) node = node->next;
  if (node != l->head) return node;
  return NULL;
}

NODE* sentinel_ordened_search_list(LIST* l, KEY_TYPE key) {
  NODE* node = l->head->next;
  l->head->reg.key = key;
  while (node->reg.key < key) node = node->next;
  if (node != l->head && node->reg.key == key) return node;
  return NULL;
}

NODE* sequential_search_list_aux(LIST* l, KEY_TYPE key, NODE** prev) {
  *prev = l->head;
  NODE* node = l->head->next;
  l->head->reg.key = key;
  while (node->reg.key < key) {
    *prev = node;
    node = node->next;
  }
  if (node != l->head && node->reg.key == key) return node;
  return NULL;
}

bool ordened_insert_list(LIST* l, REGISTER reg) {
  NODE *prev, *node;
  node = sequential_search_list_aux(l, reg.key, &prev);
  if (node != NULL) return false;
  node = (NODE*)malloc(sizeof(NODE));
  node->reg = reg;
  node->next = prev->next;
  prev = node;
  return true;
}

bool delete_node_list(LIST* l, KEY_TYPE key) {
  NODE *prev, *node;
  node = sequential_search_list_aux(l, key, &prev);
  if (node == NULL) return false;
  prev->next = node->next;
  free(node);
  return true;
}

void reboot_list(LIST* l) {
  NODE* node = l->head->next;
  while (node != l->head) {
    NODE* garbage = node;
    node = node->next;
    free(garbage);
  }
  l->head->next = l->head;
}