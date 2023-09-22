/* Implementação das funções definidas na biblioteca */

#include "../include/arquivos.h"

extern  IndicePrimario *vetorPrimario;
extern IndiceSecundario *vetorTitulos;
extern int numeroFilmes;

/* Função que abre os arquivos de dados e índices */
Arquivos abreArquivos(){
    FILE *fp;
    Arquivos aux;

    if(verificaDados()){ //existe arquivo de dados
        fp = fopen(NOME_ARQ_DADOS, "r+"); //abre pra leitura
    } else{
        fp = fopen(NOME_ARQ_DADOS, "w+"); //cria para escrita
    }
    aux.dadosP = fp;

    if(verificaPrimario()){ //existe índice primário
        fp = fopen(NOME_INDICE_PRIMARIO, "r+"); //abre pra leitura
    } else{
        fp = fopen(NOME_INDICE_PRIMARIO, "w+"); //cria para escrita
    }
    aux.primarioP = fp;

    if(verificaSecundario()){ //existe índice secundário
        fp = fopen(NOME_INDICE_TITULO, "r+"); //abre pra leitura
    } else{
        fp = fopen(NOME_INDICE_TITULO, "w+"); //cria para escrita
    }
    aux.secundarioP = fp;

    return aux;
}

/* Carrega índice primário do disco para RAM, retorna vetor de índices ordenado*/
IndicePrimario *carregaPrimario(FILE *dadosp, FILE *fp){
    int  i;
    int flag = -1;

    /*leitura do header*/
    fscanf(fp, "%d", &flag); //flag de consistência

    if(flag == -1){ //arquivo vazio
        numeroFilmes = 0;

        fprintf(fp, "%d %d", 0, 0); //flag e número de registros

        return NULL;
    }

    if(flag == 0){ //arquivo de índices não atualizado
        criaPrimario(dadosp, fp); //função que reescreverá o arquivo baseando-se no arquivio de dados
    }

    rewind(fp);
    fscanf(fp, "%d %d\n", &flag, &numeroFilmes); //dados do header

    vetorPrimario = malloc((numeroFilmes) * sizeof(IndicePrimario)); //aloca vetor do índice primário

    for(i = 0; i < numeroFilmes; i ++){ //para todos os registros
        //lê chave primária e RRN e carrega em uma struct
        fscanf(fp, "%s %ld", vetorPrimario[i].chavePrimaria, &vetorPrimario[i].RRN);
    }

    rewind(fp);
    fprintf(fp, "%d", 0); //flag = 0
    fclose(fp);
    
    ordenaPrimario(numeroFilmes);

    return vetorPrimario;
}

/* Carrega índice secunsário do disco para RAM, retorna vetor de índices ordenado*/
IndiceSecundario *carregaSecundario(FILE *dadosp, FILE *fp){
    char bufferNom[MAX_NOME + 1];
    int i = 0, flag;

    if(numeroFilmes == 0){
        return NULL;
    }

    //leitura do header
    fscanf(fp, "%d", &flag);

    if(flag == 0){ //inconsistência entre índice e arquivo de dados
        criaSecundario(dadosp, fp);
    }

    rewind(fp);
    fscanf(fp, "%d\n", &flag); //dado do header
    
    vetorTitulos = malloc(numeroFilmes * sizeof(IndiceSecundario)); //aloca vetor do índice secundário

    for(i = 0; i < numeroFilmes; i ++){ //para cada registro
        //lê título e chave primária
        char linha[TAM_CHAVE + MAX_NOME + 1];
        fgets(linha, MAX_NOME + TAM_CHAVE + 1, fp); //lê linha

        if (sscanf(linha, "%[^@]@%s", vetorTitulos[i].titulo, vetorTitulos[i].chavePrimaria) != 2) { //lê campos
            printf("Erro ao ler os campos.\n");
        } 
    }

    ordenaSecundario(numeroFilmes);

    rewind(fp);
    fprintf(fp, "%d", 0);

    fclose(fp);
    fclose(dadosp);

    return vetorTitulos;
}

