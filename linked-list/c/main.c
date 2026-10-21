#include <stdio.h>
#include <stdlib.h>

struct node {
	struct node *prev;
	int key;
	struct node *next;
};
typedef struct node node_t;

void list_debug(node_t *list) {
	if (list == NULL) {
		fprintf(stderr, "trying to print a NULL list\n");
		return;
	}
	printf("prev: %p\nkey: %d\nnext: %p\n", list->prev, list->key, list->next);
}

node_t* list_search(node_t *list, int key) {
	node_t *node = list;
	while (node != NULL && node->key != key) {
		node = node->next;
	}
	return node;
}

void list_append(node_t **list, int key) {
	if (list == NULL) {
		fprintf(stderr, "list is null\n");
		return;
	}
	node_t *node = malloc(sizeof(node_t));
	node->key = key;
	node->next = NULL;
	node->prev = *list;

	if (*list != NULL) {
		(*list)->next = node;
	} else {
		*list = node;
	}
}

int main(void) {
	int nums[] = { 1, 4, 9, 16 };
	int len = sizeof(nums) / sizeof(int);
	if (len == 0) {
		return 1;
	}

	node_t *head = NULL;
	list_append(&head, nums[0]);

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

	node_t* x = list_search(head, 9);
	list_debug(x);

	return 0;
}
