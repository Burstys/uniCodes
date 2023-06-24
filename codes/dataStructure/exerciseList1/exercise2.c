#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*Crie um programa utilizando struct e calloc que leia a informação de peso(N) e área da base (m²) de n objetos e calcule a pressão de cada objeto.
Pressão = peso (N)/área (m²)*/

typedef struct object Object;
struct object{
    float weight;
    float baseArea;
};

int main(){
    int n;
    printf("Insert how many objects' pressure are gonna be calculated: \n");
    scanf("%d", &n);
    
    float *pressure;
    pressure = (float*)calloc(n, sizeof(float));

    Object *object;
    object = (Object*)calloc(n, sizeof(Object));
    
    for(int i=0;i<n;i++){
        printf("Insert %d's weight and base area: \n", i+1);
        scanf("%f%f", &object[i].weight, &object[i].baseArea);
        pressure[i] = object[i].weight/object[i].baseArea;
        printf("%d's pressure: %.2f\n", i+1, pressure[i]);
    }

    free(pressure);
    free(object);
    return 0;
}
