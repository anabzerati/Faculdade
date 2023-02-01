/*comando: geraçao de um arquivo de texto ("linhas.dat") a partir das informaçoes contidas em outros dois arquivos("codigos.dat" e "palavras.dat") - para cada código
se gera uma linnha de palavras. 
    No arquivo “codigos.dat” existe uma quantidade desconhecida de números inteiros no intervalo de -5 a 5;
    No arquivo “palavras.dat” existe uma quantidade desconhecida de palavras, sempre separadas por um espaçoo em branco;
    Para cada número lido de “codigos.dat” se deve escrever uma linha com Ni palavras do arquivo de palavras, sendo:
        1. se Ni < 0 se escreve as palavras anteriores `a ´ultima palavra lida, inclusive ela;
        2. se Ni > 0 se escreve as palavras seguintes `a ela;
        3. se Ni = 0 se escreve uma linha contendo apenas o valor 0.
    No caso de se chegar ao final do arquivo de palavras e ainda existirem c´odigos a serem lidos, ent˜ao se deve escrever uma ´ultima linha, com todos
os c´odigos restantes;
    No caso de se chegar ao final do arquivo de c´odigos e ainda existirem palavras a serem lidas, ent˜ao se deve escrever na sa´ıda quantas linhas com
cinco palavras cada at´e se esgotar as palavras do arquivo de entrada*/


#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int main(){
    int i, N, count;
    char palavras[100], teste_espaco;
    FILE *arq_palavras, *arq_codigos, *arq_linhas;
    
    //abrindo arquivos já existentes e criando novo ("linhas.dat")
    arq_palavras = fopen("palavras.dat","r"); 
    arq_codigos = fopen("codigos.dat","r");
    arq_linhas = fopen("linhas.dat","w");

    //enquanto os arquivos lidos nao tiverem acabado, ler a quantidade de palavras em "palavras.dat" de acordo com o valor em "codigos.dat" e printar em "linhas.dat"
    while(feof(arq_palavras)==0 && feof(arq_codigos)==0){
        fscanf(arq_codigos, "%d", &N); //código de "codigos.dat"
        if(N>0){
            for(i=0; i<N; i++){
                fscanf(arq_palavras, "%s", palavras);
                fprintf(arq_linhas, "%s ", palavras);
            }
            fprintf(arq_linhas, "\n"); //pular linha depois de ter escrito 'N' palavras
        } else if(N==0){
            fprintf(arq_linhas, "%d\n", N);
        } else{
            count=0;
            while(count<abs(N)){  //count variavel contedora de espaços, enquanto n tiver "voltado" 'N' palavras no arquivo, continua o fseek voltando o ponteiro
                fseek(arq_palavras, -1, SEEK_CUR); //volta o ponteiro em 1 para ler o caracter anterior
                fscanf(arq_palavras, "%c", &teste_espaco);
                if(teste_espaco == ' '){  // se tiver um espaço, conta-se uma palavra
                    count++;
                }
                fseek(arq_palavras, -1, SEEK_CUR); //ao "ler" o valor para analise de espaço, o ponteiro "anda" uma posição para frente, é necessário voltar mais uma vez
            }
            for(i=0; i<abs(N); i++){ //printar a partir das palavras que foram "retornadas" (pelo fseek e contagem de espaços)
                fscanf(arq_palavras, "%s", palavras);
                fprintf(arq_linhas, "%s ", palavras);
            }
            fprintf(arq_linhas, "\n");
        }
    }

     //se terminou de ler o arqivo de palavras mas nao terminou o de códigos, printar os códigos restantes em uma única linha
        while(feof(arq_codigos)==0){
            fscanf(arq_codigos, "%d", &N);
            fprintf(arq_linhas, "%d ", N);
        }
    

     //se terminou de ler o arquivo de códigos e o de palavras não, escrever linhas com 5 palavras até acabar;
        count=0;
        while(feof(arq_palavras)==0){
          fscanf(arq_palavras, "%s", palavras);
          fprintf(arq_linhas, "%s ", palavras);
          count++; //contagem de palavras impressas
          if(count%5==0){
              fprintf(arq_linhas, "\n");
          }
      }
    

    //fechando arquivos
    fclose(arq_palavras);
    fclose(arq_codigos);
    fclose(arq_linhas);

    return 0;
}
