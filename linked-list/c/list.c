#include "list.h"

#include <stdio.h>
#include <stdlib.h>

void list_debug(node_t *list) {
	if (list == NULL) {
		fprintf(stderr, "trying to print a NULL list\n");
		return;
	}
	printf("prev: %p\nkey: %d\nnext: %p\n", list->prev, list->key, list->next);
}

node_t* list_new(int key) {
	node_t *node = malloc(sizeof(node_t));
	node->prev = NULL;
	node->key = key;
	node->next = NULL;
	return node;
}

node_t* list_new_from_array(int *keys, int len) {
	if (len == 0) {
		return NULL;
	}
	node_t *head = list_new(keys[0]), *node = head;
	for (int i = 1; i < len; i++) {
		list_append(&node, keys[i]);
		node = node->next;
	}
	return head;
}

void list_free(node_t **head) {
	if (head == NULL || *head == NULL) {
		fprintf(stderr, "trying to free a null list");
		return;
	}
	node_t *node = *head;
	while (node != NULL) {
		node_t *next = node->next;
		free(node);
		node = next;
	}
	head = NULL;
}

node_t* list_search(node_t *list, int key) {
	node_t *node = list;
	while (node != NULL && node->key != key) {
		node = node->next;
	}
	return node;
}

void list_prepend(node_t **list, int key) {
	if (list == NULL) {
		fprintf(stderr, "list is null\n");
		return;
	}
	node_t *node = malloc(sizeof(node_t));
	node->prev = NULL;
	node->key = key;
	node->next = *list;

	if (*list == NULL) {
		(*list) = node;
	} else {
		(*list)->prev = node;
		(*list) = node;
	}
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
