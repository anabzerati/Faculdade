/*C program to write even, odd and prime numbers to separate file*/

#include <stdio.h>
#include <stdlib.h>

int isEven(int num);
int isOdd(int num);
int isPrime(int num);

int main(){
    FILE *original, *even, *odd, *prime;
    int num;
    
    //abrindo arquivos
    original = fopen("arq.txt", "r");
    even = fopen("even.txt", "w");
    odd = fopen("odd.txt", "w");
    prime = fopen("prime.txt", "w");

    if(!original || !even || !odd || !prime){
        printf("Erro ao abrir o arquivo");
        
        exit(1);
    }

    while(!feof(original)){
        fscanf(original, "%d", &num);

        if(isPrime(num)){
            fprintf(prime, "%d ", num);
        }

        if(isEven(num)){
            fprintf(even, "%d ", num);
        } else{
            fprintf(odd, "%d ", num);
        }
    }

    fclose(original);
    fclose(even);
    fclose(odd);
    fclose(prime);

    return 0;
}

int isPrime(int num){
    int i;

    for(i = 2; i < num; i++){
        if(num % i){
            return 0;
        }
    }

    return 1;
}

int isEven(int num){
    return (num % 2 == 0);
}

int isOdd(int num){
    return (num % 2 != 0);
}