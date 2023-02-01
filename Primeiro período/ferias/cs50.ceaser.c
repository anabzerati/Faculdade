#include <stdio.h>
#include <string.h>

int main(){
    char texto[10], novo_texto[10];
    int k, tam;

    printf("Insira o texto a ser criptografado: ");
    scanf("%s", texto);

    do{
        printf("\nInsira quantas posições a letra deve ser deslocada: ");
        scanf("%d", &k);
        if(k<=0){
            printf("Erro! Inisra valores inteiros positivos!");
        }
        k = k%26;
    } while(k<=0);

    printf("\n");
    tam = strlen(texto);
    for(int i=0; i<tam; i++){
        novo_texto[i] = texto[i] + k;
        printf("%c", novo_texto[i]);
    }
  
    return 0;
}  