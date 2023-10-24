#include "estoque.h"
#include <time.h>
FILE* saida2;

int main() {
    int tamanhos_lista[10] = {5000, 10000, 15000, 20000, 25000, 30000, 35000, 40000, 45000, 50000}; // Array com tamanhos de lista
    double tempos[30][10]; // Matriz para armazenar os tempos de execução

    saida2 = fopen("./saida2.txt", "w"); // Abre o arquivo "saida2.txt" para escrita

    // Loop para iterar pelos diferentes tamanhos de lista
    for (int coluna = 0; coluna < 10; coluna++) {
        int n = tamanhos_lista[coluna]; // Tamanho atual da lista
        // Loop para repetir a medição do tempo de execução 30 vezes
        for (int linha = 0; linha < 30; linha++) {
            Lista* lista = CriaListaOrdenada(n); // Cria uma lista ordenada com tamanho n

            // Medir o tempo de execução
            clock_t inicio = clock(); // Marca o tempo de início
            OrdenaListaValor(lista); // Chama a função para ordenar a lista
            clock_t fim = clock(); // Marca o tempo de fim

            // Calcular tempo em segundos
            double tempo_execucao = (double)(fim - inicio) / CLOCKS_PER_SEC; // Calcula o tempo de execução em segundos

            tempos[linha][coluna] = tempo_execucao; // Armazena o tempo na matriz
            fprintf(saida2, "%lf ", tempos[linha][coluna]); // Escreve o tempo no arquivo

            LiberaLista(lista); // Libera a memória alocada para a lista
        }
        fprintf(saida2, "\n"); // Escreve uma quebra de linha no arquivo após cada conjunto de tempos
    }

    fclose(saida2); // Fecha o arquivo
    return 0; // Retorna 0 para indicar sucesso
}
