#include <stdlib.h>
#include <stdio.h>

typedef struct list List;

struct list{
    int info;
    List* next;
};

List* createList(void) {//Function designed to create a new void list
    return NULL;
}

List* insertList(List* list, int value){//Insert a new value in the beggining of the list, and returns the updated list
    List* new = (List*)malloc(sizeof(List));
    new->info = value;
    new->next = list;
    return new;
}

void printList(List* list){//Prints lists' values
    while(list != NULL){
        printf("info= %d ", list->info);
        list = list->next;
    }
    printf("\n");
}

int emptyListCheck(List* list){//Check if the list is empty
    return (list == NULL);
}

List* searchValue(List* list, int value){//Search the list for specific value
    while(list != NULL){
        if(list->info == value){
            return list;
        }
        list = list->next;
    }
    return NULL;
}

List* removeValue(List* list, int value){//Remove specific value from the list
    List* ant = NULL;
    List* p = list;
    while (p!=NULL && p->info!=value){
        ant = p;
        p = p->next;
    }

    if (p == NULL){
        return list;
    }
    if (ant == NULL){
        list = p->next;
    }
    else{
        ant->next = p->next;
    }
    free(p);
    return list;
}

void deleteList (List* list){//Delete the list
    List* t;
    while(list != NULL){
        List* aux = list;
        t = list->next;
        free(aux);
        aux = t;
    }
}

List* insertInOrder (List* list, int value){//Insert a value in a specific order
    List* new;
    List* ant = NULL;
    List* p = list;
    while (p!=NULL && p->info < value){
        ant = p;
        p = p->next;
    }
    new = (List*) malloc(sizeof(List));
    new->info = value;

    if (ant == NULL){
        new->next = list;
        list = new;
    }
    else{
        new->next = ant->next;
        ant->next = new;
    }
    return list;
}

int equalListsCheck (List* list1, List* list2){//Checks if two lists are equal
    while (list1 != NULL && list2 != NULL){
        if (list1->info != list2->info){
            return 0;
        }
        list1 = list1->next;
        list2 = list2->next;
    }
    return 1;
}