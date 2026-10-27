#ifndef LIST_H
#define LIST_H

struct node {
	struct node *prev;
	int key;
	struct node *next;
};
typedef struct node node_t;

void list_debug(node_t *head);
void list_free(node_t **list);
node_t* list_new(int key);
node_t* list_new_from_array(int *keys, int len);
node_t* list_search(node_t *list, int key);
void list_prepend(node_t **list, int key);
void list_append(node_t **list, int key);

#endif // LIST_H
