/*Escreva um programa que contenha duas variaveis inteiras. Leia essas vari ´ aveis do ´
teclado. Em seguida, compare seus enderec¸os e exiba o conteudo do maior enderec¸o*/

#include <stdio.h>

int main(){
    int a, b, *pa, *pb;

    pa=&a;
    pb=&b;

    printf("%p||%p",pa,pb);

    if(pa>pb){
        printf("\n%d",a);
    }else{
        printf("\n%d",b);
    }

    return 0;
}