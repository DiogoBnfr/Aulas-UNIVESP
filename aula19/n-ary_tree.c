#include <stdio.h>
#include <stdlib.h>

#define true 1
#define false 0
typedef int bool;

typedef int KEY_TYPE;

typedef struct node {
  KEY_TYPE key;
  struct node *firstborn;
  struct node *brother;
} NODE;

NODE *create_node(KEY_TYPE key) {
  NODE *node = (NODE *)malloc(sizeof(NODE));
  node->key = key;
  node->firstborn = NULL;
  node->brother = NULL;
  return node;
}

NODE *create_tree(KEY_TYPE key) { return create_node(key); }

NODE *search_node(KEY_TYPE key, NODE *root) {
  if (root == NULL)
    return NULL;
  if (root->key == key)
    return root;
  NODE *p = root->firstborn;
  while (p) {
    NODE *node = search_node(key, p);
    if (node)
      return node;
    p = p->brother;
  }
  return NULL;
}

bool insert_node(NODE *root, KEY_TYPE parent_key, KEY_TYPE key) {
  NODE *parent = search_node(parent_key, root);
  if (!parent)
    return false;
  NODE *child = create_node(key);
  NODE *p = parent->firstborn;
  if (!p) {
    parent->firstborn = child;
  } else {
    while (p->brother)
      p = p->brother;
    p->brother = child;
  }
  return true;
}

void print_tree(NODE *root) {
  if (!root)
    return;
  printf("%d(", root->key);
  NODE *p = root->firstborn;
  while (p) {
    print_tree(p);
    p = p->brother;
  }
  printf(")");
}

int main() { NODE *tree = create_tree(5); }
