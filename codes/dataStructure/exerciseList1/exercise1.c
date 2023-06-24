#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*Faça um programa utilizando struct e malloc, que leia a informação do raio de n círculos e calcule a circunferência e área.
Circunferência = 2*pi*r; Área = pi*r²*/

typedef struct circle Circle;
struct circle{
    float radius;
};

int main(){
    int n;
    printf("Enter the amount of circles to be used: \n");
    scanf("%d", &n);

    float *circumference = 0, *area = 0;
    circumference = (float*)malloc(n*sizeof(float));
    area = (float*)malloc(n*sizeof(float));
    
    Circle *circle;
    circle = (Circle*)malloc(n*sizeof(Circle));

    for(int i = 0;i<n;i++){
        printf("%d radius: \n", i+1);
        scanf("%f", &circle[i].radius);
        circumference[i] = 2*3.14*circle[i].radius;
        area[i] = 3.14*pow(circle[i].radius, 2); 
        printf("Circle number %d circumference and area: %.2f - %.2f\n", i+1, circumference[i], area[i]);
    }

    free (circumference);
    free (area);
    free (circle);
    return 0;
}