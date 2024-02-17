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

NODE* insert(NODE* root, KEY_TYPE value) {
	if (root == NULL) return create_node(value);
	if (value < root->value) {
		root->left = insert(root->left, value);
	} else {
		root->right = insert(root->right, value);
	}
	return root;
}

NODE* search(NODE* root, KEY_TYPE value) {
	if (root == NULL) return NULL;
	if (root->value == value) return root;
	if (value < root->value) return search(root->left, value);
	return search(root->right, value);
}

int size(NODE* root) {
	if (root == NULL) return 0;
	return size(root->left) + 1 + size(root->right);
}

void print(NODE* root) {
	if (root != NULL) {
		printf("%d", root->value);
		printf("(");
		print(root->left);
		print(root->right);
		printf(")");
	}
}

int main(void) {
	NODE* tree = new_tree();

	tree = insert(tree, 15);
	tree = insert(tree, 20);
	tree = insert(tree, 23);
	tree = insert(tree, 19);
	tree = insert(tree, 8);
	tree = insert(tree, 3);
	tree = insert(tree, 12);

	print(tree);
	printf("\n");
	
	bool r;
	if (search(tree, 23)) r = true;
	else r = false;
	printf("Contain 23: %b\n", r);

	if (search(tree, 99)) r = true;
	else r = false;
	printf("Contain 99: %b\n", r);
	
	if (search(tree, 89)) r = true;
	else r = false;
	printf("Contain 89: %b\n", r);

	printf("Size: %d\n", size(tree));
} 
