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

//Binary search tree

void bstPrint(Node *t){
    if (t!=NULL){
        bstPrint(t->left);
        printf("%d", t->data);
        bstPrint(t->right);
    }
}

Node *bstHasElement(Node *t, int value){
    if(t == NULL){
        return NULL;
    }
    else if(t->data > value){
        return bstHasElement(t->left, value);
    }
    else if(t->data < value){
        return bstHasElement(t->right, value);
    }
    else{
        return t;
    }
}

Node *bstInsert(Node *t, int value){
    if (t == NULL){
        t = (Node*)malloc(sizeof(Node));
        t->data = value;
        t->left = t->right = NULL;
    }

    else if (value < t->data){
        t->left = bstInsert(t->left, value);
    }
    else{ //v >= t->data
        t->right = bstInsert(t->right, value);
    }
    return t;
}

Node *bstRemove(Node *t, int value){
    if (t == NULL){
        return NULL;
    }
    else if(t->data > value){
        t->left = bstRemove(t->left, value);
    }
    else if(t->data < value){
        t->right = bstRemove(t->right, value);
    }
    else{
        if (t->left == NULL && t->right == NULL){
            free(t);
            t = NULL;
        }

        else if(t->left == NULL){
            Node *aux = t;
            t = t->right;
            free(aux); 
        }
        else if(t->right == NULL){
            Node *aux = t;
            t = t->left;
            free(aux); 
        }
        else{
            Node *aux = t->left;
            while (aux->right != NULL){
                aux = aux->right;
            }
            t->data = aux->data;
            aux->data = value;
            t->left = bstRemove(t->left, value);
        }
    }
    return t;
}
