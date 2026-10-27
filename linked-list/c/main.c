#include "list.h"
#include "test.h"

#include <stdio.h>
#include <stdlib.h>

struct test {
	const char* name;
	bool (*fp)(void);
};
typedef struct test test_t;

int main(void) {
	test_t tests[] = {
		{ "test_list_new", test_list_new },
		{ "test_list_new_from_array", test_list_new_from_array },
		{ "test_list_prepend", test_list_prepend },
		{ "test_list_append", test_list_append },
		{ "test_list_search", test_list_search },
		{ "test_list_remove", test_list_remove },
		{ "test_array_to_linked_list", test_array_to_linked_list },
	};
	int len = sizeof(tests) / sizeof(tests[0]);

	for (int i = 0; i < len; i++) {
		printf("%s...%s\n", tests[i].name, tests[i].fp() ? "OK" : "FAIL");
	}
	return 0;
}
