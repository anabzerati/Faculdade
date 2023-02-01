/*Fac¸a um programa que leia tres valores inteiros e chame uma func¸ ˆ ao que receba estes 3 ˜
valores de entrada e retorne eles ordenados, ou seja, o menor valor na primeira variavel, ´
o segundo menor valor na variavel do meio, e o maior valor na ´ ultima vari ´ avel. A func¸ ´ ao˜
deve retornar o valor 1 se os tres valores forem iguais e 0 se existirem valores diferentes. ˆ
Exibir os valores ordenados na tela.
*/

#include <stdio.h>
#include <stdlib.h>

int funcordenar(float *n1, float *n2, float *n3);

int main(){
    float *p1, *p2, *p3;
    p1 = malloc(sizeof(float));
    p2 = malloc(sizeof(float));
    p3 = malloc(sizeof(float));
    int flag;

    scanf("%f %f %f", p1, p2, p3);

    flag = funcordenar(p1, p2, p3);

    printf("%d - %.2f %.2f %.2f", flag, *p1, *p2, *p3);

    return 0;
}

int funcordenar(float *n1, float *n2, float *n3){
    int aux;
    if(*n1>*n2 && *n1>*n3){
        if(*n3>*n2){
            aux = *n2;
            *n2 = *n3;
            *n3 = aux;
        }
        } else if(*n2>*n1 && *n2>*n3){
            aux = *n1;
            *n1 = *n2;
            if(*n1>*n3){
                *n2 = aux;
            } else{
                *n2 = *n3;
                *n3 = aux;
            }
        } else if(*n3>*n1 && *n3>*n2){
            aux = *n1;
            *n1 = *n3;
            if(*n1>*n2){
                *n3 = *n2;
                *n2 = aux;
            } else{
                *n3 = aux;
            }
        } else{
            return 1;
        }
        return 0;
    }