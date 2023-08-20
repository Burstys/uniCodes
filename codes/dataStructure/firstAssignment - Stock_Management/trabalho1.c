#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct lista Lista;
typedef struct produto Produto;

struct produto {
    char nome[20];
    int codigo;
    float valor;
    int data[3]; // Dia, mês, ano
};

struct lista {
    struct produto* p;
    struct lista* prox;
};

// Cria um novo produto
struct produto* CriaProduto(char* nome, int codigo, float valor, int* data_de_validade) {
    struct produto* novoProduto = (struct produto*)malloc(sizeof(struct produto));
    
    if (novoProduto != NULL) {
        strncpy(novoProduto->nome, nome, 20);
        novoProduto->codigo = codigo;
        novoProduto->valor = valor;
        memcpy(novoProduto->data, data_de_validade, 3 * sizeof(int));
    }
    
    return novoProduto;
}

// Cria uma nova lista
struct lista* CriaLista() {
    struct lista* novaLista = (struct lista*)malloc(sizeof(struct lista));
    
    if (novaLista != NULL) {
        novaLista->p = NULL;
        novaLista->prox = NULL;
    }
    
    return novaLista;
}

// Insere um produto em uma lista
struct lista* InsereListaProduto(struct lista* l, struct produto* p) {
    struct lista* novoElemento = (struct lista*)malloc(sizeof(struct lista));
    
    if (novoElemento != NULL) {
        novoElemento->p = p;
        novoElemento->prox = l;
    }
    
    return novoElemento;
}

// Retira um produto de uma determinada lista
struct lista* RetiraListaProduto(struct lista* l, int id_produto) {
    struct lista* anterior = NULL;
    struct lista* atual = l;
    
    while (atual != NULL && atual->p->codigo != id_produto) {
        anterior = atual;
        atual = atual->prox;
    }
    
    if (atual != NULL) {
        if (anterior != NULL) {
            anterior->prox = atual->prox;
        } else {
            l = atual->prox;
        }
        
        free(atual->p);
        free(atual);
    }
    
    return l;
}

// Verifica se um produto está presente em uma determinada lista
int VerificaListaProduto(struct lista* l, int id_produto) {
    struct lista* atual = l;
    
    while (atual != NULL) {
        if (atual->p->codigo == id_produto) {
            return 1;
        }
        atual = atual->prox;
    }
    
    return 0;
}

// Verifica se existe um produto vencido em uma determinada lista
struct lista* VerificaListaValidade(struct lista* l, int dia, int mes, int ano) {
    struct lista* atual = l;
    struct lista* produtosVencidos = NULL;
    
    while (atual != NULL) {
        if (atual->p->data[2] < ano ||
            (atual->p->data[2] == ano && atual->p->data[1] < mes) ||
            (atual->p->data[2] == ano && atual->p->data[1] == mes && atual->p->data[0] < dia)) {
            produtosVencidos = InsereListaProduto(produtosVencidos, atual->p);
        }
        atual = atual->prox;
    }
    
    return produtosVencidos;
}

// Função auxiliar para trocar dois elementos na lista
void TrocaElementos(struct lista* elem1, struct lista* elem2) {
    struct produto* temp = elem1->p;
    elem1->p = elem2->p;
    elem2->p = temp;
}

// Ordena lista pelo valor do produto (usando o algoritmo de seleção)
struct lista* OrdenaListaProduto(struct lista* l) {
    struct lista* atual;
    struct lista* menor;
    
    for (atual = l; atual != NULL; atual = atual->prox) {
        menor = atual;
        
        struct lista* temp = atual->prox;
        while (temp != NULL) {
            if (temp->p->valor < menor->p->valor) {
                menor = temp;
            }
            temp = temp->prox;
        }
        
        if (atual != menor) {
            TrocaElementos(atual, menor);
        }
    }
    
    return l;
}

// Ordena lista pela data de validade (usando o algoritmo de seleção)
struct lista* OrdenaListaVencimento(struct lista* l) {
    struct lista* atual;
    struct lista* menor;
    
    for (atual = l; atual != NULL; atual = atual->prox) {
        menor = atual;
        
        struct lista* temp = atual->prox;
        while (temp != NULL) {
            if (temp->p->data[2] < menor->p->data[2] ||
                (temp->p->data[2] == menor->p->data[2] && temp->p->data[1] < menor->p->data[1]) ||
                (temp->p->data[2] == menor->p->data[2] && temp->p->data[1] == menor->p->data[1] && temp->p->data[0] < menor->p->data[0])) {
                menor = temp;
            }
            temp = temp->prox;
        }
        
        if (atual != menor) {
            TrocaElementos(atual, menor);
        }
    }
    
    return l;
}

// Imprime todos os produtos de uma lista
void ImprimeListaProdutos(struct lista* l) {
    struct lista* atual = l;
    
    while (atual != NULL) {
        fprintf("%s %d %.1f %d %d %d\n", atual->p->nome, atual->p->codigo, atual->p->valor, atual->p->data[0], atual->p->data[1], atual->p->data[2]);
        atual = atual->prox;
    }
}

Lista* AtualizaValorProduto(Lista* l, int codigo, float novoValor) {
    Lista* atual = l;
    
    while (atual != NULL) {
        if (atual->p->codigo == codigo) {
            atual->p->valor = novoValor;
            printf("PRECO ATUALIZADO %s %d %.2f\n", atual->p->nome, atual->p->codigo, atual->p->valor);
            return l;
        }
        atual = atual->prox;
    }
    
    printf("PRODUTO %d NAO ENCONTRADO NA LISTA\n", codigo);
    return l;
}