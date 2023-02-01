/*outro labirinto
fila normal, exceto para idosos (60+), que são ordenados por idade
ENTRADA: N (num pessoas fila), I e T, idade e tempo em que chega na fila
SAÍDA: cada pessoa é atendida em 3 min. cada vez que uma pessoa entra na fila, imprimir idades dos que estão na fila
obs: se duas pessoas chegam ao mesmo tempo, entra a com prioridade de idade
se uma entrada coincidir com termino de atendimento, trocar quem está no caixa e inserir dps
*/

#include <stdio.h>
#include <stdlib.h>

struct fila{
    int I, T;
    struct fila *prox;
};

int tempo = 0;

void inserir_aux(struct fila **inicio, struct fila **final, int I, int T);
void inserir(struct fila **inicio, struct fila **final, int I, int T);
void remover(struct fila **inicio, struct fila **final);
void imprimir(struct fila *inicio);

int main(){
    int N, i, I, T, tempo_t, T_atual = 3, I_atual, inseriu;
    struct fila *inicio_aux, *final_aux, *inicio_princ, *final_princ;
    inicio_aux = final_aux = inicio_princ = final_princ = NULL;

    scanf("%d", &N);
    for(i=0; i<N; i++){
        scanf("%d %d", &I, &T);
        inserir_aux(&inicio_aux, &final_aux, I, T);
    }

    tempo_t = inicio_aux->T;
    I_atual = inicio_aux->I;
    inserir(&inicio_princ, &final_princ, inicio_aux->I, inicio_aux->T);
    remover(&inicio_aux, &final_aux);
    inseriu = 1;

    while(inicio_aux != NULL || inicio_princ != NULL){
        if(T_atual >= 3){
            T_atual = 0;

            if(inicio_princ == NULL){
                inserir(&inicio_princ, &final_princ, inicio_aux->I, inicio_aux->T);
                tempo_t = inicio_aux->T;
                remover(&inicio_aux, &final_aux);
                inseriu = 1;
            }

            I_atual = inicio_princ->I;
            remover(&inicio_princ, &final_princ);
        }

        while(inicio_aux != NULL && tempo_t >= inicio_aux->T){
            inserir(&inicio_princ, &final_princ, inicio_aux->I, inicio_aux->T);
            remover(&inicio_aux, &final_aux);
            inseriu = 1;
        }

        if(inseriu == 1){
            printf("%d ", I_atual);
            imprimir(inicio_princ);
        }

        T_atual++;
        tempo_t++;
        inseriu = 0;
    }

    return 0;
}


void inserir_aux(struct fila **inicio, struct fila **final, int I, int T){
    struct fila *prev, *aux, *novo;
    prev = aux = (*inicio);

    novo = malloc(sizeof(struct fila));
    novo->I = I;
    novo->T = T;
    novo->prox = NULL;

    if((*inicio) == NULL){
        (*inicio) = novo;
        (*final) = novo;
        return;
    }

    if (novo->T < (*inicio)->T || (novo->T == (*inicio)->T && novo->I > 59 && novo->I > (*inicio)->I)){ //adicionar antes da cabeça
        novo->prox = (*inicio);
        (*inicio) = novo;
        return;
    }

    if (novo->T > (*final)->T){ //adicionar dps da cauda
        (*final)->prox = novo;
        (*final) = novo;
        return;
    }

    while (aux != NULL){
        if (novo->T < aux->T || (novo->T == aux->T && novo->I > 59 && novo->I > aux->I)){
            prev->prox = novo;
            novo->prox = aux;
            return;
        }
        prev = aux;
        aux = aux->prox;
    }

    if (novo->T == (*inicio)->T && ((*inicio)->prox == NULL || (*inicio)->prox->T != novo->T)){
        novo->prox = (*inicio)->prox;
        (*inicio)->prox = novo;
        return;
    }

  aux = (*inicio)->prox;
  while (aux != NULL) {
    if (novo->T == aux->T && (aux->prox == NULL || aux->prox->T != novo->T)){
      novo->prox = aux->prox;
      aux->prox = novo;
        if (novo->prox == NULL) 
            (*final) = novo;
        return;
    }
    aux = aux->prox;
  }
    
}

void inserir(struct fila **inicio, struct fila **final, int I, int T){
    struct fila *novo, *aux, *prev;//Alocando espaco

    novo = malloc(sizeof(struct fila));
    novo->I = I;
    novo->T = T;

    if ((*inicio) == NULL){
        (*inicio) = novo;
        (*final) = novo;
        novo->prox = NULL;
        return;
    }
  
    if (novo->I > 59){
        if (novo->I > (*inicio)->I){
            novo->prox = *inicio;
            *inicio = novo;
            return;
        }

        aux = (*inicio)->prox;
        prev = (*inicio);
        while (aux != NULL){
            if ((novo)->I > aux->I){
                prev->prox = novo;
                novo->prox = aux;
                return;
            }
            prev = aux;
            aux = aux->prox;
        }
  }

  (*final)->prox = novo;
  novo->prox = NULL;
  *final = novo;
}

void remover(struct fila **inicio, struct fila **final){
    struct fila *aux = (*inicio);

    if (*inicio == NULL){ //vazia
        return;
    } 

    if ((*inicio)->prox == NULL){ //um elemento
        free(aux);
        (*inicio) = NULL;
        (*final) = NULL;
        return;
    }

    if ((*inicio)->prox == (*final)){ //dois elementos
        free(aux);
        (*inicio) = (*final);
        return;
    }

    (*inicio) = (*inicio)->prox;
    free(aux);
}

void imprimir(struct fila *inicio){
    struct fila *aux;
    aux = inicio;

    while (aux != NULL){
        printf("%d ", aux->I);
        aux = aux->prox;
    }
    printf("\n");
}