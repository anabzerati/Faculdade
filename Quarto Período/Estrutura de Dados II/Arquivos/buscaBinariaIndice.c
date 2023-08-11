/*Escreva um algoritmo para uma função de busca de um registro em arquivos de índice simples. - busca binária*/

#include <stdio.h>
#include <stdlib.h>

struct indice{
    int chave;
    int posicao;
};

char* buscaRegistro(char* nomeIndice, char* nomeArquivo, int chave);
struct indice *buscaBinaria(struct indice *registros, int quantidadeRegistros, int chave);

int main() {
    char* resultado = search_record("index.dat", "dados.dat", 1);
    printf("%s\n", resultado);

    free(resultado);
    return 0;
}

char* buscaRegistro(char* nomeIndice, char* nomeArquivo, int chave){
    FILE* fp_indice = fopen(nomeIndice, "rb");
    if (!fp_indice) {
        return "Arquivo de índice não encontrado";
    }

    fseek(fp_indice, 0, SEEK_END); //final do arquivo
    int quantidadeRegistros = ftell(fp_indice) / sizeof(struct indice); //posição em que estou (última, tamanho do arquivo) / tamanho de um registro
    rewind(fp_indice); //volta para início

    struct indice* registros = malloc(quantidadeRegistros * sizeof(struct indice)); //aloco espaço pro vetor de registros
    if (!registros) {
        return "Erro de alocação de memória";
    }

    fread(registros, sizeof(struct indice), quantidadeRegistros, fp_indice); //leio todos os registros do arquivo e armazeno no vetor de structs
    fclose(fp_indice);

    struct indice *encontrado = buscaBinaria(registros, quantidadeRegistros, chave); //busco registro com chave e posição no arquivo de dados
    if(!encontrado){
        return "Chave não encontrada";
    }

    //se tiver sido encontrado
    FILE* fp_arquivo = fopen(nomeArquivo, "r");
    if (!fp_arquivo) {
        return "Arquivo de dados não encontrado";
    }

    fseek(fp_arquivo, encontrado->posicao, SEEK_SET); //"pula" para posição encontrada no arquivo de dados
    char* dados = malloc(256 * sizeof(char)); //tamanho máximo do registro
    fgets(dados, 256, fp_arquivo); //lemos registro

    fclose(fp_arquivo);
    return dados;
}

struct indice *buscaBinaria(struct indice *registros, int quantidadeRegistros, int chave) {
    int comeco = 0, final = quantidadeRegistros - 1;

    while (comeco <= final) {
        int meio = (comeco + final) / 2;

        if (registros[meio].chave == chave) { //encontrou
            return &registros[meio]; //retorna ponteiro pro encontrado
        }

        if (registros[meio].chave < chave) { //se for menor
            comeco = meio + 1; 
        } else {
            final = meio - 1;
        }
    }

    return NULL; //se não encontrou
}
