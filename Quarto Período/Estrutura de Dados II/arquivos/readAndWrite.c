#include <stdio.h>
#include <stdlib.h>

int main(){
    FILE *fp = fopen("arq.txt", "w"); //abro para ler
    char caracter;

    if(!fp){
        printf("Erro ao abrir o arquivo");
        exit(1);
    }

    printf("Insira as informações a serem salvas no arquivo. Para finalizar, digite 0");
    do{
        scanf(" %c", &caracter);
        fprintf(fp, "%c ", caracter);
    } while(caracter != '0');

    fclose(fp);

    fp = fopen("arq.txt", "r");
    while(!feof(fp)){
        caracter = fgetc(fp);
        printf("%c ", caracter);
    }

    fclose(fp);

    return 0;
}