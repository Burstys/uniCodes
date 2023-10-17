#include <stdio.h>
#include <stdlib.h>
#include <time.h>

FILE* saida2;
FILE* saida3;
FILE* saida4;

void insercao(int vetor[], int n){
    int i, j;
    int aux;

    for(i = 1; i < n; i++){
        aux = vetor[i];
        j = i - 1;
        while(j >= 0 && aux < vetor[j]){
            vetor[j + 1] = vetor[j];
            j--;
        }
        vetor[j + 1] = aux;
    }
}

void insertionSort(int arr[], int n)
{
    int i, key, j;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

void selecao(int vetor[], int n){
    int i, j, min;

    for( i = 0; i < n -1; i++){
        min = 1;
        for(j = i + 1; j < n; j++){
            if(vetor[j] < vetor[min]){
                min  = j;
            }
         int aux;
         aux = vetor[i];
         vetor[i] = vetor[min];
         vetor[min] = aux;
        }
    }
}

void bolha(int vetor[], int n){
    int i , j;

    for( i = 0; i < n-1; i++){
        for(j = 0; j < n-i; j++){
            if(vetor[j] < vetor[j-1]){
                int aux;
                aux = vetor[j-1];
                vetor[j-1] = vetor[j];
                vetor[j] = aux;
            }
        }
    }
}

int main() {
    int tamanhos_vetor[10] = {5000, 10000, 15000, 20000, 25000, 30000, 35000, 40000, 45000, 50000}; // Array com tamanhos de lista
    double tempos[30][10]; // Matriz para armazenar os tempos de execução;
    double tempos2[30][10];
    double tempos3[30][10];
    //int vetor[];
    saida2 = fopen("./saida2.txt", "w");
    saida3 = fopen("./saida3.txt", "w");
    saida4 = fopen("./saida4.txt", "w");

    // Loop para iterar pelos diferentes tamanhos de lista
    for (int coluna = 0; coluna < 10; coluna++) {
        int n = tamanhos_vetor[coluna]; // Tamanho atual da lista
        int vetor[n];
        // Loop para repetir a medição do tempo de execução 30 vezes
        for (int linha = 0; linha < 30; linha++) {
            for(int i=n,j=0; j<n;j++,i--){
                vetor[j] = i;
                //printf("%d", vetor[i]);
            }
            // Medir o tempo de execução

            clock_t inicio = clock(); // Marca o tempo de início
            insertionSort(vetor, n); // Chama a função para ordenar a lista
            clock_t fim = clock(); // Marca o tempo de fim

            clock_t inicio2 = clock(); // Marca o tempo de início
            selecao(vetor, n); // Chama a função para ordenar a lista
            clock_t fim2 = clock();

            clock_t inicio3 = clock();
            bolha(vetor, n);
            clock_t fim3 = clock();

            // Calcular tempo em segundos
            double tempo_execucao = (double)(fim - inicio) / CLOCKS_PER_SEC; // Calcula o tempo de execução em segundos
            double tempo_execucao2 = (double)(fim2 - inicio2) / CLOCKS_PER_SEC;
            double tempo_execucao3 = (double)(fim3 - inicio3) / CLOCKS_PER_SEC;

            tempos[linha][coluna] = tempo_execucao; // Armazena o tempo na matriz
            tempos2[linha][coluna] = tempo_execucao2;
            tempos3[linha][coluna] = tempo_execucao3;

            fprintf(saida2, "%lf ", tempos[linha][coluna]); // Escreve o tempo no arquivo
            fprintf(saida3, "%lf ", tempos2[linha][coluna]);
            fprintf(saida4, "%lf ", tempos3[linha][coluna]);
        }
        fprintf(saida2, "\n");
        fprintf(saida3, "\n");
        fprintf(saida4, "\n");
    }
    fclose(saida2);
    fclose(saida3);
    fclose(saida4);
    return 0; // Retorna 0 para indicar sucesso
}