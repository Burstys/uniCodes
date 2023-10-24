#include "estoque.h"

FILE* arquivoEntrada;
FILE* saida;

int main(){
    char acao[50];
    char nome[50];
    int id;
    float valor;
    int data[3];

    arquivoEntrada = fopen("./entrada.txt", "r");
    saida = fopen("./saida.txt", "w");

    Lista* listaPrincipal = CriaLista();

    while(fscanf(arquivoEntrada, "%s", acao) == 1 && strcmp(acao, "FIM") != 0){
        //Verifica se o comando � para inserir produtos
        if (strcmp(acao, "PRODUTO")==0){
            fscanf(arquivoEntrada, "%s %d %f %d %d %d", nome, &id, &valor, &data[0], &data[1], &data[2]);
            Produto* novoProduto = CriaProduto(nome, id, valor, data);
            listaPrincipal = InsereListaProduto(listaPrincipal, novoProduto);
        }
        //Verifica se o comando � para retirar produtos
        else if(strcmp(acao, "RETIRA")==0){
            fscanf(arquivoEntrada, "%d", &id);
            listaPrincipal = RetiraListaProduto(listaPrincipal, id);
        }
        //Verifica se o comando � para imprimir a lista
        else if(strcmp(acao, "IMPRIME_LISTA")==0){
            ImprimeListaProdutos(listaPrincipal);
        }
        //Verifica se o comando � para atualizar pre�oes
        else if(strcmp(acao, "ATUALIZA_PRECO")==0){
            fscanf(arquivoEntrada, "%d %f", &id, &valor);
            listaPrincipal = AtualizaValor(listaPrincipal, id, valor);
        }
        //Verifica se o comando � para verificar se h� produtos vencidos
        else if(strcmp(acao, "VERIFICA_VALIDADE")==0){
            fscanf(arquivoEntrada, "%d %d %d", &data[0], &data[1], &data[2]);
            listaPrincipal = VerificaListaValidade(listaPrincipal, data);
        }
        //Verifica se o comando � para verificar se h� determinando produto em uma lista
        else if(strcmp(acao, "VERIFICA_LISTA")==0){
            fscanf(arquivoEntrada, "%d", &id);
            VerificaListaProduto(listaPrincipal, id);
        }
        //Verifica se o comando � para ordenar a lista de acordo com a validade
        else if(strcmp(acao, "ORDENA_LISTA_VALIDADE")==0){
            listaPrincipal = OrdenaListaVencimento(listaPrincipal);
        }
        //Verifica se o comando � para ordenar a lista de acordo com o valor
        else if(strcmp(acao, "ORDENA_LISTA_VALOR")==0){
            listaPrincipal = OrdenaListaValor(listaPrincipal);
        }
    }

    fclose(arquivoEntrada);
    fclose(saida);
    LiberaLista(listaPrincipal);
    return 0;
}

