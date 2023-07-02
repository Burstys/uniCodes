#include <stdio.h>
#include <stdlib.h>
#define MAX_ELEMENTS 100


typedef struct stack Stack;

struct stack{
    int elements[MAX_ELEMENTS];
    int top;
};

Stack* create(void){
    Stack* s;
    s = malloc(sizeof(Stack));
    if (!s){
        perror("NULL");
        exit(1);
    }
    s->top = 0;
}
void stackUp (Stack *s, int element){
    if(s->top == MAX_ELEMENTS){
        printf("Stack is full\n");
        exit(1);
    }
    s->elements[s->top] = element;
    s->top += 1;
}
void unstack (Stack* s){
    if(s->top == 0){
        printf("Stack is empty\n");
        exit(1);
    }
    s->top -= 1;
    return s->elements[s->top];
}
int stackSize (Stack* s){
    return s->top;
}
int destroyStack (Stack* s){
    free(s);
}

