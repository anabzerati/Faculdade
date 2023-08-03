/* C program to remove specific line from a file */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM_MAX 100

int main(){
    int line, count;
    char buffer[TAM_MAX];
    FILE *fp, *aux;
    
    fp = fopen("arq.txt", "r");
    aux = fopen("aux.tmp", "w");

    if(!fp || !aux){
        printf("Erro ao abrir o arquivo");

        exit(1);
    }

    printf("Qual linha deseja remover do arquivo original? ");
    scanf("%d", &line);

    count = 1; //começa na primeira linha
    while((fgets(buffer, TAM_MAX, fp)) != NULL){ //enquanto o arquivo não acabou
        if(line != count){
            fputs(buffer, aux); //se não for a linha a ser removida, copia pro arquivo auxiliar
        }

        count++;
    }

    fclose(fp);
    fclose(aux);

    remove("arq.txt");
    rename("aux.tmp", "arq.txt");

    return 0;
}