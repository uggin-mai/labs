#ifndef LIST_H
#define LIST_H

#include <stdbool.h>
#include <stdlib.h>

typedef int Item;

typedef struct listnode {
    Item data;
    struct listnode *next;
} ListNode;

typedef struct {
    ListNode *head;
    ListNode *current;
    ListNode *tail;
} List;

List *list_create();
void list_insert(List *list, Item key, Item value);
void list_erase(List *list, Item value);
bool list_is_empty(List *list);
void list_destroy(List *list);
void list_push_front(List *list, Item value);
void list_push_back(List *list, Item value);
void list_pop_front(List *list);
void list_pop_back(List *list);
void list_print(List *list);
int list_size(List *list);
int get_length(List *list);

void sort_bubble(List *list, int size);

#endif