/* Refaz indice primário a partir do arquivo de dados*/
void criaPrimario(FILE *dadosp, FILE *primariop){
    int count = 0; //registros não apagados

    fseek(dadosp, 0, SEEK_END);
    long int size = ftell(dadosp) / TAM_REGISTRO; //quantidade total de registros

    rewind(dadosp);
    rewind(primariop);

    fprintf(primariop, "%d %d \n", 0, 0); //header - flag e quantidade

    for (int i = 0; i < size; i++){
        //fseek(dadosp, SEEK_SET, TAM_REGISTRO *i); //posiciona ponteiro

        char linha[TAM_REGISTRO + 1];
        fgets(linha, TAM_REGISTRO + 1, dadosp); //lê linha
        
        if(linha[0] == '*') // significa que é apagada
        {
            continue;
        }

        char *token = strtok(linha, "@"); //pega primeiro campo
        fprintf(primariop, "%s %ld ", token, TAM_REGISTRO * i); //imprime no índice o ID e o RRN = tamahho * registro que está

        count++; //só incrementa se não for um registro excluído
    }

    fseek(primariop, 0, SEEK_SET); //volta ponteiro para início para escrever header
    fprintf(primariop, "%d %d\n", 1, count); // flag de atualização e quantidade de registros
}

/* Refaz indice secundário a partir do arquivo de dados*/
void criaSecundario(FILE *dadosp, FILE *secundariop){
    fseek(dadosp, 0, SEEK_END);
    long int size = ftell(dadosp) / TAM_REGISTRO; //quantidade total de registros

    rewind(dadosp);
    rewind(secundariop);

    fprintf(secundariop, "%d\n", 0); //flag

    for (int i = 0; i < size; i++){
        //fseek(dadosp, SEEK_SET, TAM_REGISTRO *i); //posiciona ponteiro

        char linha[TAM_REGISTRO + 1];
        fgets(linha, TAM_REGISTRO + 1, dadosp); //lê linha
        
        if(linha[0] == '*') // significa que é apagada
        {
            continue;
        }

        char *tokenChave = strtok(linha, "@"); // pega o primeiro campo

        if (tokenChave != NULL) {
            char *tokenTitulo = strtok(NULL, "@"); // pega o segundo campo
            if (tokenTitulo != NULL) {
                printf("Chave e título lidos %s %s\n", tokenChave, tokenTitulo);
                fprintf(secundariop, "%s@%s\n", tokenTitulo, tokenChave); // imprime campos
            }
        }
    }

    //fseek(secundariop, 0, SEEK_SET); //volta ponteir para início para escrever header
    //fprintf(secundariop, "%d\n", 1); // flag de atualização

    //fseek(dadosp, 0, SEEK_SET); //volta ponteiro para a primeira posição
}

/* Insere registro no arquivo de dados e nos vetores de índices. Retorna 1 se a operação teve sucesso e 0 caso não*/
int insereRegistro(Filme *novo){
    char buffer[TAM_REGISTRO + 1];
    long int auxRRN;

    FILE *dadosp = fopen(NOME_ARQ_DADOS, "a+");

    // "concatenar" várias strings de uma vez - formatar string com @ entre os campos
    sprintf(buffer,"%s@%s@%s@%s@%s@%s@%c@", novo->chavePrimaria, novo->tituloOriginal, novo->tituloPortugues, novo->diretor, novo->anoLancamento, novo->pais, novo->nota);
    
    // preencher o resto do registro com '#'
    memset(buffer + strlen(buffer), '#', TAM_REGISTRO - strlen(buffer));
    buffer[TAM_REGISTRO] = '\0';

    // escrever registro no arquivo de dados
    fputs(buffer, dadosp);

    //calcular RRN do registro inserido com base na posição do ponteiro do arquivo e o tamanho fixo de cada registro
    auxRRN = ftell(dadosp) - TAM_REGISTRO;

    // após inserir o registro no arquivo de dados, é necessário adicioná-lo aos arquivos de índices
    numeroFilmes++;
    IndicePrimario * novoVetorPrimario = realloc(vetorPrimario, numeroFilmes * sizeof(IndicePrimario)); //realocando vetor de índices

    if(!novoVetorPrimario){ //verificando se a memória foi realocada
        printf("Erro ao alocar memória");
        
        return 0;
    }

    vetorPrimario = novoVetorPrimario;

    strcpy(vetorPrimario[numeroFilmes - 1].chavePrimaria, novo->chavePrimaria);
    vetorPrimario[numeroFilmes - 1].RRN = auxRRN;

    ordenaPrimario(); //reordena vetor

    //agora, deve-se inserir ao índice secundário
    IndiceSecundario * novovetorTitulos = realloc(vetorTitulos, numeroFilmes * sizeof(IndiceSecundario)); //realocando vetor de títulos

    if(!novovetorTitulos){ //verificando se a memória foi realocada
        printf("Erro ao alocar memória");
        
        return 0;
    }

    vetorTitulos = novovetorTitulos;

    strcpy(vetorTitulos[numeroFilmes - 1].titulo, novo->tituloOriginal);
    strcpy(vetorTitulos[numeroFilmes - 1].chavePrimaria, novo->chavePrimaria);

    ordenaSecundario(); //reordena vetor

    fclose(dadosp);
    
    return 1; 
}

