#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_NAME 256
#define TABLE_SIZE 10

// Estrutura da lista de pessoas
typedef struct person{
    char name[MAX_NAME];
    int age;
    struct person *next;
} person;

person *hash_table[TABLE_SIZE];

// Função de hash
unsigned int hash(char *name){
    int length = strnlen(name, MAX_NAME);
    unsigned int hash_value = 0;
    for(int i = 0; i < length; i++){
        hash_value += name[i];
        hash_value = (hash_value * name[i]) % TABLE_SIZE;
    }
    return hash_value;
}

// Função para iniciar a tabela hash
void init_hash_table(){
    for (int i=0; i<TABLE_SIZE;i++){
        hash_table[i] = NULL;
    }
}

// Função para imprimir a tabela hash
void print_table(){
    printf("Start\n");
    for (int i=0; i< TABLE_SIZE; i++){
        if(hash_table[i]==NULL){
            printf("\t%i\t---\n", i);
        }
        else{
            printf("\t%i\t", i);
            person *temp = hash_table[i];
            while(temp != NULL){
                printf("%s - ", temp->name);
                temp = temp->next;
            }
            printf("\n");
        }
    }
}

// Função para inserir
bool hash_table_insert(person *p){
    if (p == NULL){
        return false;
    }
    int index = hash(p->name);
    p->next = hash_table[index];
    hash_table[index] = p;
    return true;
}

// Função de busca
person *hash_table_lookup(char *name){
    int index = hash(name);
    person *aux = hash_table[index];
    while (aux != NULL && strncmp(aux->name, name, MAX_NAME)!=0){
        aux = aux->next;
    }
    return aux;
}

// Função para deletar
person *hash_table_delete(char *name){
    int index = hash(name);
    person *aux = hash_table[index];
    person *ant = NULL;
    while (aux!=NULL && strncmp(aux->name, name, MAX_NAME)!=0){
        ant = aux;
        aux = aux->next;
    }
    if (aux == NULL){
        return NULL;
    }
    if (ant == NULL){
        hash_table[index] = aux->next;
    } else {
        ant->next = aux->next;
    }
    return aux;
}

int main(){
    init_hash_table();
    print_table();

    person jacob = {.name = "Jacob", .age = 20};
    person kate = {.name = "Kate", .age = 21};
    person yasmin = {.name = "Yasmin", .age = 22};
    person rafael = {.name = "Rafael", .age = 23};
    person maria = {.name = "Maria", .age = 24};
    person joao = {.name = "Joao", .age = 25};
    person pedro = {.name = "Pedro", .age = 26};
    person lucas = {.name = "Lucas", .age = 27};
    person marcos = {.name = "Marcos", .age = 28};
    person julia = {.name = "Julia", .age = 29};

    hash_table_insert(&jacob);
    hash_table_insert(&kate);
    hash_table_insert(&yasmin);
    hash_table_insert(&rafael);
    hash_table_insert(&maria);
    hash_table_insert(&joao);
    hash_table_insert(&pedro);
    hash_table_insert(&lucas);
    hash_table_insert(&marcos);
    hash_table_insert(&julia);

    person *tmp = hash_table_lookup("Yasmin");
    if (tmp == NULL){
        printf("Not found\n");
    } else {
        printf("Found %s\n", tmp->name);
    }

    tmp = hash_table_lookup("Lucas");
    if (tmp == NULL){
        printf("Not found\n");
    } else {
        printf("Found %s\n", tmp->name);
    }

    tmp = hash_table_lookup("Joao");
    if (tmp == NULL){
        printf("Not found\n");
    } else {
        printf("Found %s\n", tmp->name);
    }

    tmp = hash_table_lookup("Maria");
    if (tmp == NULL){
        printf("Not found\n");
    } else {
        printf("Found %s\n", tmp->name);
    }

    hash_table_delete("Yasmin");
    tmp = hash_table_lookup("Yasmin");
    if (tmp == NULL){
        printf("Not found\n");
    } else {
        printf("Found %s\n", tmp->name);
    }

    print_table();
}