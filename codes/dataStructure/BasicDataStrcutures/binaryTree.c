#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *left;
    struct node *right;
} Node;

//lst = left sub-tree  rst = right sub-tree
Node *createNode(int data, Node *lst, Node *rst) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    if(newNode == NULL) exit(1);
    newNode->data = data;
    newNode->left = lst;
    newNode->right = rst;
    return newNode;
}

Node *createEmptyNode(void){
    return NULL;
}

int isEmpty(Node *t){
    return t == NULL;
}

Node *freeBTree (Node * t){
    if(!isEmpty(t)){
        freeBTree(t->left);
        freeBTree(t->right);
        free(t);
    }
    return NULL;
}

int hasElement (Node *a, int element){
    if(isEmpty(a)) return 0;
    else{
        return a->data == element ||
         hasElement(a->left, element) || 
         hasElement(a->right, element);
    }
}

void printNodes (Node *t){
    if(!isEmpty(t)){
        printf("%d", t->data);
        printNodes(t->left);
        printNodes(t->right);
    }
}

int main(void){
    Node *t = createNode(1, createNode(2, createEmptyNode(), createEmptyNode()), createNode(3, createEmptyNode(), createEmptyNode()));
    printNodes(t);
    printf("\n");
    printf("%d", hasElement(t, 3));
    printf("\n");
    printf("%d", hasElement(t, 4));
    printf("\n");
    freeBTree(t);
    return 0;
}

