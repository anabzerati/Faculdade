/* C program to count occurrences of all words in a file */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM_MAX 50
#define MAX 100

int buscaPalavra(char words[MAX][TAM_MAX], char word[TAM_MAX], int maxIndex);

int main(){
    FILE *fp;
    char words[MAX][TAM_MAX], word[TAM_MAX];
    int count[MAX], i, j;

    for(i = 0; i < MAX; i ++){
        count[i] = 0;
    }

    fp = fopen("arq.txt", "r");

    if(!fp){
        printf("Erro ao abrir o arquivo");

        exit(1);
    }

    i = 0;
    while((fscanf(fp, "%s ", word)) != EOF){
        int aux = buscaPalavra(words, word, i);

        if(aux == -1){ //ainda não há a palavra
            strcpy(words[i], word); //adiciona ao vetor
            count[i] = 1;
            i++; //acresce o índice
        } else{
            count[aux]++;
        }
    }

    fclose(fp);

    printf("\nPalavras distintas no arquivo: ");
    for (j=0; j<i; j++)
    {
        printf("\n%s -> %d", words[j], count[j]);
    } 

    return 0;
}

int buscaPalavra(char words[MAX][TAM_MAX], char word[TAM_MAX], int maxIndex){
    int i;

    for(int i = 0; i < maxIndex; i++){
        if(!strcmp(words[i], word)){ //se forem iguais
            return i; //retorna índice
        }
    }

    return -1; //não há palavra igual
}