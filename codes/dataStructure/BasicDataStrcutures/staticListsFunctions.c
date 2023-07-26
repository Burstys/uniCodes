#include <stdlib.h>
#include <stdio.h>
#define MAX_ELEMENTS 100

typedef struct staticList sList;

struct staticList{
    int elements[MAX_ELEMENTS];
    int last;
};

sList* create(void){
    sList* sL;
    sL = malloc(sizeof(sList));
    if(!sL){
        perror("NULL");
        exit(1);
    }
    sL->last = 0;
}

void insertLastPosition(sList* sL, int value){
    if(sL->last == MAX_ELEMENTS-1){
        printf("List is full\n");
        exit(1);
    }
    sL->elements[sL->last] = value;
    sL->last += 1;
}

void insertPosition(sList* sL, int value, int position){
    if(sL->last == MAX_ELEMENTS-1){
        printf("List is full\n");
        exit(1);
    }
    for(int i=sL->last; i>position; i--){
        sL->elements[i] = sL->elements[i-1];
    }
    sL->last += 1;
    sL->elements[position] = value;
}

int removeValue(sList* sL, int value){
    for(int i=0; i<sL->last; i++){
        if(sL->elements[i] == value){
            for(int j=i; j<sL->last; j++){
                sL->elements[j] = sL->elements[j+1];
            }
            sL->last -= 1;
            return 1;
        }
    }
    return 0;
}

int removeLastValue(sList* sL){
    if(sL->last == NULL){
        printf("List is empty\n");
        exit(1);
    }
    else{
        sL->elements[sL->last] = NULL;
        if(sL->last>0){
            sL->last -= 1;
        };
    }
}

