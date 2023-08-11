
#include <stdio.h>
#include <stdlib.h>
 
struct pessoa {
    int id;
    char nome[20];
    char sobrenome[20];
};
 

int main()
{
    FILE* fp;
 
    fp = fopen("pessoa1.dat", "w");
    if (!fp) {
        printf("Erro ao abrir o arquivo");
        exit(1);
    }
 
    struct pessoa aux = { 1, "Ana", "Zerati" };
 
    fwrite(&aux, sizeof(aux), 1, fp); //escrevemos no arquivo os dados da struct aux
 
    struct pessoa auxLer;
 
    fclose(fp);
    fp = fopen("pessoa1.dat", "r");
    if (!fp) {
        printf("Erro ao abrir o arquivo");
        exit(1);
    }

    fread(&auxLer, sizeof(auxLer), 1, fp); //lemos do arquivo os dados e armazenamos na struct
 
    printf("Nome: %s %s \nID: %d", auxLer.nome, auxLer.sobrenome, auxLer.id);
 
    fclose(fp);
 
    return 0;
}