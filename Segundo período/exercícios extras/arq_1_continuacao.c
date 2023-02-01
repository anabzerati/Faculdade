#include<stdio.h>

int main(){
  FILE *arqp;
    int num;

    arqp=fopen("arq.txt", "r");

    do{
        fscanf(arqp, "%d", &num);
        printf("%d ", num);
    } while(!feof(arqp));

      fclose(arqp);
    
    return 0;
}
  