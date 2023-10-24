#include "estoque.h"

struct produto {
  char nome[20];   // Armazena o nome do produto, sendo um array de caracteres.
  int codigo;      // Armazena o código único que identifica o produto.
  float valor;     // Armazena o valor monetário do produto.
  int data[3];     // Armazena a data de validade do produto como um array de três inteiros (dia, mês e ano).
};


struct lista {
  Produto *p;   // Ponteiro para um objeto Produto que armazena informações sobre um produto na lista.
  Lista *prox;   // Ponteiro para a próxima estrutura Lista na sequência, criando uma lista encadeada de produtos.
};


Lista* CriaLista(){
    return NULL; // Retorna um ponteiro nulo, indicando que a lista está vazia (não contém elementos)
}

//Criando um novo produto
Produto* CriaProduto(char* nome, int codigo, float valor, int* data_de_validade){
    Produto* p = (Produto*) malloc(sizeof(Produto)); // Aloca memória para uma nova estrutura de Produto

    strcpy(p->nome, nome); // Copia o nome fornecido para o campo nome da estrutura
    p->codigo = codigo; // Atribui o código fornecido ao campo código da estrutura
    p->valor = valor; // Atribui o valor fornecido ao campo valor da estrutura
    for (int i = 0; i < 3; i++) {
        p->data[i] = data_de_validade[i]; // Preenche o array de data de validade da estrutura com os valores fornecidos
    }

    return p; // Retorna o ponteiro para a nova estrutura de Produto criada e preenchida
}

//Inserindo um produto em uma lista
Lista* InsereListaProduto(Lista* l, Produto* p){
    Lista* lista = (Lista*)malloc(sizeof(Lista)); // Aloca memória para um novo nó

    lista->p = p; // Define o produto dentro do novo nó
    lista->prox = l; // Faz o novo nó apontar para o nó anterior (atual início da lista)
    // Imprime a mensagem indicando que o produto foi adicionado e seus detalhes
    fprintf(saida, "PRODUTO %s %d ADICIONADO\n", p->nome, p->codigo);
    return lista; // Retorna o novo nó como novo início da lista
}

//Retirando um produto em uma lista
Lista* RetiraListaProduto(Lista* l, int id_produto){
    Lista* ant = NULL; // Inicializa um ponteiro auxiliar para o nó anterior
    Lista* lista = l; // Inicializa uma lista auxiliar com a lista passada como parâmetro

    while (lista != NULL && lista->p->codigo != id_produto) { // Loop para encontrar o nó com o código de produto correspondente
        ant = lista; // Armazena o nó atual como nó anterior
        lista = lista->prox; // Move para o próximo nó na lista
    }

    if (lista == NULL) { // Se o nó não foi encontrado, retorna a lista original
        return l;
    }
    if (ant == NULL) { // Se o nó a ser removido é o primeiro
        l = lista->prox; // Atualiza o início da lista para o próximo nó
        // Imprime a mensagem indicando que o produto foi retirado e seus detalhes
        fprintf(saida, "PRODUTO %s %d RETIRADO\n", lista->p->nome, lista->p->codigo);
    } else { // Se o nó a ser removido não é o primeiro
        ant->prox = lista->prox; // Atualiza o ponteiro do nó anterior para apontar para o próximo nó
        // Imprime a mensagem indicando que o produto foi retirado e seus detalhes
        fprintf(saida, "PRODUTO %s %d RETIRADO\n", lista->p->nome, lista->p->codigo);
    }
    free(lista->p); // Libera a memória do produto dentro do nó
    free(lista); // Libera a memória do nó
    return l; // Retorna a lista após a remoção do produto
}

