#include <stdio.h>
#include <stdlib.h>

//Defining structs

typedef struct element Element;
typedef struct stack Stack;

struct element{
    int number;
    struct Element* next;
};

struct stack{
    struct Element* top;
};

Element* aux;

Stack* createStack(){
    //Allocate pointer st to manage the stack
    Stack* st = (Stack*)malloc(sizeof(Stack));
    if(st != NULL){
        st->top = NULL; //Empty stack -> top is NULL
    }
    return st;
}

//Inserts a new element, always at the top of the stack

void insert_element(Stack* st){
    //Necessary to allocate memory for every new insertion
    Element* newElement = (Element*)malloc(sizeof(Element));
    printf("Type the number to be inserted: \n");
    scanf("%d", &newElement->number);
    newElement->next = st->top; //As the new element becomes the top of the stack, it will set the current top element as the second one
    st->top = newElement; //Top points to the new adress
    printf("Successfully inserted");
}

//Prints every element in the stack

void queryStack(Stack* st){
    if(st->top == NULL){
        printf("Empty stack\n");
    }
    else{
        aux = st->top;
        do{
            printf("%d", aux->number);
            aux = aux->next;
        }while(aux != NULL);
    }
}