/* Remove registro do arquivo de índices e adiciona flag de exclusão no de dados. Retorna 1 se a operação teve sucesso e 0 caso não*/
int removeRegistro(int pos, char *titulo){
    FILE *dadosP = fopen(NOME_ARQ_DADOS, "r+");

    if(!dadosP){ //erro ao abrir arquivo
        printf("Erro ao abrir o arquivo para remoção");

        return 0;
    }

    fseek(dadosP, vetorPrimario[pos].RRN, SEEK_SET); //posiciona o ponteiro no registro do filme
    fputs("*|", dadosP); //marca filme como removido

    fseek(dadosP, 4, SEEK_CUR); //posiciona ponteiro para ler título
    fscanf(dadosP, "%[^@]s", titulo);

    fclose(dadosP);

    return 1;
}

/* Altera registro no arquivo de dados. Retorna 1 se a operação teve sucesso e 0 caso não*/
int alteraRegistro(char novaNota, char *idFilme){
    FILE *dadosp = fopen(NOME_ARQ_DADOS, "r+");

    if(!dadosp){
        printf("Erro ao abrir o arquivo para alteração");

        return 0;
    }

    int pos = buscaPrimaria(idFilme, 0, numeroFilmes); //identifica filme pela chave primária

    fseek(dadosp, vetorPrimario[pos].RRN, SEEK_SET); //posiciona ponteiro

    char buffer[TAM_REGISTRO + 1], tituloaux[MAX_NOME + 1], tituloportaux[MAX_NOME + 1], diretoraux[MAX_NOME + 1], anoaux[5], paisaux[MAX_NOME + 1]; //strings auxiliares para leitura de campos

    fgets(buffer, TAM_REGISTRO + 1, dadosp); //lê registro

    if (sscanf(buffer, "%[^@]@%[^@]@%[^@]@%[^@]@%[^@]@%[^@]@", idFilme, tituloaux, tituloportaux, diretoraux, anoaux, paisaux) != 6) { //lê campos
        printf("Erro ao ler os campos.\n");
        return 0;
    } 

    long int tamNota;
    tamNota = strlen(idFilme) + strlen(tituloaux) + strlen(tituloportaux) + strlen(diretoraux) + strlen(anoaux) + strlen(paisaux) + 6; //tamanho de cada campo + separadores

    fseek(dadosp, tamNota - TAM_REGISTRO , SEEK_CUR); //posiciona o ponteiro no campo da nota

    fputc(novaNota, dadosp); //atualiza a nota

    fclose(dadosp);

    return 1;
}

/* Ordena o vetor de índices primários considerando a chave primária. Insertion Sort*/
void ordenaPrimario(){
    int i, j;
    IndicePrimario aux;

    for(i = 1; i < numeroFilmes; i ++){
        aux = vetorPrimario[i];
        j = i - 1;

        while( j >= 0 && strcmp(vetorPrimario[j].chavePrimaria, aux.chavePrimaria) > 0){ //utiliza chave primária para ordenar
            vetorPrimario[j + 1] = vetorPrimario[j];
            j --;
        }

        vetorPrimario[j + 1] = aux;
    }
}

/* Ordena o vetor de índices secundários considerando o título. Insertion Sort*/
void ordenaSecundario(){
    int i, j;
    IndiceSecundario aux;

    for(i = 1; i < numeroFilmes; i ++){
        aux = vetorTitulos[i];
        j = i - 1;

        while( j >= 0 && strcmp(vetorTitulos[j].titulo, aux.titulo) > 0){ //utiliza título para ordenar
            vetorTitulos[j + 1] = vetorTitulos[j];
            j --;
        }

        vetorTitulos[j + 1] = aux;
    }
}

