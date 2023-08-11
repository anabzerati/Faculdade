/*Escreva um algoritmo para uma função de busca de um registro em arquivos de índice simples. - busca sequencial*/

#include <stdio.h>
#include <stdlib.h>

/*struct que representa os campos de um regisro do índice: chave primária e byte offset*/
struct indice{
    int chave;
    int posicao;
};

char* buscaRegistro(char* nomeIndex, char* nomeArquivo, int chave);

int main() {
    char* resultado = buscaRegistro("index.dat", "dados.dat", 1);
    printf("%s\n", resultado);

    free(resultado);
    return 0;
}

char* buscaRegistro(char* nomeIndex, char* nomeArquivo, int chave) {
    FILE *fp_index = fopen(nomeIndex, "r");
    if (!fp_index) {
        return "Arquivo de índice não encontrado";
    }

    struct indice indice;
    while (fread(&indice, sizeof(struct indice), 1, fp_index)) { //lê registro do arquivo de índices e guarda na struct
        if (indice.chave == chave) { //encontrou
            fclose(fp_index);
            
            FILE* fp_dados = fopen(nomeArquivo, "r");
            if (!fp_dados) {
                return "Arquivo de dados não encontrado";
            }

            fseek(fp_dados, indice.posicao, SEEK_SET); //"pulo" para a posição determinada no índice
            char* dados = malloc(256 * sizeof(char)); //tamanho máximo do registro
            fgets(dados, 256, fp_dados);

            fclose(fp_dados);
            return dados;
        }
    }

    fclose(fp_index);
    return "Registro não encontrado"; //se chegou até aqui, não encontrou
}