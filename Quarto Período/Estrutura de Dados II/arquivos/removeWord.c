/* C program to remove a word from text file */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM_MAX 100

void removePalavraLinha(char *linha, char *palavra);

int main(){
    FILE *fp, *aux;

    fp = fopen("arq.txt", "r");
    aux = fopen("aux.tmp", "w");

    if(!fp || !aux){
        printf("Erro ao abrir o arquivo");

        exit(1);
    }

    char remover[TAM_MAX], buffer[TAM_MAX];

    printf("Insira a palavra a ser removida do arquivo: ");
    scanf("%s", remover);

    while((fgets(buffer, TAM_MAX, fp)) != NULL){
        removePalavraLinha(buffer, remover);

        fputs(buffer, aux);
    }

    fclose(fp);
    fclose(aux);

    remove("arq.txt");
    rename("aux.tmp", "arq.txt");

    return 0;
}

void removePalavraLinha(char *linha, char *palavra){
    int i, j, tamLinha, tamPalavra;
    int found;

    tamLinha = strlen(linha);      
    tamPalavra = strlen(palavra);


    for(i = 0; i <= tamLinha - tamPalavra; i++) {
        found = 1;

        for(j = 0; j < tamPalavra; j++) {
            if(linha[i + j] != palavra[j]) { //letras diferentes
                found = 0;
                break;
            }
        }

        if(linha[i + j] == ' ' || linha[i + j] == '\t' || linha[i + j] == '\n' || linha[i + j] == '\0') { //se não for apalavra
            found = 0;
        }

        if(found) { //encontrou palavra
            for(j = i; j <= tamLinha - tamPalavra; j++) { //da posição da primeira letra da palavra até o fim
                linha[j] = linha[j + tamPalavra]; //"passa" letras pra esuqerda
            }

            tamLinha = tamLinha - tamPalavra;

            i--;
        }
    }
}