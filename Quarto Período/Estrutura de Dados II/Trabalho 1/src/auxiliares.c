/* Implementação das funções definidas na biblioteca */

#include "../include/auxiliares.h"

extern  IndicePrimario *vetorPrimario;
extern IndiceSecundario *vetorTitulos;
extern int numeroFilmes;

/* Função que verifica se o arquivo de dados existe. Retorna 0 se não existir e 1 se existir*/
int verificaDados(){
    FILE *fp;

    if((fp = fopen(NOME_ARQ_DADOS, "r+")) == NULL){ //não existe arquivo;
        return 0;
    }

    free(fp);
    return 1;
}

/* Função que verifica se o índice primário existe. Retorna 0 se não existir e 1 se existir*/
int verificaPrimario(){
    FILE *fp;

    if((fp = fopen(NOME_INDICE_PRIMARIO, "r+")) == NULL){ //não existe arquivo;
        return 0;
    }

    free(fp);
    return 1;
}

/* Função que verifica se o índice secundário existe. Retorna 0 se não existir e 1 se existir*/
int verificaSecundario(){
    FILE *fp;

    if((fp = fopen(NOME_INDICE_TITULO, "r+")) == NULL){ //não existe arquivo;
        return 0;
    }

    free(fp);
    return 1;
}

/* A partir do índice primário, lê os dados do filme correspondente e retorna uma struct preenchida com as informações*/
Filme *leFilmeIndicePrimario(int pos){
    char buffer[TAM_REGISTRO + 1];
    Filme *auxF = malloc(sizeof(Filme));

    FILE *dadosp = fopen(NOME_ARQ_DADOS, "r+");

    fseek(dadosp, vetorPrimario[pos].RRN, SEEK_SET); //posiciona ponteiro
    fgets(buffer, TAM_REGISTRO, dadosp); //lê registro

    //leitura formatada da string, atribuindo os campos do registro às variáveis da struct
    if (sscanf(buffer, "%[^@]@%[^@]@%[^@]@%[^@]@%[^@]@%[^@]@%c", auxF->chavePrimaria, auxF->tituloOriginal, auxF->tituloPortugues, auxF->diretor, auxF->anoLancamento, auxF->pais, &auxF->nota) != 7) {
        printf("Erro ao ler os campos.\n");
    } 

    fclose(dadosp);

    return auxF;
}

/* Remove posição do vetor de índice primário a partir de sua posição, readequando os demais elementos. Retorna 1 se a operação teve sucesso e 0 caso não*/
int removePosicaoPrimario(int pos){
    int i;

    for(i = pos; i < numeroFilmes - 1; i ++){ //readequa posições do vetor a partir do elemento a ser removido
        vetorPrimario[i] = vetorPrimario[i+1];
    }

    IndicePrimario *novoVetorPrimario = realloc(vetorPrimario, (numeroFilmes - 1) * sizeof(IndicePrimario)); //realoca vetor

    if(!novoVetorPrimario){
        printf("erro no realloc");

        return 0;
    }
    
    vetorPrimario = novoVetorPrimario;

    return 1;
}

/* Remove posição do vetor de índice secundário a partir de sua posição, readequando as posições dos demais elementos. Retorna 1 se a operação teve sucesso e 0 caso não*/
int removePosicaoSecundario(int pos){
    int i;

    for(i = pos; i < numeroFilmes - 1; i ++){ //readequa posições do vetor a partir do elemento a ser removido
        vetorTitulos[i] = vetorTitulos[i+1];
    }

    IndiceSecundario *novoVetorTitulos = realloc(vetorTitulos, (numeroFilmes - 1) * sizeof(IndiceSecundario)); //realoca vetor

    if(!novoVetorTitulos){
        printf("erro no realloc");

        return 0;
    }

    vetorTitulos = novoVetorTitulos;
    
    return 1;
}