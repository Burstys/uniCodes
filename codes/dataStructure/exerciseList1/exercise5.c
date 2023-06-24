#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*Faça um programa que leia n pontos (x,y), calcule o ponto médio (xm, ym) e apresente a distância do ponto mais próximo do ponto médio.
Use struct e calloc.*/

typedef struct point Point;

struct point{
    float x;
    float y;
};

int main(){
    int n;
    Point *point;
    float  mpx=0, mpy=0, dist=0, lowest = 1000;
    point = (Point*)calloc(n, sizeof(Point)); 
    printf("Type the amount of points: \n");
    scanf("%d", &n);
    for(int i = 0; i<n; i++){
        printf("Type point %d 's X and Y coordinates: \n", i+1);
        scanf("%f%f", &point[i].x, &point[i].y);
        mpx += point[i].x;
        mpy += point[i].y;
    }
    mpx = mpx/n;
    mpy = mpy/n;

    for (int i=0; i<n; i++){    
        dist = sqrt((pow(mpx - point[i].x, 2)) + (pow(mpy - point[i].y, 2)));
        if (dist < lowest){
            lowest = dist;
        }
    }

    printf("Shortest distance: %.2f\n", lowest);

    free (point);
    return 0;
}