/*Problema de Josephus - determinar número k e remover do círculo pessoas que estejam a k posições da atual. O processo se repete até sobrar uma pessoa.
No problema: k depende do valor armazendo pelo elemento da lista e se pode adicionar elementos (ao invés de só retirar).

Elemento: I - identificador, K - valor do próximo k, O - operação (0 = remoção, 1 = reinserção do último retirado em seu lugar original e com O=0 e remoção do atual).
Entrada: inteiro N (num de pessoas na lista N<=1000) e N linhas com K (2<=Ki<=10) e O;
Saída: valor Ii do elemento final da linha;
*/

#include <stdio.h>
#include <stdlib.h>

struct circulo{
    int I, K, O;
    struct circulo*prox;
};

struct circulo *alocar(int I);
struct circulo *inserir(struct circulo*lista, struct circulo*elem);
void teste(struct circulo*lista);
struct circulo *remover(struct circulo *elem, struct circulo **removido, int *k);
void analise(struct circulo **lista, int k);


int main(){
    struct circulo *lista, *novo, *removido, *auxiliar; 
    lista = novo = removido = auxiliar = NULL; //lista a princípio vazia

    int N, i, k, op;

    scanf("%d", &N);
    for(i=0; i<N; i++){
        novo = alocar(i+1);
        lista = inserir(lista, novo);
    }
    teste(lista);
    printf("\n");

    k = lista->K;
    //lista = lista->prox; //precisamos para a função análise, pois após removido o primeiro elelemto, "lista" aponta para o seguinte (como se já tivesse "andado" a posição inicial)
    while(i>0){ //enquanto houver mais de um elemento na lista
        analise(&lista, k);
        op = lista->O;
        if(op==0){ //remove o elemento indicado por lista e guarda ponteiro para ele (caso vá ser reinserido mais tarde)
            lista = remover(lista, &removido, &k);
            i--;
        } else{ //remove elemento indicado por lista e reinsere o último removido
            auxiliar = inserir(lista, removido); //auxiliar recebe a proxima cabeça, que é irrevelevante para essa análise
            lista = remover(lista, &removido, &k);
        }
        teste(lista);
        printf("\n");
    }
    
    printf("%d", lista->I);

    return 0;
}

struct circulo *alocar(int I){
    struct circulo *novo;
    novo = malloc(sizeof(struct circulo));

    scanf("%d %d", &novo->K, &novo->O);
    novo->I = I;
    novo->prox = novo;

    return (novo);
    
}

struct circulo *inserir(struct circulo*h, struct circulo*elem){ //nessa lista, não precisamos nos preocupar em guardar a cabeça necessariamente. Apenas um ponteiro para algum elemento da lista
    struct circulo *aux, *prev;

    if(h == NULL){ //lista vazia
        return elem;
    }

    aux = prev = h;
    if(h->prox == h){
        aux->prox = elem;
        elem->prox = aux;
        if(elem->I < aux->I){
            h = elem;
        }
        return h;
    }

    while(prev->prox != h && elem->I > aux->I){ //a lista é ordenada em relação a I. o while busca o lugar adequado do elemento mantendo a ordenação
        prev = aux;
        aux = aux->prox;
    }
    if(aux == h && elem->I < aux->I){
        prev = aux->prox;
        while(prev->prox != aux){
            prev = prev->prox;
        }
        prev->prox = elem;
        elem->prox = h;
        h = elem;
    }
    prev->prox=elem;
    elem->prox=aux;
    
    return h;
}

void teste(struct circulo*lista){
    struct circulo *aux, *prev;
    aux = prev = lista;
    while(prev->prox!=lista){
        prev = aux;
        aux = aux->prox;
        printf("%d ", prev->I);
    }
}

struct circulo *remover(struct circulo *elem, struct circulo **removido, int *k){
    struct circulo *prev;
    prev = elem->prox;
    (*k) = elem->K;

    while(prev->prox != elem){
        prev = prev->prox;
    }
    prev->prox = elem->prox;
    (*removido) = elem; //guardamos ponteiro para último removido no caso de reinserção
    (*removido)->O = 0;

    return (elem->prox); //devolvemos o seguinte do removido
}

void analise(struct circulo **lista, int k){ //anda k posições
    int i;
    for(i=1; i<k; i++){
        (*lista) = (*lista)->prox;
    }
}