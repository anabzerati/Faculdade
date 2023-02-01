/*Fac¸a um programa que receba o nome de um arquivo de entrada e outro de sa´ıda. O
arquivo de entrada contem em cada linha o nome de uma cidade (ocupando 40 caracte- ´
res) e o seu numero de habitantes. O programa dever ´ a ler o arquivo de entrada e gerar ´
um arquivo de sa´ıda onde aparece o nome da cidade mais populosa seguida pelo seu
numero de habitantes. */

#include <stdio.h>
#include <string.h>

int main(){
    FILE *or, *nov;
    int count=0;
    float pop, maior_pop;
    char cid[40], maior[40];

    or=fopen("original.txt","r");
    nov=fopen("novo.txt","w");

    do{
        fscanf(or,"%s%f",&cid,&pop);
        if(count==0){
            maior_pop=pop;
            strcpy(maior,cid);
        }else{
            if(pop>maior_pop){
                maior_pop=pop;
                strcpy(maior,cid);
            }
        }
        count++;
    }while(!feof(or));

    fprintf(nov,"%s %f",maior,maior_pop);

    return 0;
}