#include "estoque.h"

struct produto {
  char nome[20];   // Armazena o nome do produto, sendo um array de caracteres.
  int codigo;      // Armazena o c�digo �nico que identifica o produto.
  float valor;     // Armazena o valor monet�rio do produto.
  int data[3];     // Armazena a data de validade do produto como um array de tr�s inteiros (dia, m�s e ano).
};


struct lista {
  Produto *p;   // Ponteiro para um objeto Produto que armazena informa��es sobre um produto na lista.
  Lista *prox;   // Ponteiro para a pr�xima estrutura Lista na sequ�ncia, criando uma lista encadeada de produtos.
};


Lista* CriaLista(){
    return NULL; // Retorna um ponteiro nulo, indicando que a lista est� vazia (n�o cont�m elementos)
}

//Criando um novo produto
Produto* CriaProduto(char* nome, int codigo, float valor, int* data_de_validade){
    Produto* p = (Produto*) malloc(sizeof(Produto)); // Aloca mem�ria para uma nova estrutura de Produto

    strcpy(p->nome, nome); // Copia o nome fornecido para o campo nome da estrutura
    p->codigo = codigo; // Atribui o c�digo fornecido ao campo c�digo da estrutura
    p->valor = valor; // Atribui o valor fornecido ao campo valor da estrutura
    for (int i = 0; i < 3; i++) {
        p->data[i] = data_de_validade[i]; // Preenche o array de data de validade da estrutura com os valores fornecidos
    }

    return p; // Retorna o ponteiro para a nova estrutura de Produto criada e preenchida
}

//Inserindo um produto em uma lista
Lista* InsereListaProduto(Lista* l, Produto* p){
    Lista* lista = (Lista*)malloc(sizeof(Lista)); // Aloca mem�ria para um novo n�

    lista->p = p; // Define o produto dentro do novo n�
    lista->prox = l; // Faz o novo n� apontar para o n� anterior (atual in�cio da lista)
    // Imprime a mensagem indicando que o produto foi adicionado e seus detalhes
    fprintf(saida, "PRODUTO %s %d ADICIONADO\n", p->nome, p->codigo);
    return lista; // Retorna o novo n� como novo in�cio da lista
}

//Retirando um produto em uma lista
Lista* RetiraListaProduto(Lista* l, int id_produto){
    Lista* ant = NULL; // Inicializa um ponteiro auxiliar para o n� anterior
    Lista* lista = l; // Inicializa uma lista auxiliar com a lista passada como par�metro

    while (lista != NULL && lista->p->codigo != id_produto) { // Loop para encontrar o n� com o c�digo de produto correspondente
        ant = lista; // Armazena o n� atual como n� anterior
        lista = lista->prox; // Move para o pr�ximo n� na lista
    }

    if (lista == NULL) { // Se o n� n�o foi encontrado, retorna a lista original
        return l;
    }
    if (ant == NULL) { // Se o n� a ser removido � o primeiro
        l = lista->prox; // Atualiza o in�cio da lista para o pr�ximo n�
        // Imprime a mensagem indicando que o produto foi retirado e seus detalhes
        fprintf(saida, "PRODUTO %s %d RETIRADO\n", lista->p->nome, lista->p->codigo);
    } else { // Se o n� a ser removido n�o � o primeiro
        ant->prox = lista->prox; // Atualiza o ponteiro do n� anterior para apontar para o pr�ximo n�
        // Imprime a mensagem indicando que o produto foi retirado e seus detalhes
        fprintf(saida, "PRODUTO %s %d RETIRADO\n", lista->p->nome, lista->p->codigo);
    }
    free(lista->p); // Libera a mem�ria do produto dentro do n�
    free(lista); // Libera a mem�ria do n�
    return l; // Retorna a lista ap�s a remo��o do produto
}

