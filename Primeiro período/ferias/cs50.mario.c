//cs50 mario

#include <stdio.h>

int main(){
    int quant, k;

    do{
        printf("Qual a altura e largura da piramide?");
        scanf("%d", &quant);
        if(quant<=0){
            printf("Inválido!Insira um valor inteiro positivo!");
        }
    }while(quant<=0);

    k = quant-1;
    for(int i=0; i<quant; i++){
        for(int j=0; j<quant; j++){
            if(j>=k){
                printf("%c", '#');
            } else{
                printf("  ");
            }
        }
        printf("\n");
        k--;
    }
}