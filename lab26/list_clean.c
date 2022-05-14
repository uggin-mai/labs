#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "list.h"

typedef int Item;

List *list_create()
{

    List *list = (List*) malloc(sizeof(List));
    
    list->head = (ListNode*) malloc(sizeof(ListNode));
    list->head = NULL;
    list->tail = NULL; 
    list->tail = list->head;
    
    return list;
}

void list_insert(List *list, Item key, Item value)
{   
    ListNode *to_insert = (ListNode*) malloc(sizeof(ListNode));
    to_insert->data = value;
    
    ListNode *ptr = list->head;
    printf("sup1\n");
    if (list->head == NULL){
        printf("sup2");
    }
    printf("%d", ptr->data);
    while(ptr->data != key){

      ptr = ptr->next;

    }


    printf("sup7");


    ListNode *relink = ptr->next;
    ptr->next = to_insert;
    ptr->next->next = relink;
}

void list_erase(List *list, Item value)
{   
    ListNode *ptr = list->head;
    ListNode *ptr_prev = NULL;
    /*
    if (list->head == NULL){
        exit; //??
    }
    */
    while(ptr->data != value){
        if (ptr->next == NULL){
            exit;
        } else {
            ptr_prev = ptr;
            ptr = ptr->next;
        }
    }
    if (ptr == list->head) {
        ListNode *to_free = list->head;
        list->head = list->head->next;
        free(to_free);
    } else {
        ListNode *to_free = ptr;
        ptr_prev->next = ptr->next;
        free(to_free);
    }
}

bool list_is_empty(List *list)
{
    return (list->head == NULL);
}

void list_destroy(List *list)
{
    ListNode *n = list->head->next;
    while (list->head != NULL)
    {
        n = list->head->next;
        free(list->head);
        list->head = n;
    }
    list->head = NULL;
}

void list_push_front(List *list, Item value)
{
    ListNode *pushed = (ListNode*) malloc(sizeof(ListNode));
    pushed->data = value;

    if(list_is_empty(list)){
        list->head = pushed;
        list->head->next = NULL;
        list->tail = list->head;
    } else {
        pushed->next = list->head;
        list->head = pushed;
    }

}

void list_pop_front(List *list)
{   
    ListNode *ptr = list->head;
    ListNode *to_pop = list->head;
    if (list->head == NULL) {
        free(list->head);
        list->head = NULL;
    } else {
        list->head = list->head->next;
        free(to_pop);
    }
}


void list_push_back(List *list, Item value)
{
    ListNode *pushed = (ListNode*) malloc(sizeof(ListNode));
    pushed->data = value;
    pushed->next = NULL;

    if(list_is_empty(list)){
        list->head = pushed;
        list->tail = list->head;
    } else {
        list->tail->next = pushed;
        list->tail = list->tail->next;
    }
}



void list_pop_back(List *list)
{
    ListNode *ptr = list->head;
    ListNode *ptr_prev = NULL;
    while(ptr->next != NULL){
        ptr_prev = ptr;
        ptr = ptr->next;
    }
    if (ptr == list->head) {
        free(list->head);
        list->head = NULL;
    } else {
        ListNode *to_free = ptr;
        ptr_prev->next = NULL;
        free(to_free);
    }
}
void list_print(List *list) {
   ListNode *ptr = list->head;
   printf("\n[ ");
	
   int i = 0;
   while(ptr != NULL) {
      printf("(%d - %d)", i, ptr->data);
      ptr = ptr->next;
      i++;
   }
	
   printf(" ]");
}
int list_size(List *list)
{
    int size = 0;
    ListNode *ptr = list->head;
    for(ptr = list->head; ptr != NULL; ptr = ptr->next) {
      size++;
    }

    return size;
}

void sort_bubble(List *list, int size){


    if (list->head == NULL){
            exit; //??
    } else {
        int i, j, k, tempData;
        k = size;
        ListNode *ptr = list->head;
        ListNode *next = list->head->next;

        for(i = 0; i < size - 1; i++) {
            ptr = list->head;
            next = list->head->next;
            for (j = 0; j < size - i - 1; j++){
                if ( ptr->data > next->data ) {
                    tempData = ptr->data;
                    ptr->data = next->data;
                    next->data = tempData;
                }

                ptr = ptr->next;
                next = next->next;


            }
        }
    }
}

bool isInt(const char*str) {
    while(*str)  {
        if((*str< '0' || *str > '9') && *str != '-' && *str != '.')
            return false;
        *str++;
    }
    return true;
}

int main() {
    printf("|________________________________________________________|\n");
    printf("|                       List Editor                      |\n");
    printf("|________________________________________________________|\n");
    printf("|Create List - |1| Insert - |2| Delete - |3| Empty? - |4||\n");
    printf("|     Destroy - |5| Push front - |6| Push back - |7|     |\n");
    printf("|       Pop front - |8| Pop back - |9| Exit - |0|        |\n");
    printf("|            Bubble sort - |10| Print - |11|             |\n");
    printf("|________________________________________________________|\n");
    

    char input[] = "";
    bool execute = true;
    bool isListCreated = false;
    int task = -1;
    List *list = list_create();
    int value = 0;
    
    while (execute) {
        char input[] = "";
        printf("\n");
        Item data = 0;
        Item key = 0;
        int size = 0;
        Item value = 0;

        scanf("%s", input);
        if (isInt(input)) {
            if (!strcmp("0", input)) task = 0;
            if (!strcmp("1", input)) task = 1;
            if (!strcmp("2", input)) task = 2;
            if (!strcmp("3", input)) task = 3;
            if (!strcmp("4", input)) task = 4;
            if (!strcmp("5", input)) task = 5;
            if (!strcmp("6", input)) task = 6;
            if (!strcmp("7", input)) task = 7;
            if (!strcmp("8", input)) task = 8;
            if (!strcmp("9", input)) task = 9;
            if (!strcmp("10", input)) task = 10;
            if (!strcmp("11", input)) task = 11;
        } else {
            printf("Try something else :) ");
            task = -1;
        }

        switch (task) {
            case 0:
                execute = false;
                if (isListCreated) {
                    list_destroy(list);
                }
                break;
            case 1:
                //already created
                break;
            case 2:
                scanf("%d", &key);
                scanf("%s", input);
                if (isInt(input)){
                    data = atoi(input);
                    list_insert(list, key, data);
                } else {
                    printf("Incorrect input");
                }
                break;
            case 3:
                scanf("%s", input);
                if (isInt(input)){
                    key = atoi(input);
                    list_erase(list, key);
                } else {
                    printf("Incorrect input");
                }
                break;
            case 4:
                printf("Emptiness - %d" , list_is_empty(list));
                break;
            case 5:
                list_destroy(list);
                list = list_create();
                break;
            case 6:
                scanf("%s", input);
                if (isInt(input)){
                    value = atoi(input);
                    list_push_front(list, value);
                } else {
                    printf("Incorrect input");
                }
                break;
            case 7:
                scanf("%s", input);
                if (isInt(input)){
                    value = atoi(input);
                    list_push_back(list, value);
                } else {
                    printf("Incorrect input");
                }
                break;
            case 8:
                list_pop_front(list);
                break;
            case 9:
                list_pop_back(list);
                break;
            case 10:
                size = list_size(list);
                sort_bubble(list, size);
                break;
            case 11:
                list_print(list);
                break;
            default:
                printf("Incorrect input");
                break;
        }
    }
	return 0;
    
}
