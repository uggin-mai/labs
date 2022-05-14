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
    list->tail = NULL; // IMPORTANT
    list->tail = list->head;
    
    return list;
}

void list_insert(List *list, Item key, Item value)
{   
    ListNode *to_insert = (ListNode*) malloc(sizeof(ListNode));
    to_insert->data = value;
    
    ListNode *ptr = list->head;
    printf("sup1\n");
    if (list->head == NULL){ //stoyal = vmesto == SUKA
        printf("sup2");
    }
    printf("%d", ptr->data);
    while(ptr->data != key){

      //printf("(%d - %d)", 1, ptr->data);
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
            exit; //??
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
        //list->tail = list->tail->next;
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
	
   //start from the beginning
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
                //printf("%d %d\n", i, j);
                //printf("%d - %d\n", ptr->data, next->data);
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



