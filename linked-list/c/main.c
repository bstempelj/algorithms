#include <stdio.h>
#include <stdlib.h>

struct node {
	struct node *prev;
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

	node_t *head = malloc(sizeof(node_t));
	head->key = nums[0];
	head->next = NULL;

	node_t *node = NULL;
	node_t *prev = head;

	for (int i = 1; i < len; i++) {
		node = malloc(sizeof(node_t));
		node->prev = prev;
		node->key = nums[i];
		node->next = NULL;
		prev->next = node;
		prev = node;
	}
	node_t *tail = node;

	printf("from head to tail: ");
	node = head;
	while (node != NULL) {
		printf("%d ", node->key);
		node = node->next;
	}
	printf("\n");

	printf("from tail to head: ");
	node = tail;
	while (node != NULL) {
		printf("%d ", node->key);
		node = node->prev;
	}
	printf("\n");
	return 0;
}
