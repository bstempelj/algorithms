#include <stdio.h>
#include <stdlib.h>

struct node {
	int key;
	struct node *next;
};
typedef struct node node_t;

int main(void) {
	int nums[] = { 1, 4, 9, 16 };
	int len = sizeof(nums) / sizeof(int);
	if (len == 0) {
		return 1;
	}

	node_t *root = malloc(sizeof(node_t));
	root->key = nums[0];
	root->next = NULL;

	node_t *node = NULL;
	node_t *prev = root;

	for (int i = 1; i < len; i++) {
		node = malloc(sizeof(node_t));
		node->key = nums[i];
		node->next = NULL;
		prev->next = node;
		prev = node;
	}

	while (root != NULL) {
		printf("%d\n", root->key);
		root = root->next;
	}
	return 0;
}