/* Busca filme pelo índice primário e retorna sua posição no vetor. Caso não haja registro com esse ID, retorna -1. Busca binária*/
int buscaPrimaria(char *chavePrimaria, int i, int j){
    int mid = (i + j) / 2;
    int val = strcmp(vetorPrimario[mid].chavePrimaria, chavePrimaria);

    if(i > j){ //não há filme no vetor com essa chave primária
        return -1;
    } else if(val == 0){ //encontrou o filme
        return mid; //retorna posição
    } else{ //continuar buscando
        if(val > 0){ //mid > chave buscada -> chave está na parte inferior do vetor
            return buscaPrimaria(chavePrimaria, i, mid - 1);
        } else{ //chave está na metade superior do vetor
            return buscaPrimaria(chavePrimaria, mid + 1, j);
        }
    }
}

/* Busca filme pelo índice secundário a partir do título e retorna os indices da primeira e útlima aparição dessa chave secundária. Caso não haja registro com esse ID, retorna -1 em j*/
void buscaSecundaria(char *titulo, int *i, int *j){
    int mid, val;

    int menor = 0, maior = numeroFilmes - 1;

    while(menor <= maior){ //enquanto ainda houver filmes para verificar
        mid = (menor + (maior - menor)/2);
        val = strcmp(vetorTitulos[mid].titulo, titulo);

        if(val == 0){ //encontrou um filme
            //agora, é necessário buscar os demais filmes com o mesmo título
            *i = *j = mid;
                   
            while(*i > 0 && strcmp(vetorTitulos[(*i) - 1].titulo, titulo) == 0){ //buscamos a primeira aparição no vetor
                *i = *i - 1;
            }

            while(*j < numeroFilmes - 1 && strcmp(vetorTitulos[(*j) + 1].titulo, titulo) == 0){ //buscamos última aparição
                *j = *j + 1;
            }

            return;
        } else if(val > 0){ //mid > chave buscada -> chave está na parte inferior do vetor
            maior = mid-1;
        } else{ //chave está na metade superior do vetor
            menor = mid+1;
        }
    }

    *j = -1; //se não encontrou filme 
    
}

/* Atualiza dados dos índices da RAM para o disco. Atualiza flag da header*/
void atualizaIndices(){
    int i;

    //arquivo de índice primário primeiro
    FILE *primario =  fopen(NOME_INDICE_PRIMARIO, "w");
    fprintf(primario, "%d %d\n", 1, numeroFilmes); //flag e quantidade de registros 

    for(i = 0; i < numeroFilmes; i++){ //para cada registro, imprime os campos de chave primária e RRN
        fprintf(primario, "%s %ld ", vetorPrimario[i].chavePrimaria, vetorPrimario[i].RRN);
    }  

    fclose(primario);

   //arquivo de índice secundário
    FILE *secundario = fopen(NOME_INDICE_TITULO, "w");
    fprintf(secundario, "%d\n", 1); //flag

    for(i = 0; i < numeroFilmes; i++){ //para cada registro, imprime os campos de título e chave primária
        fprintf(secundario, "%s@%s\n", vetorTitulos[i].titulo, vetorTitulos[i].chavePrimaria);
    }  
    
    fclose(secundario);
}

/* Chama função de atualizar índices e libera as memórias alocadas*/
void sair(){
    atualizaIndices();

    free(vetorPrimario);
    free(vetorTitulos);
}

/* Função para compactar arquivo de dados, removendo fisicamente os registros excluidos (logicamente)*/
void compactarDados(){
    int i;

    FILE *dadosp = fopen(NOME_ARQ_DADOS, "r+");
    FILE *aux = fopen("data/auxiliar.tmp", "w");

    //percorrer registros imprimindo-os no arquivo auxiliar
    for(i = 0; i < numeroFilmes; i ++){
        fseek(dadosp, vetorPrimario[i].RRN, SEEK_SET); //posiciona ponteiro

        char linha[TAM_REGISTRO + 1];
        fgets(linha, TAM_REGISTRO + 1, dadosp); //lê registro

        fputs(linha, aux);
        vetorPrimario[i].RRN = TAM_REGISTRO * i;
    }

    fclose(aux);
    fclose(dadosp);
    aux = dadosp = NULL;

    if (remove(NOME_ARQ_DADOS) == 0) {
        printf("Arquivo excluído com sucesso.\n");
    } else {
        perror("Erro ao excluir o arquivo");
    }

    if(rename("data/auxiliar.tmp", NOME_ARQ_DADOS) == 0){
        printf("Arquivo modificado com sucesso.\n");
    } else {
        perror("Erro ao renomear o arquivo");
    }
    
}