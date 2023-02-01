/*A entrada ´e composta por uma ´unica linha, sem caracteres em branco, contendo n´umeros,
operadores aritm´eticos e os delimitadores ’(’, ’)’, ’[’, ’]’, ’{’ e ’}’.
Cada linha ter´a at´e 104
caracteres.
Sa´ıda
A sa´ıda de seu programa deve ter apenas uma linha, contendo a letra S se a sequˆencia for
v´alida ou N caso seja inv´alida.*/

#include <stdio.h>
#include <string.h>

int main(){
    char expressao[10];
    int par_aberto=0, par_fechado=0, col_aberto=0, col_fechado=0, chav_aberto=0, chav_fechado=0, tamanho, i, valor=1;

    scanf("%s", expressao);
    tamanho=strlen(expressao);

    for(i=0; i<tamanho; i++){
        if(i==0){
            if(expressao[i]==')'||expressao[i]==']'||expressao[i]=='}'){
                valor=0;
                } else if(expressao[i]=='('){
                    par_aberto++;
                }else if(expressao[i]=='['){
                    col_aberto++;
                }else if(expressao[i]=='{'){
                    chav_aberto++;
                }
         } else{
            if(expressao[i]=='('){
                par_aberto++;
            }else if(expressao[i]=='['){
                col_aberto++;
            }else if(expressao[i]=='{'){
                chav_aberto++;
            }else if(expressao[i]==')'){
                par_fechado++;
            }else if(expressao[i]==']'){
                col_fechado++;
            }else if(expressao[i]=='}'){
                chav_fechado++;
            }
        }
    }

    if(par_aberto!=par_fechado||col_aberto!=col_fechado||chav_aberto!=chav_fechado){
        valor=0;
    }

    if(valor==0){
        printf("N");
    } else{
        printf("S");
    }

    return 0;
}