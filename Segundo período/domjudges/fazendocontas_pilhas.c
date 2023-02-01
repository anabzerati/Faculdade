//resolução fazendo contas usando pilhas

#include <stdio.h>
#include <string.h>
#define TAM 100
struct lifo{
        int topo;
        int pilha[TAM];
};
void push(struct lifo *p, int item){
        if(p->topo == TAM){
                fputs("Erro: overflow\n", stderr);
        }else p->pilha[p->topo++] = item;
}
int empty(struct lifo *p){
        if(p->topo == 0) return -1;
        else return 0;
}
int pop(struct lifo *p){
        if(empty(p)){
                fputs("Nenhum elemento na pilha.\n", stdout);
        }else return p->pilha[--p->topo];
}
int top(struct lifo *p){
        if(empty(p)){
                fputs("Nenhum elemento na pilha.\n", stdout);
        }else return p->pilha[p->topo-1];
}
void main(){
        struct lifo arquivo;
        int abre, fecha, id, i;
        char expressao[TAM];
        i = abre = fecha = arquivo.topo = 0;
        printf("Informe uma expressao matematica com parenteses, chaves e/ou colchetes: ");
        fgets(expressao, TAM, stdin);
        for(i; expressao[i] != '\n'; i++){
                if((expressao[i] == '(') || (expressao[i] == '[') || (expressao[i] == '{')){
                        abre++;
                        if(expressao[i] == '(') id = 1;
                        else if(expressao[i] == '[') id = 2;
                        else id = 3;
                        push(&arquivo, id);
                }else if((expressao[i] == ')') || (expressao[i] == ']') || (expressao[i] == '}')){
                        fecha++;
                        if(expressao[i] == ')') id = 1;
                        else if(expressao[i] == ']') id = 2;
                        else id = 3;
                        if(id == top(&arquivo)) pop(&arquivo);
        }       }
        if(empty(&arquivo)){
                if(abre == fecha) printf("\nA expressao foi escrita corretamente!\n");
                else printf("\nHa parenteses, colchetes e/ou chaves fechando nada. Tente retira-los.\n");
        }else{
                printf("\nA expressao esta desordenada.\n");
                if(abre < fecha) printf("Alem disso, ha parenteses, colchetes e/ou chaves abertos sem fechar.\n");
                else if(abre > fecha) printf("Alem disso, ha mais parenteses, colchetes e/ou chaves de fechamento do que de abertura.\n");
        }
        if(i - abre - fecha < abre + fecha + 1) printf("Apenas um observacao e uma sugestao: os parenteses, colche... voce sabe. Ha mais do que o necessario. Entao, porque nao os tira logo da expressao?\n");
