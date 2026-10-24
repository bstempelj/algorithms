#include "list.h"
#include <stdio.h>

bool test_list_prepend(void) {
	node_t *head = list_new(1);	
	list_prepend(&head, 0);

	if (head->key != 0) {
		fprintf(stderr, "expected 0, got %d", head->key);
		return false;
	}
	return true;
}

bool test_list_append(void) {
	node_t *head = list_new(0);	
	list_append(&head, 1);

	if (head->next->key != 1) {
		fprintf(stderr, "expected 1, got %d", head->key);
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
		fprintf(stderr, "expected 2, got %d", head->key);
		return false;
	}
	return true;
}
