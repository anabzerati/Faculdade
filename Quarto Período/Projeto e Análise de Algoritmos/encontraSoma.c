#include <stdio.h>
#include <stdlib.h>

int comparaValor(const void *a, const void *b){
    return (* (int *)a) - (* (int *)b);
}

int encontraPar(int n, int valores[n], int x, int *valor1, int *valor2) {
    qsort(valores, n, sizeof(int), comparaValor); // ordena valores

    int indice1 = 0, indice2 = n - 1; // pontas opostas do vetor

    while (indice1 < indice2){
        int soma = valores[indice1] + valores[indice2];

        if (soma == x){ // encontrou par
            *valor1 = valores[indice1];
            *valor2 = valores[indice2];
            return 1; // sucesso
        } else if (soma < x){ 
            indice1++; // verifica com valor seguinte (maior)
        } else{
            indice2--; // verifica com valor anterior (menor)
        }
    }

    return 0; // não encontrou o par
}

int main() {
    int A[] = {10, 2, 3, 5, 7, 11, 15};
    int n = sizeof(A) / sizeof(A[0]);
    int x = 12;

    int valor1, valor2;

    if (encontraPar(n, A, x, &valor1, &valor2)) {
        printf("Par encontrado: %d + %d = %d\n", valor1, valor2, x);
    } else {
        printf("Nenhum par encontrado.\n");
    }

    return 0;
}
