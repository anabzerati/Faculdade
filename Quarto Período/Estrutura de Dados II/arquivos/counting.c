/* C program to count number of characters, words and lines in a text file. */

#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *fp;
    char path[100];

    char ch;
    int characters, words, lines;

    fp = fopen("arq.txt", "r");

    if (!fp) {
        printf("Erro ao abrir o arquivo");

        exit(1);
    }


    characters = words = lines = 0;
    while ((ch = fgetc(fp)) != EOF) {
        characters++;

        if (ch == '\n' || ch == '\0') //quebra de linha
            lines++;

        if (ch == ' ' || ch == '\n' || ch == '\0') //final de palavra
            words++;
    }

    if (characters > 0) { //acresce quantidades para última linha e última palavra
        words++;
        lines++;
    }

    printf("Caracteres = %d\n", characters);
    printf("Palavras = %d\n", words);
    printf("Linhas = %d\n", lines);

    fclose(fp);

    return 0;
}