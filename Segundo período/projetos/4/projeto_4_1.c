/*escrever um programa que faça o atendimento de uma fila atendida por vários atendentes simultaneamente (em paralelo).
elemento: identificador, instante em que chega na fila e tempo necessário para atendimento.
obs: se dois ou mais elementos tiverem o mesmo instante de chegada, é atendido o com menor identificador
entrada: 2 inteiros N (número de elementos da fila) e M (número de contros de serviço), N linhas com I, O (instante de chegada) e C (tempo de atendimento)
saída: uma linha com o instante em que é concluido o último atendimento de cada um dos centros de serviço
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct fila{
    int I, O, C;
    struct fila *prox;
}Fila;

int *cargas, *status;
int tempo_t = 0;

Fila *inserir(Fila *inicio);
Fila *remover(Fila *inicio);
void inicializar(int tam);
int analisar(int max);
void atualizar(int tam);
void adiantar(int tam, Fila *inicio);
void teste(Fila *inicio);

int main(){
    int N, M, i;
    Fila *inicio, *novo;
    inicio = novo = NULL;

    scanf("%d %d", &N, &M);
    for(i=0; i<N; i++){ //certo
        inicio = inserir(inicio);
    }

    cargas = malloc(M * sizeof(int));
    status = malloc(M * sizeof(int));
    inicializar(M);

    while(inicio!=NULL){ //enquanto há pessoas a serem atendidas
        i = analisar(M); //indice de centro livre
        if(i == -1){ //ninguem livre, olhar menor carga e "pular" tempo
            adiantar(M, inicio);
            inicio = remover(inicio);
        }
        status[i] = 1; //falta verificar quando ainda tem que pular tempo
        if(tempo_t < inicio->O){
            cargas[i] = inicio->O + inicio->C;
            tempo_t = inicio->O + inicio->C;

        } else{
            cargas[i] = cargas[i] + inicio->C;
            tempo_t = inicio->O + inicio->C; //ou tempo=inicio->O
        }
        inicio = remover(inicio);  
        atualizar(M);
    }

    for(i=0; i<M; i++){
        printf("%d ", cargas[i]);
    }

    return 0;
}

Fila *inserir(Fila *inicio){
    Fila *aux, *prev, *novo;

    novo = malloc(sizeof(Fila));
    scanf("%d %d %d", &novo->I, &novo->O, &novo->C);
    novo->prox = NULL;

    aux = prev = inicio;

    if(inicio == NULL){ //fila vazia
        return (novo);
    }

    while(aux && aux->O < novo->O){
        prev = aux;
        aux = aux->prox;
    }

    while(aux && aux->O == novo->O && novo->I > aux->I){ //mesmo momento de inserção, prioridade para menor I
        prev = aux;
        aux = aux->prox;
    }

    if(aux == inicio){
        novo->prox = aux;
        return (novo);
    }

    prev->prox = novo;
    novo->prox = aux;
    return (inicio);

}

Fila *remover(Fila *inicio){
    Fila *aux = inicio;

    if(aux == NULL){
        return NULL;
    }

    inicio = aux->prox;
    free(aux);
    return (inicio);
}

void inicializar(int tam){
    int i;
    for(i=0; i<tam; i++){
        cargas[i] = 0;
        status[i] = 0;
    }
}

int analisar(int max){
    int i;
    for(i=0; i<max; i++){
        if(status[i] == 0){ //retorna o menor indice disponivel
            return i;
        }
    }
    return -1; //retorna -1 se não há indice disponível
}

void atualizar(int tam){
    int i;
    for(i=0; i<tam; i++){
        if(tempo_t > cargas[i]){
            status[i] = 0;
        }
    }
}

void adiantar(int tam, Fila *inicio){ //encontra a menor carga e "adianta" o tempo para liberar centro
    int i, menor = cargas[0], liberar;
    for(i=0; i<tam; i++){
        if(cargas[i]<menor){
            menor = cargas[i];
            liberar = i;
        }
    }
    cargas[liberar] = inicio->O + inicio->C;
    tempo_t = inicio->O + inicio->C;
}

void teste(Fila *inicio){
    Fila *aux = inicio;
    while(aux){
        printf(" %d", aux->I);
        aux = aux->prox;
    }
}