//Verificando se ha um produto em uma lista
int VerificaListaProduto(Lista* p, int id_produto){
    Lista* lista = p; // Inicializa uma lista auxiliar com a lista passada como par�metro
    while (lista != NULL) { // Loop percorrendo a lista
        if (lista->p->codigo == id_produto) { // Verifica se o c�digo do produto corresponde ao c�digo fornecido
            // Imprime a mensagem indicando que o produto foi encontrado na lista
            fprintf(saida, "PRODUTO ENCONTRADO NA LISTA\n");
            return 1; // Retorna 1 para indicar que o produto foi encontrado
        }
        lista = lista->prox; // Move para o pr�ximo n� na lista
    }
    // Se o loop for conclu�do sem encontrar o produto, imprime a mensagem indicando que o produto n�o foi encontrado
    fprintf(saida, "PRODUTO NAO ENCONTRADO NA LISTA\n");
    return 0; // Retorna 0 para indicar que o produto n�o foi encontrado na lista
}

//Atualizando o valor de um produto
Lista* AtualizaValor(Lista* p, int codigo, float valor){
    Lista* lista = p; // Inicializa uma lista auxiliar com a lista passada como par�metro

    while(lista != NULL){ // Loop percorrendo a lista
        if (lista->p->codigo == codigo) { // Verifica se o c�digo do produto corresponde ao c�digo fornecido
            lista->p->valor = valor; // Atualiza o valor do produto
            // Imprime a mensagem indicando que o pre�o foi atualizado e os detalhes do produto
            fprintf(saida, "PRECO ATUALIZADO %s %d %.1f\n", lista->p->nome, lista->p->codigo, lista->p->valor);
            return p; // Retorna a lista original ap�s a atualiza��o
        }
        lista = lista->prox; // Move para o pr�ximo n� na lista
    }
    return p; // Retorna a lista original caso o produto com o c�digo n�o seja encontrado
}

//Verificando se existem produtos vencido em uma lista

Lista* VerificaListaValidade(Lista* p, int* data){
    Lista* lista = p; // Inicializa uma lista auxiliar com a lista passada como par�metro
    char encontrouProduto[4] = "nao"; // Vari�vel para controlar se um produto vencido foi encontrado
    int dia = data[0]; // Extrai o dia da data passada como par�metro
    int mes = data[1]; // Extrai o m�s da data passada como par�metro
    int ano = data[2]; // Extrai o ano da data passada como par�metro

    while (lista != NULL) { // Loop percorrendo a lista
        if (lista->p->data[2] < ano || // Verifica se o ano do produto � menor que o ano atual
            (lista->p->data[2] == ano && lista->p->data[1] < mes) || // Verifica se o ano � igual e o m�s do produto � menor que o m�s atual
            (lista->p->data[2] == ano && lista->p->data[1] == mes && lista->p->data[0] < dia)) { // Verifica se ano e m�s s�o iguais e o dia do produto � menor que o dia atual
            fprintf(saida, "PRODUTO %s %d VENCIDO\n", lista->p->nome, lista->p->codigo); // Imprime a mensagem de produto vencido
            strcpy(encontrouProduto, "sim"); // Define que um produto vencido foi encontrado
        }
        lista = lista->prox; // Move para o pr�ximo n� da lista
    }

    if(strcmp(encontrouProduto, "nao")){ // Verifica se um produto vencido foi encontrado
        fprintf(saida, "PRODUTO VENCIDO NAO ENCONTRADO NA LISTA\n"); // Imprime a mensagem de nenhum produto vencido encontrado
    }
    return p; // Retorna a lista original
}

//Imprimindo a lista
void ImprimeListaProdutos(Lista* p){
    Lista* lista = p; // Inicializa uma lista auxiliar com a lista passada como par�metro
    while (lista != NULL) { // Loop percorrendo a lista
        // Imprime os detalhes do produto usando os campos da estrutura Produto
        fprintf(saida, "%s %d %.1f %d %d %d\n", lista->p->nome, lista->p->codigo, lista->p->valor, lista->p->data[0], lista->p->data[1], lista->p->data[2]);
        lista = lista->prox; // Move para o pr�ximo da lista
    }
}

