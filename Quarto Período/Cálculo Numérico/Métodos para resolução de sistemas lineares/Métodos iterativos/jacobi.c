/* Método de Jacobi
AX = B -> X = CX + B
Xk+1 = Xk * B + C
Condição de parada: ||Xk+1 - Xk|| < E*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void inicializa(float *vetor, int n);
int convergencia(int n, float A[n][n]);
void jacobi(int n, float *X, float C[n][n], float B[n]);
float normaMax(float *X, float *aproxX, int n);

int main(){
    int n, i, j;

    //leitura dos dados
    printf("Dimensão da matriz: ");
    scanf("%d", &n);

    float A[n][n], B[n], X[n];

    printf("Matriz A \n");
    for(i = 0; i < n; i ++){
        printf("Linha %d: \n", i + 1);
        for(j = 0; j < n; j ++){
            printf("Coluna %d: ", j + 1);
            scanf("%f", &A[i][j]);
        }
    }

    printf("Vetor B \n");
    for(i = 0; i < n; i ++){
        printf("Linha %d: ", i+1);
        scanf("%f", &B[i]);
    }

     if(convergencia(n, A)){
        //transformação de AX = B em X = CX + B
        float C[n][n];

        for(i = 0; i < n; i ++){
            for(j = 0; j < n; j ++){
                if(i == j){
                    C[i][j] = 0.0;
                } else{
                    C[i][j] = - A[i][j] / A[i][i];
                }
            }

            B[i] = B[i] / A[i][i];
        }

        inicializa(X, n);

        jacobi(n, X, C, B);

        for(i = 0; i < n; i ++){
            printf("X[%d] = %f", i+1, X[i]);
        }
    } else{
        printf("Solução não converge pelo método de Jacobi");
    }

}

void inicializa(float *vetor, int n){
    int i;

    for(i = 0; i < n; i ++){
        vetor[i] = 0;
    }
}

//critério das linhas
int convergencia(int n, float A[n][n]){
    int i, j;
    float sum;

    for(i = 0; i < n; i ++){ //para cada linha
        sum = 0;
        for(j = 0; j < n; j ++){ //para cada coluna
            sum = sum + fabs(A[i][j]); //soma de todos os elementos da linha
        }

        sum = sum - A[i][i];
        if(A[i][i] < sum){
            return 0;
        }
    }

    return 1;

}

//Xk+1 = Xk * B + C
void jacobi(int n, float *X, float C[n][n], float B[n]){
    int i, j;
    float e = 0.01;
    float dif = 1;

    while(dif > e){ //condição de parada: ||Xk+1 - Xk|| <= e
        float aproxX[n]; //Xk+1
         
        for(i = 0; i < n; i ++){ //Xk+1 = C * Xk + B
            aproxX[i] = 0;
            for(j = 0; j < n; j ++){
                aproxX[i] = aproxX[i] + C[i][j] * X[j];
            }

            aproxX[i] = aproxX[i] + B[i];
        }

        dif = normaMax(aproxX, X, n);

        // atualizando X com os novos valores aproximados
        for (i = 0; i < n; i++) {
            X[i] = aproxX[i];
        }
    }
}

//norma máxima do vetor
float normaMax(float *X, float *aproxX, int n){
    int i;
    float max = fabs(aproxX[0] - X[0]); 

    for(i = 1; i < n; i ++){
        float dif = fabs(aproxX[i] - X[i]);

        if(dif > max){
            max = dif;
        }
    }

    return max; //maior das diferenças
}