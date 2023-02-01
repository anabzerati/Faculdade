/*
I = 1
V = 5
X = 10
L = 50
C = 100
D = 500
M = 1000

Valor de número obtido somando valores, excessão: valor menor antes de maior
Escreva um programa, com fun¸c˜oes para converter números romanos em decimais e
números decimais em romanos
Seu programa deve, também somar todos os números
romanos que foram convertidos para decimais, imprimindo esse total no final.
Entrada: inteiro N (3 ≤ N ≤ 10000), seguida de
N linhas em que cada linha ter´a um n´umero decimal C, seguido por um n´umero romano se
C = 1 ou por um n´umero decimal se C = 2.
Saída: N+1 linhas, sendo as N primeiras com os valores convertidos
pelas respectivas fun¸c˜oes e a ´ultima linha com o total da soma dos n´umeros romanos lidos.
*/

#include <stdio.h>
#include <string.h>

void rom_decimal(char *romano, int *decimal);
void dec_romano (int *decimal);

int main(){
    long int N;
    int C, i, j, decimal=0, soma=0;
    char romano[100];

    scanf("%ld", &N);
    for(i=0; i<N; i++){
        scanf("%d", &C);
        if(C==1){ //converte romano para decimal
            decimal = 0;
            scanf("%s", romano);
            rom_decimal(romano, &decimal);
            printf("%d\n", decimal);
            soma = soma + decimal;
        } else{ //converte decimal para romano
            scanf("%d", &decimal);
            dec_romano(&decimal);
        }
    }

    printf("%d", soma); //CERTO

    return 0;
}

void rom_decimal(char *romano, int *decimal){ 
    int i, tam, valor;
    tam = strlen(romano);
    for(i=0; i<tam; i++){
            switch(romano[i]){
                case 'M':
                    valor = 1000;
                    break;

                case 'D':
                    valor = 500;
                    break;

                case 'C':
                    if(romano[i+1] == 'D'){
                        valor = 400;
                        i++;
                    } else if(romano[i+1] == 'M'){
                        valor = 900;
                        i++;
                    } else{
                        valor = 100;
                    }
                    break;

                case 'L':
                    valor = 50;
                    break;

                case 'X':
                    if(romano[i+1] == 'C'){
                        valor = 90;
                        i++;
                    } else if(romano[i+1] == 'L'){
                        valor = 40;
                        i++;
                    } else{
                        valor = 10;
                    }
                    break;

                case 'V':
                    valor = 5;
                    break;

                case 'I':
                    if(romano[i+1] == 'X'){
                        valor = 9;
                        i++;
                    } else if(romano[i+1] == 'V'){
                        valor = 4;
                        i++;
                    } else{
                        valor = 1;
                    }
                    break;
            }
            *decimal = *decimal + valor;
    }
}


void dec_romano (int *decimal){  //ERRO 
    int i;
    char valor1[5], valor2[5], valor3[5], valor4[5], resp[100];

    for(i=0; i<5; i++){
        valor1[i] = '\0';
        valor2[i] = '\0';
        valor3[i] = '\0';
        valor4[i] = '\0';
        resp[i] = '\0';
    }

    int a,b,c,d;
    a = *decimal/1000; //milhares
    b = (*decimal%1000)/100; //centenas
    c = (*decimal%100)/10; //dezenas
    d = *decimal%10; //unidades

    if(a == 1 || a==2){
        for(i=0; i<a; i++){
            strcat(valor1, "M");
        }
    } 

    strcat(resp, valor1);


    if(b == 1 || b == 2 || b == 3){
        for(i=0; i<b; i++){
            strcat(valor2, "C");
        }
    } else if(b == 4){
        strcat(valor2, "CD");
    } else if(b == 5){
        strcat(valor2, "D");
    } else if(b == 6 || b == 7 || b == 8){
        strcat(valor2, "D");
        for(i=0; i<(b-5); i++){
            strcat(valor2, "C");
            }
    } else if(b == 9){
        strcat(valor2, "CM");
    } 

    strcat(resp, valor2);

    if(c == 1 || c == 2 || c == 3){
        for(i=0; i<c; i++){
            strcat(valor3, "X");
        }
    } else if(c == 4){
        strcat(valor3, "XL");
    } else if(c == 5){
        strcat(valor3, "L");
    } else if(c == 6 || c == 7 || c == 8){
        strcat(valor3, "L");
        for(i=0; i<(c-5); i++){
            strcat(valor3, "X");
        }
    } else if(c == 9){
        strcat(valor3, "XC");
    }

    strcat(resp, valor3);

    if(d == 1 || d == 2 || d == 3){
        for(i=0; i<d; i++){
            strcat(valor4, "I");
        }
    } else if(d == 4){
        strcat(valor4, "IV");
    } else if(d == 5){
        strcat(valor4, "V");
    } else if(d == 6 || d == 7 || d == 8){
        strcat(valor4, "V");
        for(i=0; i<(d-5); i++){
            strcat(valor4, "I");
        }
    } else if(d == 9){
        strcat(valor4, "IX");
    }

    strcat(resp, valor4);

    printf("%s\n", resp);
    
}