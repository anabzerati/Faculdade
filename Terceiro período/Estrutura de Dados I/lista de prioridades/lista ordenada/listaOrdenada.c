#include <stdlib.h>
#include "listaOrdenada.h"

No *inserir(No *head, int chave){
    No *novo = malloc(sizeof(No));
    novo->chave = chave;
    novo->prox = NULL;

    if(!head){
        return novo; //raiz
    }

    No *aux, *prev;
    aux = prev = head;

    while(aux->prox && aux->chave > chave){
        prev = aux;
        aux = aux->prox;
    }

    if(aux == head){
        novo->prox = aux;
        return novo; //nova raiz
    } else{
        prev->prox = novo;
        novo->prox = aux;
        return head;
    }   
}

No *remover(No **head){
    if(!head){
        return NULL;
    }

    No *aux = *head;
    *head = (*head)->prox;

    return aux;
}

No *buscar(No *head, int chave){
    if(!head || head->chave == chave){
        return head;
    }

    No *aux;
    while(aux->prox && aux->chave > chave){
        aux = aux->prox;
    }

    return aux;
}

void percorrer(No *head){
    No *aux = head;

    while(aux){
        printf("%d ", aux->chave);
        aux = aux->prox;
    }
}