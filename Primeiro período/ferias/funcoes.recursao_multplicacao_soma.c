//recursao -  Multiplicação de dois números naturais, através de somas sucessivas (Ex.: 6 ∗ 4 = 4 + 4 + 4 + 4 + 4 + 4).

#include <stdio.h>

int mult(int n1, int n2);

int main(){
    int num1, num2;

    printf("Números para multiplicação: ");
    scanf("%d %d", &num1, &num2);

    printf("%d x %d = %d", num1, num2, mult(num1,num2));

    return 0;
}

int mult(int n1, int n2){
    int soma=0;
    if(n1==0|n2==0){
        return 0;
    } else if(n1==1){
        return n2;
    } else{
        return n2 + mult(n1-1, n2);
    }
}