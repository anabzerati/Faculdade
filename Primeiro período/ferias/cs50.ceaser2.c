#include <stdio.h>
#include <string.h>

int main(){
    char texto[10], novo_texto[10], chave[27], letra;
    int k, tam;

    printf("Insira o texto a ser criptografado: ");
    scanf("%s", texto);

    do{
        printf("\nInsira a chave: ");
        scanf("%s", chave);
        if(strlen(chave)!=26){
            printf("Erro! Insira uma chave com 26 elementos!: ");
        }
    } while(strlen(chave)!=26);

    tam = strlen(texto);
    for(int i=0; i<tam; i++){
      letra = texto[i] - 97;
      printf("%c", chave[letra]);
    }
  
    return 0;
}  