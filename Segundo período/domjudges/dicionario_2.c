/*Escreva um programa para a manipulaçãoo de uma lista ligada que contenha palavras,
escritas com caracteres minúsculos.
Seu programa deve ter as funções de inserção e remoção da lista, apresentando seu
conteúdo a cada remoção.
ENTRADA: 2 inteiros N (num de palavras na lista) e M (quant de operações realizadas), 
        N palavras que devem ser armazenadas na lista
        M linhas seguintes contem inteiro e palavra (0=remover 1=inserir)
SAÍDA:  cada linha apresentará as palavras contidas na lista após operações de remoção da lista
        • Se a palavra a ser removida não estiver na lista apenas apresente a lista
        • Se a lista estiver vazia na operação de remoção escreva NULL
        • Não se deve inserir palavras repetidas na lista*/

//tentando com função para retirar repetidos

#include <stdio.h>
#include <stdlib.h>

typedef struct palavras{
    char palavra[30];
    struct palavras *prox;
}ListaPalavras;

ListaPalavras *inserir(ListaPalavras*h, char*palavraadicionar);
ListaPalavras *remover(ListaPalavras*h, char*palavraremover);
void printar(ListaPalavras*h);

int main(){
    int M, N, i, op;
    char adicionar_remover[30];
    ListaPalavras *cabeca=NULL;
    scanf("%d %d", &N, &M);

    for(i=0; i<N; i++){
        scanf(" %s", adicionar_remover);
        cabeca=inserir(cabeca,adicionar_remover);
    }

    for(i=0; i<M; i++){ //operações
        scanf(" %d", &op);
        scanf(" %s", adicionar_remover);
        if(op==0){ //remover
            cabeca=remover(cabeca,adicionar_remover);
        } else{ //adicionar
            cabeca=inserir(cabeca,adicionar_remover);
        }
    }

    return 0;
}

ListaPalavras *inserir(ListaPalavras*h, char*palavraadicionar){
    ListaPalavras *nova,*aux, *prev;

    nova=malloc(sizeof(ListaPalavras)); //alocou espaço
    strcpy(nova->palavra, palavraadicionar); //preencheu conteúdo

    if(h==NULL){ //lista vazia, o primeiro elemento adicionado (único) vira cabeça
        h=nova;
        nova->prox=NULL;
        return (h);
    }

    aux=prev=h; //começa apontando todos para o primeiro elemento
    while(aux->prox!=NULL && strcmp(aux->palavra,nova->palavra)<0){ //percorre a lista até achar onde colocar
        prev=aux;
        aux=aux->prox;
    }

    if(aux==h){ //precisa adicionar antes da cabeça
        if(strcmp(aux->palavra,nova->palavra)>0){
            h=nova;
            nova->prox=aux;
            return (h);
        } else if(strcmp(aux->palavra,nova->palavra)<0){
            h->prox=nova;
            nova->prox=NULL;
            return (h);
        } else{
            return (h);
        }
    } else{ //adicionar no meio da lista
        if(strcmp(aux->palavra,nova->palavra)>0){
            prev->prox = nova;
            nova->prox = aux;
            return (h);
        } else if(strcmp(aux->palavra,nova->palavra)<0){
            aux->prox=nova;
            nova->prox=NULL;
            return (h);
        } else{
            return (h);
        }
        
    }
    return (h);
}

ListaPalavras *remover(ListaPalavras*h, char*palavraremover){
    ListaPalavras*aux, *prev;

    aux=prev=h;
    while(aux->prox && strcmp(aux->palavra,palavraremover)!=0){
        prev=aux;
        aux=aux->prox;
    }
    if(strcmp(aux->palavra,palavraremover)==0){ //se achou
        if(aux==h){ //remover primeira palavra da lista
        h=aux->prox;
        } else{ //remove no meio da lista
            prev->prox = aux->prox;
        }
        free(aux); //libera posição retirada
    }
    printar(h);
    return (h);
}

void printar(ListaPalavras*h){
    ListaPalavras *aux;
    aux=h;
    if(h==NULL){
        printf("NULL\n");
        return;
    }
    while(aux!=NULL){
        printf("%s ", aux->palavra);
        aux = aux->prox;
    }
        printf("\n");
    return;
}