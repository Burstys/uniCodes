#include <stdio.h>
#include <string.h>
#include "listExercise1.h"

struct list{
    int value;
    List* next;
};

List* createList(void){
    return NULL;
}

int checkListSort(List* list){
    if (list == NULL || list->next == NULL){
        return 1;
    }
    List* newList = list;

    if(newList->value < newList->next){//crescent order
        while (newList->next != NULL){
            if (newList->value > newList->next){
                return 0;
            }
            newList = newList->next;
        }
    }
    else{//decrescente
        while(newList->next != NULL){
            if(newList->value < newList->next){
                return 0;
            }
            newList = newList->next;
        }
    }
    return 1;
}

void copyList(List* list){
    List* secondList;
    secondList = (List*)malloc(sizeof(List));
    secondList = list;
}

