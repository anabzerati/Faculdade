//exercicios complementares função - Escreva	 uma função	 que	 receba	 dois	 números	inteiros	 retorne	 o	menor numero

#include <stdio.h>

int menor(int n1, int n2);

int main(){
    int n1, n2;
    
    printf("Inisra dois números para comparação: ");
    scanf("%d %d", &n1, &n2);

    printf("O menor número é: %d", menor(n1,n2));
    return 0;
}

int menor(int n1, int n2){
    if(n1<n2){
        return n1;
    } else{
        return n2;
    }
}