// Aprximação de curvas pela interpolação utilizando o polinômio de Lagrange
// Pn(x) = y0 * L0(x) + y1 * L1(x) + ... + yn-1 * Ln-1(x)
// Lk(x) = (x-x0)(x-x1)...(x-xk-1)(x-xk+1)...(x-xn-1) / (xk-x0)(xk-x1)...(xk-xk-1)(xk-xk+1)...(xk-xn-1);

#include <stdio.h>
#include <stdlib.h>

struct ponto{
    float x, y;
};

float calculaInterpolacaoLagrange(struct ponto *, float, int);

int main(){
    int n;

    printf("Insira a quantidade de pontos: ");
    scanf("%d", &n);

    struct ponto pontos[n];
    int i;

    for(i = 0; i < n; i ++){
        printf("Ponto x%d: ", i);
        scanf("%f", &pontos[i].x);

        printf("Ponto f(x%d): ", i);
        scanf("%f", &pontos[i].y);
    }

    float x;
    printf("Insira o ponto de interpolação: ");
    scanf("%f", &x);

    printf("Estimativa de f(%f) = %f", x, calculaInterpolacaoLagrange(&pontos, x, n));

    return 0;
}

float calculaInterpolacaoLagrange(struct ponto *pontosDados, float pontoDesejado, int n){
    int i, j;
    float resultado = 0;

    for(i = 0; i < n; i ++){
        float l = 1;
        for(j = 0; j < n; j ++){
            if(j != i){
                l *= (pontoDesejado - pontosDados[j].x) / (pontosDados[i].x - pontosDados[j].x);
            }
        }

        resultado += pontosDados[i].y * l;
    }

    return resultado;
}