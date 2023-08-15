/*Escreva um algoritmo para uma função de busca de um registro em arquivos com índice secundário. - busca binária*/

#include <stdio.h>
#include <stdlib.h>

#define MAX 10

/*struct que representa os campos de um regisro do índice primário: chave primária e byte offset*/
struct indicePrimario{
    int chave;
    int posicao;
};

/*struct que representa os campos de um regisro do índice secundário: chaves primária e secundária*/
struct indiceSecundario{
    int chaveSecundaria;
    int chavesPrimarias[MAX]; //vetor de chaves primárias associada a essa chave secundária
};

void buscaRegistro(char *nomeIndicePrimario, char *nomeIndiceSecundario, char *nomeArquivo, char *chaveSecundaria); 
int *buscaPrimaria(char *nomeIndicePrimario, int *indices);
int *buscaSecundaria(char *nomeIndiceSecundario, char *chaveSecundaria); //a partir da chave secunária, retorna vetor de chaves primárias

int main(){
    char* chaveSecundaria = "exemplo";
    buscaRegistro("indexPrimario.dat", "indexSecundario.dat", "dados.dat", chaveSecundaria);

    return 0;
}

void buscaRegistro(char *nomeIndicePrimario, char *nomeIndiceSecundario, char *nomeArquivo, char *chaveSecundaria){
    int *indicesPrimarios = buscaSecundaria(nomeIndiceSecundario, chaveSecundaria);
    int *posicoes = buscaPrimaria(nomeIndicePrimario, indicesPrimarios);
    int i;
    FILE *arquivo = fopen(nomeArquivo, "r");
    if(!arquivo){
        printf("Erro ao abrir o arquivo!");
        exit(1);
    }

    for(i = 0; i < MAX; i ++){
        fseek(arquivo, SEEK_SET, posicoes[i]); //posição determinada pelo índice
        char* dados = malloc(256 * sizeof(char)); //tamanho máximo do registro
        fgets(dados, 256, arquivo); //lemos registro
        printf("%s\n", dados); //imprime na tela
    }
}

int *buscaPrimaria(char *nomeIndicePrimario, int *indices){
    FILE *arquivoIndicePrimario = fopen(nomeIndicePrimario, "r");
    if(!arquivoIndicePrimario){
        printf("Erro ao abrir o arquivo!");
        exit(1);
    }

    int *posicoes = calloc(MAX, sizeof(int)); //vetor de MAX posições para as posições associadas as chaves primárias
    struct indicePrimario aux; //auxiliar para leitura de dados do arquivo
    int i = 0, j;

    while(!feof(arquivoIndicePrimario)){ //percorre todo o arquivo de índices primários
        fread(&aux, sizeof(struct indicePrimario), 1, arquivoIndicePrimario);
        for(j = 0; j < MAX; j ++){
            if(aux.chave == indices[j]){ //se lemos um registro com uma das chaves que procuramos
                posicoes[i] = aux.posicao; //guardamos posição do registro equivalente no arquivo original
                i++;
            }
        }
    }

    return posicoes;
}

int *buscaSecundaria(char *nomeIndiceSecundario, char *chaveSecundaria){
    FILE *arquivoIndicesSecundarios = fopen(nomeIndiceSecundario, "r");
    if(!arquivoIndicesSecundarios){
        printf("Erro ao abrir o arquivo!");
        exit(1);
    }

    fseek(arquivoIndicesSecundarios, SEEK_END, 0); //última posição
    int quantidadeRegistros = ftell(arquivoIndicesSecundarios) / sizeof(struct indiceSecundario); //calcula quantidade de registros
    rewind(arquivoIndicesSecundarios); //volta para primeira posição

    struct indiceSecundario* registros = malloc(quantidadeRegistros * sizeof(struct indiceSecundario)); //aloco espaço pro vetor de registros
    if (!registros) {
        return "Erro de alocação de memória";
    }

    fread(registros, sizeof(struct indiceSecundario), quantidadeRegistros, arquivoIndicesSecundarios); //lê todos os registros e guarda no vetor

    int comeco = 0, final = quantidadeRegistros - 1;
    while(comeco <= final){
        int meio = (comeco + final) / 2;

        if (registros[meio].chaveSecundaria == chaveSecundaria) { //encontrou
            return registros[meio].chavesPrimarias; //retorna vetor de chaves primarias do encontrado
        }

        if (registros[meio].chaveSecundaria < chaveSecundaria) { //se for menor
            comeco = meio + 1; 
        } else {
            final = meio - 1;
        }
    }

    return NULL; //nada foi encontrado
}