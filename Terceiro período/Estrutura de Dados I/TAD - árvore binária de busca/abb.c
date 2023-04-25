#include <stdio.h>
#include <stdlib.h>
#include "abb.h"

/*Implementação de funções*/
tree inserir(tree root, int chave){
    if(root == NULL){
        tree aux = malloc(sizeof(struct node));
        aux->info.chave = chave;
        aux->dir = aux->esq = NULL;
        return aux;
    }
    if(chave < root->info.chave){
        root->esq = inserir(root->esq, chave);
    } else{
        root->dir = inserir(root->dir, chave);
    }
    return root;
}

tree buscar(tree root, int chave){
    if(root == NULL || root->info.chave == chave){
        return root;
    }
    if(chave < root->info.chave){
        return buscar(root->esq, chave);
    } else{
        return buscar(root->dir, chave);
    }
}

void removerNo(tree *p){
    tree q;
    if((*p)->esq == NULL){
        q = *p;
        *p = (*p)->dir;
        free(q);
    } else if((*p)->dir == NULL){
        q = *p;
        *p = (*p)->esq;
        free(q);
    } else{
        substituiMenorDireita(p, &(*p)->dir);
    }

}

int buscaRemover(tree *root, int chave){
    tree raiz = *root;
    if(raiz == NULL){
        return 0;
    }
    if(raiz->info.chave == chave){
        removerNo(root);
        return 1;
    }

    if (chave < raiz->info.chave)
   {
      return buscaRemover(&(raiz->esq), chave);
   }
   else
   {
	  //Buscar e remover na sub-�rvore direita
      return buscaRemover(&(raiz->dir), chave);
   }
}

void substituiMenorDireita(tree *p, tree *suc){
    tree q;
    if((*suc)->esq == NULL){ //buscando o menor da direita, o mais a esquerda
        q = *suc;
        *suc = (*suc)->dir;
        free(q);
    } else{
        substituiMenorDireita(p, &(*suc)->esq);
    }
}

tree percursoEmOrdem(tree root){
    if(root != NULL){
        percursoEmOrdem(root->esq);
        printf("%d ", root->info.chave);
        percursoEmOrdem(root->dir);
    }
}

void remover(tree *root, int chave){
    int flag = buscaRemover(root, chave);
    if(flag == 0){
        printf("Elemento não está na árvore");
    } else{
        printf("Remoção concluída");
    }
}