//Ordenando a lista por ordem de valor crescente
Lista* OrdenaListaValor(Lista* p){
    Lista* lista = p; // Inicializa uma lista auxiliar com a lista passada como par�metro

    if(p == NULL){
        return p; // Retorna a lista original se estiver vazia
    }

    while (lista->prox != NULL) { // Loop percorrendo a lista at� o pen�ltimo n�
        Lista* menorValor = lista; // Inicializa um n� para acompanhar o n� com menor valor
        Lista* aux = lista->prox; // Inicializa um n� auxiliar para percorrer os n�s restantes

        while (aux != NULL) { // Loop interno para encontrar o n� com o menor valor
            if (aux->p->valor < menorValor->p->valor) {
                menorValor = aux; // Atualiza o n� com menor valor
            }
            aux = aux->prox; // Move para o pr�ximo n�
        }

        Produto* temporario = lista->p; // Armazena temporariamente os dados do n� atual
        lista->p = menorValor->p; // Substitui os dados do n� atual pelos dados do n� com menor valor
        menorValor->p = temporario; // Restaura os dados do n� com menor valor a partir do tempor�rio

        lista = lista->prox; // Move para o pr�ximo n� na lista
    }
    return p; // Retorna a lista ordenada por valor
}

//Ordenando a lista por ordem de validade crescente
Lista* OrdenaListaVencimento(Lista* p){
    Lista* lista = p; // Inicializa uma lista auxiliar com a lista passada como par�metro

    if(p == NULL){
        return p; // Retorna a lista original se estiver vazia
    }

    while (lista->prox != NULL) { // Loop percorrendo a lista at� o pen�ltimo n�
        Lista* menorData = lista; // Inicializa um n� para acompanhar o n� com a menor data de validade
        Lista* temporaria = lista->prox; // Inicializa um n� auxiliar para percorrer os n�s restantes

        while (temporaria != NULL) { // Loop interno para encontrar o n� com a menor data de validade
            if (temporaria->p->data[2] < menorData->p->data[2] || // Compara anos
                (temporaria->p->data[2] == menorData->p->data[2] && temporaria->p->data[1] < menorData->p->data[1]) || // Compara anos iguais e meses
                (temporaria->p->data[2] == menorData->p->data[2] && temporaria->p->data[1] == menorData->p->data[1] && temporaria->p->data[0] < menorData->p->data[0])) { // Compara anos e meses iguais e dias
                menorData = temporaria; // Atualiza o n� com a menor data de validade
            }
            temporaria = temporaria->prox; // Move para o pr�ximo n�
        }

        Produto* temporario = lista->p; // Armazena temporariamente os dados do n� atual
        lista->p = menorData->p; // Substitui os dados do n� atual pelos dados do n� com a menor data de validade
        menorData->p= temporario; // Restaura os dados do n� com a menor data de validade a partir do tempor�rio

        lista = lista->prox; // Move para o pr�ximo n� na lista
    }

    return p; // Retorna a lista ordenada por data de validade
}

//Liberando a memoria utilizada por uma lista
void LiberaLista(Lista* l) {
    while (l != NULL) { // Loop enquanto houver n�s na lista
        Lista* temp = l; // Armazena o n� atual em um n� tempor�rio
        l = l->prox; // Move o ponteiro para o pr�ximo n�
        free(temp->p); // Libera a mem�ria do produto dentro do n�
        free(temp); // Libera a mem�ria do n�
    }
}

//Fun��o utilizada no trabalho 2

Lista* CriaListaOrdenada(int n){
    Lista* lista = NULL; // Inicializa a lista como vazia
    for (int i = n; i > 0; i--) { // Loop de n at� 1
        Produto* produto = malloc(sizeof(Produto)); // Aloca mem�ria para um Produto
        produto->valor = i; // Define o valor do Produto como i
        Lista* listaN = malloc(sizeof(Lista)); // Aloca mem�ria para um n� de lista
        listaN->p = produto; // Atribui o Produto rec�m-criado ao n� de lista
        listaN->prox = lista; // Define o pr�ximo n� como o atual in�cio da lista
        lista = listaN; // Atualiza o in�cio da lista para o n� rec�m-criado
    }
    return lista; // Retorna a lista encadeada resultante
}

