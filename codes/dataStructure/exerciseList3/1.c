#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TABLE_SIZE 97

typedef struct student{
    int id;
    float grade;
    char name[100];
    struct student *nextStudent;
} Student;

typedef struct hashTable{
    Student *students[TABLE_SIZE];
    int nWeights;
    int *weights;
} HashTable;

// Function to calculate the hash value
unsigned int calculate_hash(HashTable *ht, char *name){
    unsigned int hash_value = 0;
    for (int i = 0; i < strlen(name); i++){
        hash_value += (unsigned int) name[i] * ht->weights[i%ht->nWeights];
    }
    return hash_value % TABLE_SIZE;
}

// Function to create a new hash table
HashTable *createHashTable(){
    HashTable *ht = (HashTable*)malloc(sizeof(HashTable));
    for (int i=0; i < TABLE_SIZE; i++){
        ht->students[i] = NULL;
    }

    srand(time(NULL));

    ht->weights = (int*) malloc (sizeof(int) * ht->nWeights);
    for (int i = 0; i < ht->nWeights; i++){
        ht->weights[i] = rand() % 100000;
    }
    return ht;
}

// Function to insert a new student in the hash table
void insertStudent(HashTable *ht, int id, float grade, char *name){
    Student *newStudent = (Student*)malloc(sizeof(Student));
    newStudent->id = id;
    newStudent->grade = grade;
    strcpy(newStudent->name, name);
    newStudent->nextStudent = NULL;

    unsigned int index = calculate_hash(ht, name);

    newStudent->nextStudent = ht->students[index];
    ht->students[index] = newStudent;
}

// Function to print the student information
void printStudentInfo(Student *student){
    printf("Name: %s\n", student->name);
    printf("ID: %d\n", student->id);
    printf("Grade: %.2f\n", student->grade);
}

// Function to insert a student in the hash table using linear probing
void insertLinear(HashTable *ht, int id, float grade, char *name){
    Student *newStudent = (Student*)malloc(sizeof(Student));
    newStudent->id = id;
    newStudent->grade = grade;
    strcpy(newStudent->name, name);

    unsigned int index = calculate_hash(ht, name);

    while (ht->students[index]!= NULL){
        index = (index + 1) % TABLE_SIZE;
    }
    ht->students[index] = newStudent;
}

// Function to search a student in the hash table
void searchStudent(HashTable *ht, char *name){
    unsigned int index = hash(ht, name);
    Student *currentStudent = ht->students[index];

    while (currentStudent != NULL){
        if(strcmp(currentStudent->name, name) == 0){
            printf("Estudante encontrado\n");
            printStudentInfo(ht->students[index]);
            return currentStudent;
        }
        currentStudent = currentStudent->nextStudent;
    }
    printf("Estudante não encontrado\n");
    return NULL;
}

// Function to search a student in the hash table using linear probing
void searchStudent2(HashTable *ht, char *name){
    unsigned int index = hash(ht, name);
    while (ht->students[index] != NULL && strcmp(ht->students[index]->name, name)!= 0){
        index = (index + 1) % TABLE_SIZE;
    }

    if (ht->students[index] != NULL && strcmp(ht->students[index]->name, name) == 0){
        printf("Estudante encontrado\n");
        printStudentInfo(ht->students[index]);
        return ht->students[index];
    }
    printf("Estudante não encontrado\n");
    return NULL;
}