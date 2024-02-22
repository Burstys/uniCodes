#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define VAZIO "!!!!!!!!!\0"
#define N 16

//Programa que gera um peso para cada caractere de uma chave constituida de n caracteres
void geraPesos(int p[], int n){
    int i;
    srand(time(NULL));
    for(i = 0; i < n; i++){
        p[i] = 1 + (int) (10000.0*rand()/(RAND_MAX));
    }
}

// Implementação da função de transformação
int h(char *chave, int p[], int m, int tam_p){
    int i;
    unsigned int soma = 0;
    int comp = strlen(chave);

    for (i = 0; i < comp; i++){
        soma += (unsigned int) chave[i] * p[i % tam_p];
    }

    return (soma % m);
}

// Tratamento de colisões usando listas encadeadas
typedef char TChave[N];
typedef struct {
    TChave chave;
} TItem;

typedef struct celula{
    struct celula *pProx;
    TItem item;
} TCelula;

typedef struct {
    TCelula *pPrimeiro, *pUltimo;
} TLista;

typedef struct {
    int n; //numero de itens na hash
    int n_listas; //tamanho do array de listas
    int n_pesos; //tamanho do array de pesos
    int *p; //array de pesos
    TLista *v; //array de listas
} THash;

// Inicializa a hash. Parametros: p = numero de pesos; m = tamanho do vetor de listas
void THash_inicia(THash *hash, int n_listas, int n_pesos){
    int i;
    hash->n = 0;
    hash->n_listas = n_listas;
    hash->n_pesos = n_pesos;

    //Inicializando as listas
    hash->v = (TLista *) malloc(sizeof(TLista) * n_listas);
    for (i=0; i<n_listas; i++){
        TLista_Inicia(&hash->v[i]);
    }

    //Inicializando os pesos
    hash->p = (int *) malloc(sizeof(int) * n_pesos);
    for (i=0; i<n_pesos; i++){
        hash->p[i] = rand()%100000;
    }
}

// Funcao de hash que retorna o indice (n inteiro) de uma chave (string)
int THash_H(THash *hash, TChave chave){
    int i;
    unsigned int soma = 0;
    int comp = strlen(chave);

    for (i = 0; i < comp; i++){
        soma += (unsigned int) chave[i] * hash->p[i % hash->n_pesos];
    }

    return (soma % hash->n_listas);
}

// Retorna o pontieor apontando para a celula anterior da lista
TCelula *THash_PesquisaCelula(THash *hash, TChave chave){
    int i = THash_H(hash, chave);
    TCelula *aux;

    if (Tlista_EhVazia(&hash->v[i])){
        return NULL; //pesquisa sem sucesso
    }

    aux = hash->v[i].pPrimeiro;
    while (aux->pProx->pProx != NULL && strcmp(chave, aux->pProx->item.chave) != 0){
        aux = aux->pProx;
    }

    if(!strncmp(chave, aux->pProx->item.chave, sizeof(TChave))){
        return aux;
    }
    else{
        return NULL; //pesquisa sem sucesso
    }
}

//Retorna se a pesquisa foi bem sucedida e o item x por meio da passagem por referência
int THash_Pesquisa(THash *hash, TChave chave, TItem *x){
    TCelula *aux = THash_PesquisaCelula(hash, chave);
    if(aux == NULL){
        return 0;
    }
    *x = aux->pProx->item;
    return 1;
}

//Insere um item na hash
int THash_Insere(THash *hash, TItem x){
    if (THash_PesquisaCelula(hash, x.chave) == NULL){
        TLista_Insere(&hash->v[THash_H(hash, x.chave)], x);
        hash->n++;
        return 1;
    }
    return 0;
}

//Remove um item da hash
int THash_Remove(THash *hash, TItem *x){
    TCelula *aux = THash_PesquisaCelula(hash, x->chave);
    if(aux == NULL){
        return 0;
    }
    TLista_Remove(&hash->v[THash_H(hash, x->chave)], aux, x);
    hash->n--;
    return 1;
}

// Tratamento de colisões usando endereçamento aberto
//considerando M = 7

int M = 7;

typedef TItem TDicionario[7];

void TDicionario_Inicia(TDicionario dic){
    int i;
    for (i=0;i<M;i++){
        memcpy(dic[i].chave, VAZIO, N);
    }
}

int TDicionario_Pesquisa(TDicionario dic, TChave chave, int p){
    int i = 0;
    int ini = h(chave, p);

    while (strcmp(dic[(ini + i) % M].chave, VAZIO) != 0 &&
            strcmp(dic[(ini+i) % M].chave, chave) != 0 && i < M){
                i++;
            }
    if (strcmp(dic[(ini+i) % M].chave, chave)==0){
        return (ini + i) % M;
    }
    return -1;
}

int TDicionario_Insere(TDicionario dic, TItem x, int p){
    if(TDicionario_Pesquisa(dic, x.chave, p) >= 0){
        return 0;
    }

    int i = 0;
    int ini = h(x.chave, p);
    while (strcmp(dic[(ini + i) % M].chave, VAZIO) != 0 && i < M){
        i++;
    }
    if(i<M){
        dic[(ini + i) % M] = x;
        return 1;
    }
    return 0;
}

int TDicionario_Retira(TDicionario dic, TItem *x, int p){
    int i = TDicionario_Pesquisa(dic, x->chave, p);
    if (i==-1){
        return 0;
    }
    memcpy(dic[i].chave, VAZIO, N);
    return 1;
}

