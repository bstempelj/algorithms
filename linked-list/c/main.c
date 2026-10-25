#include "list.h"
#include "test.h"

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	printf("test_list_new...");
	if (test_list_new()) {
		printf("OK\n");
	} else {
		printf("NOK\n");
	}

	printf("test_list_prepend...");
	if (test_list_prepend()) {
		printf("OK\n");
	} else {
		printf("NOK\n");
	}
	
	printf("test_list_append...");
	if (test_list_append()) {
		printf("OK\n");
	} else {
		printf("NOK\n");
	}

	printf("test_list_search...");
	if (test_list_search()) {
		printf("OK\n");
	} else {
		printf("NOK\n");
	}

	printf("test_array_to_linked_list...");
	if (test_array_to_linked_list()) {
		printf("OK\n");
	} else {
		printf("NOK\n");
	}

	return 0;
}
