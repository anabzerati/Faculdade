// Aprximação de curvas pela interpolação utilizando o polinômio de Newton
// Pn(x) = d0 + d1(x-x0) + d2(x-x0)(x-x1) + ... + dn(x-x0)(x-x1)...(x-xn-1)
// d0 = f[x0]; d1 = f[x0,x1]; d2 = f[x0,x1,x2]; ... - diferenças divididas

#include <stdio.h>
#include <stdlib.h>

float calculaInterpolacaoNewton(int n, float x[n], float y[n][n], float pontoDesejado);
void preencheTabelaDiferencasDivididas(int n, float x[n], float y[n][n]);

int main(){
    int n;

    printf("Insira a quantidade de pontos: ");
    scanf("%d", &n);

    float x[n], y[n][n]; // y tabela de diferenças divididas
    int i;

    for(i = 0; i < n; i ++){
        printf("Ponto x%d: ", i);
        scanf("%f", &x[i]);

        printf("Ponto f(x%d): ", i);
        scanf("%f", &y[i][0]); // linha i coluna 0
    }

    float xBuscado;
    printf("Insira o ponto de interpolação: ");
    scanf("%f", &xBuscado);

    printf("Estimativa de f(%f) = %f", x, calculaInterpolacaoNewton(n, x, y, xBuscado));

    return 0;
}

float calculaInterpolacaoNewton(int n, float x[n], float y[n][n], float pontoDesejado){
    int i, j;
    float resultado = y[0][0];
 
    for(i = 1; i < n; i ++){
        float mult = 1;
        for(j = 0; j < i; j ++){ // (x-x0)...(x-xi)
            mult = mult * (pontoDesejado - x[j]);
        }

        resultado = resultado + (mult * y[0][i]); // di(x-x0)...(x-xi)
    }

    return resultado;
}

void preencheTabelaDiferencasDivididas(int n, float x[n], float y[n][n]){
    int i, j;

    for(i = 1; i < n; i ++){
        for(j = 0; j < n - i; j ++){
            y[j][i] = (y[j][i - 1] - y[j + 1][i - 1]) / (x[j] - x[i + j]);
        }
    }
}