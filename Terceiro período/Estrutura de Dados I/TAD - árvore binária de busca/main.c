#include <stdio.h>
#include <stdlib.h>
#include "abb.h"

int main(){
    tree root = inserir(NULL, 5);
    root = inserir(root, 3);
    root = inserir(root, 7);
    root = inserir(root, 4);
    root = inserir(root, 2);
    root = inserir(root, 6);
    root = inserir(root, 9);

    printf("Árvore antes de remoção: ");
    percursoEmOrdem(root);

    remover(&root, 6);

    printf("\nÁrvore após remoção da raíz: ");
    percursoEmOrdem(root);

    return 0;
}