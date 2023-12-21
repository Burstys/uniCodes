#include <stdio.h>
#include <stdlib.h>

/*Direct data rearrangement
struct item a;
struct item b;
struct item aux = a;
a = b;
b = aux;

Indirect data rearrangement

struct item *a;
struct item *b;
struct item *aux = *a;
a = b;
b = aux;
*/

void selectionSort (int array[], int value){
    int i, j, min;
    for (i=0; i < value -1; i++){
        min = i;
        for (j = i + 1; j < value; j++){
            if (array[j] < array[min]){
                min = j;
            }
        }
        int aux = array[i];
        array[i] = array[min];
        array[min] = aux;
    }
}

void insertionSort(int array[], int value){
    int i, key, j;
    for (i = 1; i < value; i++) {
        key = array[i];
        j = i - 1;

        while (j >= 0 && array[j] > key) {
            array[j + 1] = array[j];
            j = j - 1;
        }
        array[j + 1] = key;
    }
}

void bubbleSort(int array[], int value){
    int i, j;
    for (i=0; i < value-1; i++){
        for (j=1; j < value-i; j++){
            if(array[j] < array[j-1]){
                int aux = array[j-1];
                array[j-1] = array[j];
                array[j] = aux;
            }
        }
    }
}

void merge(int array[], int p, int q, int r){
    int auxArray[r-p+1];
    int i = 0, j = 0;
    for(i = p; i<q; i++){
        auxArray[i] = array[i];
        printf("%d\n", auxArray[i]);
    }
    for(j = q+1; j<r; j++){
        auxArray[r+q+1-j] = array[j];
        printf("asdf %d\n", auxArray[r+q+1-j]);
    }
    i = p;
    j = r;

    for(int k = p; k<r; k++){
        if(auxArray[i]<=auxArray[j]){
            array[k] = auxArray[i];
            i++;
        }
        else{
            array[k] = auxArray[j];
            j--;
        }
    }
}

void mergeSort(int array[], int p, int r){
    if (p < r){
        int q = (p + r)/2;
        mergeSort(array, p, q);
        mergeSort(array, q+1, r);
        merge(array, p, q, r);
    }
}