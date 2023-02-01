/*Escreva um programa que declare um inteiro, um real e um char, e ponteiros para inteiro, real, e char. Associe as variaveis aos ponteiros (use &). Modifique os valores de ´
cada variavel usando os ponteiros. Imprima os valores das vari ´ aveis antes e ap ´ os a ´
modificac¸ao*/

#include <stdio.h>

int main(){
    int a=1, *pa;
    float b=1.2, *pb;
    char c='a', *pc;

    pa=&a;
    pb=&b;
    pc=&c;

    printf("%d %f %c", a, b, c);

    *pa=2;
    *pb=2.3;
    *pc='b';

    printf("\n%d %f %c",a, b, c);

    return 0;
}