//Verificando se ha um produto em uma lista
int VerificaListaProduto(Lista* p, int id_produto){
    Lista* lista = p; // Inicializa uma lista auxiliar com a lista passada como parâmetro
    while (lista != NULL) { // Loop percorrendo a lista
        if (lista->p->codigo == id_produto) { // Verifica se o código do produto corresponde ao código fornecido
            // Imprime a mensagem indicando que o produto foi encontrado na lista
            fprintf(saida, "PRODUTO ENCONTRADO NA LISTA\n");
            return 1; // Retorna 1 para indicar que o produto foi encontrado
        }
        lista = lista->prox; // Move para o próximo nó na lista
    }
    // Se o loop for concluído sem encontrar o produto, imprime a mensagem indicando que o produto não foi encontrado
    fprintf(saida, "PRODUTO NAO ENCONTRADO NA LISTA\n");
    return 0; // Retorna 0 para indicar que o produto não foi encontrado na lista
}

//Atualizando o valor de um produto
Lista* AtualizaValor(Lista* p, int codigo, float valor){
    Lista* lista = p; // Inicializa uma lista auxiliar com a lista passada como parâmetro

    while(lista != NULL){ // Loop percorrendo a lista
        if (lista->p->codigo == codigo) { // Verifica se o código do produto corresponde ao código fornecido
            lista->p->valor = valor; // Atualiza o valor do produto
            // Imprime a mensagem indicando que o preço foi atualizado e os detalhes do produto
            fprintf(saida, "PRECO ATUALIZADO %s %d %.1f\n", lista->p->nome, lista->p->codigo, lista->p->valor);
            return p; // Retorna a lista original após a atualização
        }
        lista = lista->prox; // Move para o próximo nó na lista
    }
    return p; // Retorna a lista original caso o produto com o código não seja encontrado
}

//Verificando se existem produtos vencido em uma lista

Lista* VerificaListaValidade(Lista* p, int* data){
    Lista* lista = p; // Inicializa uma lista auxiliar com a lista passada como parâmetro
    char encontrouProduto[4] = "nao"; // Variável para controlar se um produto vencido foi encontrado
    int dia = data[0]; // Extrai o dia da data passada como parâmetro
    int mes = data[1]; // Extrai o mês da data passada como parâmetro
    int ano = data[2]; // Extrai o ano da data passada como parâmetro

    while (lista != NULL) { // Loop percorrendo a lista
        if (lista->p->data[2] < ano || // Verifica se o ano do produto é menor que o ano atual
            (lista->p->data[2] == ano && lista->p->data[1] < mes) || // Verifica se o ano é igual e o mês do produto é menor que o mês atual
            (lista->p->data[2] == ano && lista->p->data[1] == mes && lista->p->data[0] < dia)) { // Verifica se ano e mês são iguais e o dia do produto é menor que o dia atual
            fprintf(saida, "PRODUTO %s %d VENCIDO\n", lista->p->nome, lista->p->codigo); // Imprime a mensagem de produto vencido
            strcpy(encontrouProduto, "sim"); // Define que um produto vencido foi encontrado
        }
        lista = lista->prox; // Move para o próximo nó da lista
    }

    if(strcmp(encontrouProduto, "nao")){ // Verifica se um produto vencido foi encontrado
        fprintf(saida, "PRODUTO VENCIDO NAO ENCONTRADO NA LISTA\n"); // Imprime a mensagem de nenhum produto vencido encontrado
    }
    return p; // Retorna a lista original
}

//Imprimindo a lista
void ImprimeListaProdutos(Lista* p){
    Lista* lista = p; // Inicializa uma lista auxiliar com a lista passada como parâmetro
    while (lista != NULL) { // Loop percorrendo a lista
        // Imprime os detalhes do produto usando os campos da estrutura Produto
        fprintf(saida, "%s %d %.1f %d %d %d\n", lista->p->nome, lista->p->codigo, lista->p->valor, lista->p->data[0], lista->p->data[1], lista->p->data[2]);
        lista = lista->prox; // Move para o próximo da lista
    }
}

