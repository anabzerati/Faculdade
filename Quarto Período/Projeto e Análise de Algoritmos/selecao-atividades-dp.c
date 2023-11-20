#include <stdio.h>
#include <stdlib.h>

 
struct Atividade {
    int comeco;
    int fim;
};
 
// max de atividades não conflitantes
int selecionaAtividades(int n, struct Atividade atividades[n]){
    int tabela[n]; // max de atividades não conflitantes até atividades[i]
    tabela[0] = 0;

    for(int i = 0; i < n; i ++){ // para todas as atividades
        for (int j = 0; j < i; j++){ // todas as atividades menores que i
            if (atividades[j].fim < atividades[i].comeco && tabela[i] < tabela[j]){ // se são compatíveis 
                tabela[i] = tabela[j];
            }
        }
 
        tabela[i]++; // adiciona atividades[i]
    }
 
    int max = 0;
    for(int i = 0; i < n; i ++){
        if(tabela[i] > max){
            max = tabela[i];
        }
    }

    return max;
}
 
int main(){
    struct Atividade atividades[11] = {
        {1, 4}, {3, 5}, {0, 6}, {5, 7}, {3, 8}, {5, 9},
        {6, 10}, {8, 11}, {8, 12}, {2, 13}, {12, 14}
    };
 
    printf("Número máximo de atividades não conflitantes: %d\n", selecionaAtividades(11, atividades));
 
    return 0;
}