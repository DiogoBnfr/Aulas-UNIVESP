#include <stdio.h>
#include <stdlib.h>

#define true 1
#define false 0
typedef int bool;

typedef int KEY_TYPE;

typedef struct aux { 
	KEY_TYPE value;
	struct aux *left, *right;
} NODE;

NODE* new_tree() {
	return NULL;
}

NODE* create_node(KEY_TYPE value) {
	NODE* new = (NODE*)malloc(sizeof(NODE));
	new->value = value;
	new->left = NULL;
	new->right = NULL;
	return new;
}

NODE* insert_node(NODE* root, KEY_TYPE value) {
	if (root == NULL) return create_node(value);
	if (value < root->value) {
		root->left = insert_node(root->left, value);
	} else {
		root->right = insert_node(root->right, value);
	}
	return root;
}

int main(void) {
	NODE* tree = new_tree();

	tree = insert_node(tree, 15);
	tree = insert_node(tree, 20);
	tree = insert_node(tree, 23);
	tree = insert_node(tree, 19);
	tree = insert_node(tree, 8);
	tree = insert_node(tree, 3);
	tree = insert_node(tree, 12);
} 
