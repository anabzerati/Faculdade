#include <stdio.h>

struct Atividade {
    int comeco;
    int fim;
};

int selecionaAtividades(int n, struct Atividade atividades[n]){
	int quant = 1; // primeira sempre selecionada

    int ultima = 0;
	for (int j = 1; j < n; j ++){ // verifica resto, buscando compatíveis
		if (atividades[j].comeco >= atividades[ultima].fim) {
            quant++;
			ultima = j;
		}
	}

    return quant;
}

int main(){
	struct Atividade atividades[11] = {
    {1, 4}, {3, 5}, {0, 6}, {5, 7}, {3, 8}, {5, 9},
    {6, 10}, {8, 11}, {8, 12}, {2, 13}, {12, 14}
};

	printf("Número máximo de atividades não conflitantes: %d\n", selecionaAtividades(11, atividades));

	return 0;
}
