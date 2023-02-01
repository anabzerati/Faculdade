/*novo dicionário
programa para manipulação de uma lista ligada que contenha palavras. Funções de inserção e remoção, apresentando parte do conteúdo a cada solicitação
ENTRADA: N (número inicial de palavras) e M (número de operações), N palavras separadas por espaços em branco para serem armazenadas
M linhas seguintes com um inteiro e uma palavra - 1=inserida, 0=removida, 2=imprimir conteúdo a partir da palavra
SAÍDA: imprimir palavras seguintes da indicada no comando 2
obs: sub-lista vazia = imrpime NULL
se a palavra chave de impressão fizer parte da lista, deve ser impressa
não inserir palavras repetidas na lista 
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct dicionario{
    char palavra[100];
    struct dicionario *prox;
}lista_palavra;

void inserir(lista_palavra **h, char *inserir);
void testar(lista_palavra *h);
void remover(lista_palavra **h, char *elem);
void imprimir(lista_palavra *h, char *palavra);

int main(){
    int i, N, M, op;
    char palavra_inserida[100];

    lista_palavra *h, *novo;
    h = NULL;

    scanf("%d %d", &N, &M);
    for(i=0; i<N; i++){
        scanf(" %s", palavra_inserida);
        inserir(&h, palavra_inserida);
    }

    for(i=0; i<M; i++){
        scanf("%d", &op);
        scanf("%s", palavra_inserida);
        if(op == 0){ //remover
            remover(&h, palavra_inserida);
        } else if(op == 1){ //inserir
            inserir(&h, palavra_inserida);
        } else{ //imprimir a partir da palavra
            imprimir(h, palavra_inserida);
        }
    }



    return 0;
}

void inserir(lista_palavra **h, char *inserir){
    lista_palavra *novo, *aux, *prev;

    novo = malloc(sizeof(lista_palavra));
    strcpy(novo->palavra, inserir);
    novo->prox = NULL;

    if((*h) == NULL){
        (*h) = novo;
        return;
    }

    aux = prev = (*h);
    while(aux->prox && strcmp(aux->palavra, novo->palavra)<0){
        prev = aux;
        aux = aux->prox;
    }


    if(aux == (*h)){
        if(strcmp(novo->palavra, (*h)->palavra) < 0){ //insere antes da cabeça
            novo->prox = (*h);
            (*h) = novo;
            return;
        } else if(strcmp(novo->palavra, (*h)->palavra) > 0){ //insere dps da cabeça
            (*h)->prox = novo;
            return;
        } else{ //palavras iguais, não insere mais uma vez
            return;
        }
    }

    if(strcmp(novo->palavra,aux->palavra)>0){ //novo vem depois de auxiliar
        aux->prox = novo; 
    } else if(strcmp(novo->palavra, aux->palavra) < 0){ //vem antes do auxiliar
        prev->prox = novo;
        novo->prox = aux;
    }
    return;

}

void testar(lista_palavra *h){
    lista_palavra *aux = h;
    while(aux){
        printf("%s ", aux->palavra);
        aux = aux->prox;
    }
}

void remover(lista_palavra **h, char *elem){
    lista_palavra *aux, *prev;
    aux = prev = (*h);

    if((*h) == NULL){
        return;
    }

    while(aux->prox && strcmp(elem, aux->palavra)!=0){
        prev = aux;
        aux = aux->prox;
    }

    if(strcmp(elem, aux->palavra) == 0){ //a palavra desejada está na lista
        if((*h) == aux){
            (*h) = aux->prox;
            free(aux);
            return;
        }

        prev->prox = aux->prox;
        free(aux);
        return;
    }

    return;
}

void imprimir(lista_palavra *h, char *palavra){
    lista_palavra *aux = h;

    while(aux && strcmp(palavra, aux->palavra)>0){
        aux = aux->prox;
    }

    if(aux == NULL){ //não há nada para imprimir
        printf("NULL\n");
        return;
    }

    while(aux){
        printf("%s ", aux->palavra);
        aux = aux->prox;
    }
    printf("\n");
}