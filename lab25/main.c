#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "list.h"


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