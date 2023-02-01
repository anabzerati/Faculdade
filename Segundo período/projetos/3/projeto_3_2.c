/*Problema de Josephus - determinar número k e remover do círculo pessoas que estejam a k posições da atual. O processo se repete até sobrar uma pessoa.
No problema: k depende do valor armazendo pelo elemento da lista e se pode adicionar elementos (ao invés de só retirar).

Elemento: I - identificador, K - valor do próximo k, O - operação (0 = remoção, 1 = reinserção do último retirado em seu lugar original e com O=0 e remoção do atual).
Entrada: inteiro N (num de pessoas na lista N<=1000) e N linhas com K (2<=Ki<=10) e O;
Saída: valor Ii do elemento final da linha;
*/

#include <stdio.h>
#include <stdlib.h>

struct circulo{
    int I, K, O; //identficador, quantidade de elementos a andar e operação (remover ou reinserir)
    struct circulo*prox;
};

struct circulo *alocar(int I); 
struct circulo *inserir(struct circulo*h, struct circulo*elem);
struct circulo *remover(struct circulo **h, struct circulo *elem, struct circulo **removido, int *k);
struct circulo *analise(struct circulo *lista, int k);


int main(){
    struct circulo *lista, *novo, *removido, *cabeca; //cabeca aponta para o primeiro elemento da lista, lista percorre a lista (guarda posição atual), removido aponta para o último removido e novo é usado na inserção
    lista = novo = removido = cabeca = NULL; 

    int N, i, k, op;

    scanf("%d", &N); //quantidade de elementos
    for(i=0; i<N; i++){
        novo = alocar(i+1);
        cabeca = inserir(cabeca, novo); //preenche a lista (circulo)
    }

    lista = cabeca; //para percorrer o circulo (guardar a posição atual), iniciamos pela cabeça
    k = lista->K; //quantas posições vai percorrer da primeira vez
    while(i>0){ //enquanto houver mais de um elemento na lista
        lista = analise(lista, k); //move lista as k posições exigidas
        op = lista->O; 
        if(op==0){ //remove o elemento indicado por lista e guarda ponteiro para ele (caso vá ser reinserido mais tarde)
            lista = remover(&cabeca, lista, &removido, &k); 
            i--; 
        } else{ //remove elemento indicado por lista e reinsere o último removido
            cabeca = inserir(cabeca, removido); //reinserção
            lista = remover(&cabeca, lista, &removido, &k); 
        }
    }
    
    printf("%d", lista->I); //identificador do único elemento restante do circulo

    return 0;
}

struct circulo *alocar(int I){ //aloca memória e preenche estrutura
    struct circulo *novo;
    novo = malloc(sizeof(struct circulo));

    scanf("%d %d", &novo->K, &novo->O);
    novo->I = I;
    novo->prox = novo;

    return (novo); //retorna ponteiro para a estrutura 
    
}

struct circulo *inserir(struct circulo*h, struct circulo*elem){ //insere elem na lista
    struct circulo *aux, *prev;

    if(h == NULL){ //lista vazia
        return elem; //elem é a cabeca
    }

    aux = prev = h;
    if(h->prox == h){ //um elemento
        aux->prox = elem;
        elem->prox = aux;
        if(elem->I < aux->I){ //se elem for menor que a cabeca, atualiza cabeca
            h = elem;
        }
        return h;
    }

    while(prev->prox != h && elem->I > aux->I){ //a lista é ordenada em relação a I. o laço busca o lugar adequado do elemento mantendo a ordenação
        prev = aux;
        aux = aux->prox;
    }
    if(aux == h && elem->I < aux->I){ //inserir antes da cabeca
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

struct circulo *remover(struct circulo **h, struct circulo *elem, struct circulo **removido, int *k){ //remove elem, guarda em removido (ponteiro para ele) e guarda o k dele (próximo k)
    struct circulo *aux, *prev;
    prev = aux = (*h);
    (*k) = elem->K;

    while(aux->prox != (*h) && aux->I < elem->I){ //busca elem
        prev = aux;
        aux = aux->prox;
    }
    
    if(aux!=(*h)){
        prev->prox = aux->prox;
    } else{
        while(prev->prox!=(*h)){
            prev = prev->prox;
        }
        prev->prox = aux->prox;
        (*h) = aux->prox; //remove e atualiza cabeca
    }

    (*removido) = elem; //guardamos um ponteiro para último removido para o caso de reinserção
    (*removido)->O = 0; //sua operação se torna 0

    return (elem->prox); //lista aponta para o seguinte do removido
}

struct circulo *analise(struct circulo *lista, int k){ //anda lista em k posições
    int i;
    for(i=1; i<k; i++){ //i começa como um pois lista aponta para o seguinte do removido (de quem é o k)
        lista = lista->prox;
    }
    return (lista);
}