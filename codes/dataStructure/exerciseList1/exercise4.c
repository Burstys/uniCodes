#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <math.h>

/*Faça um programa utilizando calloc e struct que irá receber as notas de três avaliações de n pessoas, armazene em um vetor
, calcule a média final de cada prova e apresente a maior nota.*/

typedef struct student Student;
struct student{
    float grade1;
    float grade2;
    float grade3;
};

int main(){
    int n;
    float average_g1=0, average_g2=0, average_g3=0;
   
    printf("Enter how many students are being considered: \n");
    scanf("%d", &n);

    Student *student;
    student = (Student*)calloc(n, sizeof(Student));

    for (int i=0;i<n;i++){
        printf("Type student number %d's grades 1 to 3:\n", i+1);
        scanf("%f%f%f", &student[i].grade1, &student[i].grade2, &student[i].grade3);
        average_g1 += student[i].grade1/n;
        average_g2 += student[i].grade2/n;
        average_g3 += student[i].grade3/n;
    }
    printf("|--------------- Grades ---------------|\n");
    printf("   First test average grade: %2.f\n   Second test average grade: %2.f\n   Third test average grade: %2.f\n", average_g1, average_g2, average_g3);
    printf("|--------------------------------------|\n");
    free (student);
    return 0;
}