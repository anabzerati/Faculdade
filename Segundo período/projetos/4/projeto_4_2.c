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

int *cargas, *status; //cargas (tempo de trabalho) e status de cada centro de atendimento
int tempo_t = 0; //tempo total passado

Fila *inserir(Fila *inicio);
void atualizar(int tam);
int analisar(int max);
int adiantar(int tam, Fila *inicio);
Fila *remover(Fila *inicio);
void zerar(int tam);

int main(){
    int N, M, i, j;
    Fila *inicio;
    inicio = NULL;

    scanf("%d %d", &N, &M);
    cargas = malloc(M * sizeof(int)); 
    status = malloc(M * sizeof(int));
    zerar(M);

    for(i=0; i<N; i++){
        inicio = inserir(inicio);
    }

    while(inicio != NULL){
        tempo_t = inicio->O;
        atualizar(M);
        i = analisar(M);
        if(i == -1){ //se não há centro de atendimento disponível
            j = adiantar(M, inicio);
            if(inicio->O > cargas[j]){
                cargas[j] = inicio->O + inicio->C;
            } else{
                cargas[j] = cargas[j] + inicio->C;
            }
            inicio = remover(inicio);
        } else{
            status[i] = 1;
            if(inicio->O > cargas[i]){
                cargas[i] = inicio->O + inicio->C;
            } else{
                cargas[i] = cargas[i] + inicio->C;
            }
            inicio = remover(inicio);
        }
    }

    for(i=0; i<M; i++){
        printf("%d ", cargas[i]);
    }

    return 0;
}

Fila *inserir(Fila *inicio){ //inserir elemento na fila
    Fila *aux, *prev, *novo;

    novo = malloc(sizeof(Fila));
    scanf("%d %d %d", &novo->I, &novo->O, &novo->C);
    novo->prox = NULL;

    aux = prev = inicio;

    if(inicio == NULL){ //fila vazia
        return (novo);
    }

    while(aux && aux->O < novo->O){ //ordena por ordem de chegada
        prev = aux;
        aux = aux->prox;
    }

    while(aux && aux->O == novo->O && novo->I > aux->I){ //com mesmo momento de entrada, prioridade para menor I (ordena por identificação)
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

void atualizar(int tam){ //atualiza os status de acordo com o tempo decorrido (libera centros que já terminaram atendimento)
    int i;
    for(i=0; i<tam; i++){
        if(tempo_t > cargas[i]){
            status[i] = 0;
        }
    }
}

int analisar(int max){ //analisa o centro que atenderá, olhando status e, se houver mais de um centro disponível, o centro que será liberado mais cedo
    int i, menor = cargas[0], indice = 0, flag = 0;
    for(i=0; i<max; i++){
        if(status[i] == 0){ 
            flag = 1; //há alguém disponível
            if(cargas[i] < menor){
                menor = cargas[i];
                indice = i;
            }
        }
    }

    if(flag == 0){ //não há centro disponível
        return -1; //retorna -1 se não há indice disponível
    } else{
        return indice;
    }
}

int adiantar(int tam, Fila *inicio){ //encontra a menor carga e "adianta" o tempo para liberar centro
    int i, menor = cargas[0], liberar;
    for(i=0; i<tam; i++){
        if(cargas[i]<menor){
            menor = cargas[i];
            liberar = i;
        }
    }
    return liberar;
}

Fila *remover(Fila *inicio){ //remoção de elemento já atendido da fila
    Fila *aux = inicio;

    if(aux == NULL){
        return NULL;
    }

    inicio = aux->prox;
    free(aux);
    return (inicio);
}

void zerar(int tam){
    int i;
    for(i=0; i<tam; i++){
        cargas[i] = 0;
        status[i] = 0;
    }
}