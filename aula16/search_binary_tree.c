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

NODE* search_prev(NODE* root, KEY_TYPE value) {
	if (root->left->value == value || root->right->value == value) return root;
	if (value < root->value) return search_prev(root->left, value);
	return search_prev(root->right, value);
}

NODE* delete(NODE* root, KEY_TYPE value) {
	if (root == NULL) return false;

	NODE* temp_node;
	NODE* unwanted_node = search(root, value);

	if (value == root->value) {
		if (root->left == NULL && root->right == NULL) {
			free(root);
			return NULL;
		}

		if (root->right != NULL) root = root->right;
		else root = root->left;
		
		NODE* temp_node = root;
		while (temp_node->left != NULL) temp_node = temp_node->left;
		temp_node->left = unwanted_node->left;
	} else {
		NODE* prev = search_prev(root, value);
		
		int descendents;
		if (unwanted_node->left == NULL && unwanted_node->right == NULL) {
			descendents = 0;
		} else if (unwanted_node->right == NULL && unwanted_node->left != NULL) {
			descendents = 1;
		} else if (unwanted_node->left == NULL && unwanted_node->right != NULL) {
			descendents = 2;
		} else {
			descendents = 3;
		}
	}
	free(unwanted_node);
	return root;
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

	tree = delete(tree, 23);
	print(tree);
} 
