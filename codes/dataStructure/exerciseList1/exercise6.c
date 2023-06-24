#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*Faça um programa utilizando struct que leia a informação da idade, peso e altura(cm) de n pessoas, calcule o IMC e determine o maior valor.
Use calloc.*/

typedef struct person Person;
struct person{
    int age;
    float bodyWeight;
    float heightCentimeters;
};

int main(){
    int n, highest_idx = 0;
    float *bmi, highest = -1;
    
    printf("How many people are going to be tested? \n");
    scanf("%d", &n);

    bmi = (float*)calloc(n, sizeof(float));
    Person *people;
    people = (Person*)calloc(n, sizeof(Person));

    for (int i = 0;i<n;i++){
        printf("Type the %d person's age, bodywheight (kilograms) and height (centimeters):\n ", i+1);
        scanf("%d%f%f", &people[i].age, &people[i].bodyWeight, &people[i].heightCentimeters);
        bmi[i] = people[i].bodyWeight/pow(people[i].heightCentimeters/100, 2);
        if (bmi[i] > highest){
            highest = bmi[i];
            highest_idx = i+1;
        }
        if(bmi[i] < 18.5){
            printf("%d: thinness\n", i+1);
        }
        else if(bmi[i] >= 18.5 && bmi[i] < 25){
            printf("%d: %.2f - Normal\n", i+1, bmi[i]);
        }
        else if(bmi[i] >= 25 && bmi[i] < 30){
            printf("%d: %.2f - Overwheight\n", i+1, bmi[i]);
        }
        else if(bmi[i] >= 30 && bmi[i] < 35){
            printf("%d: %.2f - Obesity type I\n", bmi[i], i+1);
        }
        else if(bmi[i] >= 35 && bmi[i] < 40){
            printf("%d: %.2f - Obesity type II\n", i+1, bmi[i]);
        }
        else if(bmi[i] >= 40){
            printf("%d: %.2f - Obesity type III\n", i+1, bmi[i]);
        }
    }

    printf("The highest bmi value is %.2f from %d (st/nd/rd/th) person\n", highest, highest_idx);
    free (bmi);
    free (people);
    return 0;
}