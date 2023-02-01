/*Crie uma func¸ao que receba como par ˜ ametro um array e o imprima. N ˆ ao utilize ˜ ´ındices
para percorrer o array, apenas aritmetica de ponteiros. */

#include <stdio.h>

void fun_imprimir(int *posicao);

int main(){
    int array[5]={1,2,3,4,5};

    fun_imprimir(array);

    return 0;
}

void fun_imprimir(int *posicao){
    int i=0;
    for(i=0; i<5; i++){
        printf("\n%d", *(posicao+i));
    }
}