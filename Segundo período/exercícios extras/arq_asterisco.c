//Fac¸a um programa que receba do usuario um arquivo texto. Crie outro arquivo texto contendo o texto do arquivo de entrada, mas com as vogais substitu´ıdas por ‘*’

#include <stdio.h>

int main(){
    FILE *fp, *novo_arq;
    char c;

    fp=fopen("arq.txt","r");
    novo_arq=fopen("arq_2.txt","w");

    while(feof(fp)==0){
        fscanf(fp,"%c",&c);
        if(c=='a'||c=='e'||c=='i'||c=='o'||c=='u'){
            c ='*';
        }
        fprintf(arq_2, "%c", c);
    }

    fclose(fp);
    fclose(arq_1);

    return 0;
}