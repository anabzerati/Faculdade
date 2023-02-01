/* Fac¸a um programa que leia o conteudo de um arquivo e crie um arquivo com o mesmo ´
conteudo, mas com todas as letras min ´ usculas convertidas para mai ´ usculas. Os no- ´
mes dos arquivos serao fornecidos, via teclado, pelo usu ˜ ario. A func¸ ´ ao que converte ˜
maiuscula para min ´ uscula ´ e o toupper(). Ela ´ e aplicada em cada caractere da string*/

#include<stdio.h>

int main(){
    FILE *arq_o, *arq_n;
    char l;

    arq_o=fopen("arq_original.txt", "r");
    arq_n=fopen("arq_novo.txt","w");

    while(feof(arq_o)==0){
        fscanf(arq_o, "%c", &l);
        if(l>=97 && l<=122){
            l=l-32;
        }
        fprintf(arq_n,"%c",l);
    }

    feof(arq_o);
    feof(arq_n);

    return 0;
}