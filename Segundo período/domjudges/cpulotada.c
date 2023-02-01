/*prioridade
ENTRADA: inteiro N (entre 1 e 1000) = num de programas a serem executados
        N linhas seguintes contem os valores de T (até 10000) e C (até 50) = instante em que o programa é submetido ao sistema e carga de execução
SAÍDA: uma linha com carga dos programas executados na ordem em que ocorrer
OBS: dois C iguais = alocar com maior T
    se valor de T coincidir com términ de um programa, pode ser alocado
    

lista em ordem de tempo em que foi adicionado
remove com preferencia
variavel global contando tempo total para analisar
*/

#include <stdio.h>
#include <stdlib.h>

struct dados{
    int instante_ad, tempo_exec;
    struct dados *prox;
};

struct dados *inserir(struct dados *h, int *tempo_t);
int executar(struct dados *h, int tempo_t);
void remover(struct dados **h, int exec);

int main(){
    int N, i, T, C, tempo_t=10000000, maior_exec, *resp;
    struct dados *cabeca;
    cabeca=NULL; //começa apontando para nulo, lista vazia

    scanf("%d", &N);
    resp=malloc(N*sizeof(int));

    for(i=0; i<N; i++){
        scanf(" %d %d", &T, &C);
        cabeca = inserir(cabeca, &tempo_t); //instante em que é inserido e carga de execução
    }

    i=0;
    while(cabeca!=NULL){ //enquanto ainda houver elementos na lista
        maior_exec=executar(cabeca, tempo_t);
        if(maior_exec==0){
            tempo_t=cabeca->instante_ad;
            maior_exec=executar(cabeca,tempo_t);
        }
        remover(&cabeca, maior_exec);
        resp[i]=maior_exec;
        i++;
        tempo_t=tempo_t+maior_exec;
    }

    for(i=0; i<N; i++){
        printf("%d ", resp[i]);
    }
    printf("\n");

    return 0;
}

struct dados *inserir(struct dados *h, int *tempo_t){ //insere em ordem crescente de tempos de inserção, vê exatamente a ordem em que foram adicionados
    struct dados *aux, *prev, *novo;

    novo = malloc(sizeof(struct dados)); //crio e preencho estrutura (novo elemento da lista)
    scanf(" %d %d", &novo->instante_ad, &novo->tempo_exec);
    novo->prox=NULL;

    if(novo->instante_ad<(*tempo_t)){
        *(tempo_t)=novo->instante_ad;
    }

    if(h==NULL){ //lista vazia
        return (novo);
    }

    aux=prev=h; 
    while(aux->prox && aux->instante_ad<novo->instante_ad){ //percorre lista até achar lugar para o elemento
        prev=aux;
        aux=aux->prox;
    }

    if(aux==h){ //se o elemento for inserido antes da cabeça
        if(novo->instante_ad>aux->instante_ad){
            novo->prox=h->prox;
            h->prox=novo;
            return (h);
        } else{
            novo->prox=h;
            return (novo);
        }
    } 

    if(novo->instante_ad>aux->instante_ad){
        novo->prox=aux->prox;
        aux->prox=novo;
    } else{
        novo->prox=aux;
        prev->prox=novo;
    }
    return (h);
}

int executar(struct dados *h, int tempo_t){
    struct dados *aux;
    int maior_exec=0;
    aux = h;

    while(aux && aux->instante_ad<=tempo_t){
        if(aux->tempo_exec>maior_exec){
            maior_exec=aux->tempo_exec;
        }
        aux=aux->prox;
    }
    return (maior_exec);
}

void remover(struct dados **h, int exec){
    struct dados *aux, *prev;
    aux=prev=(*h);

    if(aux!=NULL && aux->tempo_exec==exec){
        (*h)=aux->prox;
        free(aux);
        return;
    }

    while(aux && aux->tempo_exec!=exec){
        prev=aux;
        aux=aux->prox;
    }
    
    if(aux==NULL){
        return;
    }
    prev->prox=aux->prox;
    free(aux);
    return;
}
