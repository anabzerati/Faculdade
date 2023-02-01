 /*cpu é ocupada no instante pelo processo com maior valor esperado para processamento.
ENTRADA: N (até 1000) números de programas executados, T e C (instante de submissão e carga de execução)
SAÍDA: cargas dos programas executados na ordem de execução
OBS: duas cargas iguais = alocar com menor T
    se T coincidir com o término de um programa na CPU, considerar candidato
*/

#include <stdio.h>
#include <stdlib.h>

struct dados{
    int T, C;
    struct dados *prox;
};

struct dados *aloca();
struct dados *inserir(struct dados *h, struct dados *n);
int analise(struct dados *h, int tempo);
void remover(struct dados **h, int C);


int main(){
    struct dados *cabeca, *novo;
    cabeca = NULL;

    int N, i, maior_exec, tempo=10000000, *cargas;

    scanf("%d", &N);
    cargas = malloc(N*sizeof(int));

    for(i=0; i<N; i++){
        novo = aloca();
        if(tempo > novo->T){
            tempo = novo->T;
        }
        cabeca = inserir(cabeca, novo);
    }

    i=0;
    while(cabeca != NULL){
        maior_exec = analise(cabeca, tempo);
        if(maior_exec == 0){
            tempo = cabeca->T;
            maior_exec = analise(cabeca, tempo);
        }
        remover(&cabeca, maior_exec);
        cargas[i] = maior_exec;
        i++;
        tempo = tempo + maior_exec;
    }

    for(i=0; i<N; i++){
        printf("%d ", cargas[i]);
    }
    
    return 0;
}

struct dados *aloca(){
    struct dados *aux;

    aux = malloc(sizeof(struct dados));
    scanf(" %d %d", &aux->T, &aux->C);
    aux->prox = NULL;

    return (aux);
}

struct dados *inserir(struct dados *h, struct dados *n){
    struct dados *aux, *prev;

    if(h == NULL){
        return (n);
    }

    aux = prev = h;
    while(aux->prox && n->T>aux->T){
        prev = aux;
        aux = aux->prox;
    }

    if(aux == h){
        if(n->T>aux->T){
            n->prox = h->prox;
            h->prox=n;
            return (h);
        } else{
            n->prox = h;
            return (n);
        }
    }

    if(n->T>aux->T){
        n->prox = aux->prox;
        aux->prox = n;
    } else{
        n->prox = aux;
        prev->prox = n;
    }
    return (h);
}

int analise(struct dados *h, int tempo){
    struct dados *aux;
    int maior_carga=0;
    aux = h;

    while(aux && aux->T<=tempo){
        if(aux->C>maior_carga){
            maior_carga = aux->C;
        }
        aux = aux->prox;
    }
    return (maior_carga);
}

void remover(struct dados **h, int C){
    struct dados *aux, *prev;
    aux = prev = (*h);

    if(aux!=NULL && aux->C==C){
        (*h) = aux->prox;
        free(aux);
        return;
    }    

    while(aux && aux->C!=C){
        prev = aux;
        aux = aux->prox;
    }
    if(aux == NULL){
        return;
    }
    prev->prox = aux->prox;
    free(aux);
}