//Ordenando a lista por ordem de valor crescente
Lista* OrdenaListaValor(Lista* p){
    Lista* lista = p; // Inicializa uma lista auxiliar com a lista passada como parâmetro

    if(p == NULL){
        return p; // Retorna a lista original se estiver vazia
    }

    while (lista->prox != NULL) { // Loop percorrendo a lista até o penúltimo nó
        Lista* menorValor = lista; // Inicializa um nó para acompanhar o nó com menor valor
        Lista* aux = lista->prox; // Inicializa um nó auxiliar para percorrer os nós restantes

        while (aux != NULL) { // Loop interno para encontrar o nó com o menor valor
            if (aux->p->valor < menorValor->p->valor) {
                menorValor = aux; // Atualiza o nó com menor valor
            }
            aux = aux->prox; // Move para o próximo nó
        }

        Produto* temporario = lista->p; // Armazena temporariamente os dados do nó atual
        lista->p = menorValor->p; // Substitui os dados do nó atual pelos dados do nó com menor valor
        menorValor->p = temporario; // Restaura os dados do nó com menor valor a partir do temporário

        lista = lista->prox; // Move para o próximo nó na lista
    }
    return p; // Retorna a lista ordenada por valor
}

//Ordenando a lista por ordem de validade crescente
Lista* OrdenaListaVencimento(Lista* p){
    Lista* lista = p; // Inicializa uma lista auxiliar com a lista passada como parâmetro

    if(p == NULL){
        return p; // Retorna a lista original se estiver vazia
    }

    while (lista->prox != NULL) { // Loop percorrendo a lista até o penúltimo nó
        Lista* menorData = lista; // Inicializa um nó para acompanhar o nó com a menor data de validade
        Lista* temporaria = lista->prox; // Inicializa um nó auxiliar para percorrer os nós restantes

        while (temporaria != NULL) { // Loop interno para encontrar o nó com a menor data de validade
            if (temporaria->p->data[2] < menorData->p->data[2] || // Compara anos
                (temporaria->p->data[2] == menorData->p->data[2] && temporaria->p->data[1] < menorData->p->data[1]) || // Compara anos iguais e meses
                (temporaria->p->data[2] == menorData->p->data[2] && temporaria->p->data[1] == menorData->p->data[1] && temporaria->p->data[0] < menorData->p->data[0])) { // Compara anos e meses iguais e dias
                menorData = temporaria; // Atualiza o nó com a menor data de validade
            }
            temporaria = temporaria->prox; // Move para o próximo nó
        }

        Produto* temporario = lista->p; // Armazena temporariamente os dados do nó atual
        lista->p = menorData->p; // Substitui os dados do nó atual pelos dados do nó com a menor data de validade
        menorData->p= temporario; // Restaura os dados do nó com a menor data de validade a partir do temporário

        lista = lista->prox; // Move para o próximo nó na lista
    }

    return p; // Retorna a lista ordenada por data de validade
}

//Liberando a memoria utilizada por uma lista
void LiberaLista(Lista* l) {
    while (l != NULL) { // Loop enquanto houver nós na lista
        Lista* temp = l; // Armazena o nó atual em um nó temporário
        l = l->prox; // Move o ponteiro para o próximo nó
        free(temp->p); // Libera a memória do produto dentro do nó
        free(temp); // Libera a memória do nó
    }
}

//Função utilizada no trabalho 2

Lista* CriaListaOrdenada(int n){
    Lista* lista = NULL; // Inicializa a lista como vazia
    for (int i = n; i > 0; i--) { // Loop de n até 1
        Produto* produto = malloc(sizeof(Produto)); // Aloca memória para um Produto
        produto->valor = i; // Define o valor do Produto como i
        Lista* listaN = malloc(sizeof(Lista)); // Aloca memória para um nó de lista
        listaN->p = produto; // Atribui o Produto recém-criado ao nó de lista
        listaN->prox = lista; // Define o próximo nó como o atual início da lista
        lista = listaN; // Atualiza o início da lista para o nó recém-criado
    }
    return lista; // Retorna a lista encadeada resultante
}

