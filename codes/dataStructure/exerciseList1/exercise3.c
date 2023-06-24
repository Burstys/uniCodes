#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <math.h>

/*Faça um programa utilizando o comando malloc, que leia o peso de n pessoas, armazene em um vetor e encontre a pessoa com o peso mais distante da média.*/

typedef struct person Person;
struct person{
    float weight;
};

int main(){
    int n;
    float average =0, furthest = -1;
    printf("How many people are going to be inserted?\n");
    scanf("%d", &n);
    
    Person *person;
    person = (Person*)malloc(n*sizeof(Person));

    for(int i=0;i<n;i++){
        printf("Number %d weight: \n", i+1);
        scanf("%f", &person[i].weight);
        average += person[i].weight/n;
        if(person[i].weight > furthest){
            furthest = person[i].weight;
        }
    }

    printf("Average weight: %.2f\nFurthest weight: %.2f", average, furthest);
    free (person);
    return 0;
}
