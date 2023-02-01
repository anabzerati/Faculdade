/*Crie uma func¸ao que receba dois par ˜ ametros: um array e um valor do mesmo tipo do ˆ
array. A func¸ao dever ˜ a preencher os elementos de array com esse valor. N ´ ao utilize ˜
´ındices para percorrer o array, apenas aritmetica de ponteiros*/

#include <stdio.h>
#include <stdlib.h>

void func_preencher(int *array, int valor);

int main(){
    int array[5], valor=3, i;

    func_preencher(array, valor);

    for(i=0; i<5; i++){
        printf("\n%d", array[i]);
    }

    return 0;
}

void func_preencher(int *array, int valor){
    int i;
    for(i=0; i<5; i++){
        *(array+i) = valor;
    }
}