#include <stdio.h>
#include <stdlib.h>
#define MAX_ELEMENTS 100

typedef struct queue Queue;

struct queue{
    int elements[MAX_ELEMENTS];
    int firstElement;
    int lastElement;
};

Queue* createQueue(void){//Creates queue
    Queue* q;
    q = (Queue*)malloc(sizeof(Queue));
    if(!q){
        perror("NULL");
        exit(1);
    }
    q->firstElement = 0;
    q->lastElement = 0;
}
void queueElement(Queue* q, int element){//Queue element
    q->elements[q->lastElement] = element;
    q->lastElement += 1;
    if(q->lastElement == MAX_ELEMENTS){
        q->lastElement = 0;
    }
}
void unQueue (Queue* q){//Unqueues 
    int r = q->elements[q->firstElement];
    q->firstElement += 1;
    if(q->firstElement == MAX_ELEMENTS){
        q->firstElement = 0;
    }
    return r;
}
int queueSize(Queue* q){//Checks queue size
    int t = q->lastElement - q->firstElement;
    if (t<0){
        t += MAX_ELEMENTS;
        return t;
    }
}
int destroyQueue(Queue* q){//Destroys the queue
    free(q);
}