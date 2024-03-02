#include <stdio.h>
#include <stdlib.h>

#define true 1
#define false 0
typedef int bool;

typedef int KEY_TYPE;
typedef enum { left, right } SIDE;

typedef struct aux {
  KEY_TYPE value;
  struct aux *left, *right;
} NODE;

typedef struct {
  NODE *root;
} BINARY_TREE;

NODE *search_key(KEY_TYPE key, NODE *root) {
  if (root == NULL)
    return NULL;
  if (root->value == key)
    return root;
  NODE *aux = search_key(key, root->left);
  if (aux)
    return aux;
  return search_key(key, root->right);
}

NODE *create_node(KEY_TYPE key) {
  NODE *new = (NODE *)malloc(sizeof(NODE));
  new->value = key;
  new->left = NULL;
  new->right = NULL;
  return new;
}

void new_root(NODE **root, KEY_TYPE key) { *root = create_node(key); }

bool new_child(NODE *root, KEY_TYPE parent_key, KEY_TYPE key, SIDE s) {
  NODE *parent = search_key(parent_key, root);
  if (parent == NULL)
    return false;
  NODE *new = create_node(key);
  switch (s) {
  case right:
    new->right = parent->right;
    parent->right = new;
    break;
  default:
    new->left = parent->left;
    parent->left = new;
    break;
  }
  return true;
}
