#include "list.h"
#include <stdio.h>

bool test_list_new(void) {
	node_t *head = list_new(1);

	if (head->prev != NULL) {
		fprintf(stderr, "expected head->prev=NULL, got %p\n", head->prev);
		return false;
	}
	if (head->key != 1) {
		fprintf(stderr, "expected head->key=1, got %d\n", head->key);
		return false;
	}
	if (head->next != NULL) {
		fprintf(stderr, "expected head->next=NULL, got %p\n", head->next);
		return false;
	}
	return true;
}

bool test_list_prepend(void) {
	node_t *head = list_new(1);	
	list_prepend(&head, 0);

	if (head->key != 0) {
		fprintf(stderr, "expected 0, got %d\n", head->key);
		return false;
	}
	return true;
}

bool test_list_append(void) {
	node_t *head = list_new(0);	
	list_append(&head, 1);

	if (head->next->key != 1) {
		fprintf(stderr, "expected 1, got %d\n", head->key);
		return false;
	}
	return true;
}

bool test_list_search(void) {
	node_t *head = list_new(0);	

	list_append(&head, 1);
	list_append(&head->next, 2);
	list_append(&head->next->next, 3);

	if (head->next->next->key != 2) {
		fprintf(stderr, "expected 2, got %d\n", head->key);
		return false;
	}
	return true;
}

bool test_array_to_linked_list(void) {
	int nums[] = { 1, 4, 9, 16 };
	int len = sizeof(nums) / sizeof(int);

	node_t *head = list_new(nums[0]);
	node_t *node = head;

	for (int i = 1; i < len; i++) {
		list_append(&node, nums[i]);
		node = node->next;
	}
	node_t *tail = node;
	
	// test head to tail
	int i = 0; node = head;
	while (node != NULL) {
		if (node->key != nums[i]) {
			fprintf(stderr, "expected node->key=%d, got %d\n", nums[i], node->key);
			return false;
		}
		i++; node = node->next;
	}

	if (i != len) {
		fprintf(stderr, "expected i==len, got i=%d len=%d\n", i, len);
		return false;
	}

	// test tail to head
	node = tail; i = len-1;
	while (node != NULL) {
		if (node->key != nums[i]) {
			fprintf(stderr, "expected node->key=%d, got %d\n", nums[i], node->key);
			return false;
		}
		i--; node = node->prev;
	}
	return true;
}
