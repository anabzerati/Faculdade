/*palindromeio - palíndromo no meio de uma sequência de caracteres - descobrir o maior existente para uma sequencia
entrada: k(<2000) caracteres em maiusculo
saida: numero = tamanho do maior palindromeio da sequencia*/

#include <stdio.h>

int palindromeio(char *palavra, int i, int j);

int main(){
    char palavra[2001];
    int i, j, tam, maior=0;

    scanf("%s", palavra);
    tam=strlen(palavra);

    for(i=0; i<tam; i++){
        for(j=i+1; j<tam; j++){
            if(palindromeio(palavra, i, j) && j-i>maior){
                maior = j-i;
            }
        }
    }

    printf("%d\n", maior+1);

    return 0;
}

int palindromeio(char *palavra, int i, int j){
    if(i>j){
        return 1;
    } else if(palavra[i]!=palavra[j]){
        return 0;
    } else{
        return palindromeio(palavra, i+1, j-1);
    } 
}