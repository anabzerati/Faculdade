/*
Método da bissecção para resolução de equações não lineares. princípio do Binary Search.
*/

#include <stdio.h>
#include <math.h>

float aplicaFuncao(int n, float coef[n], float x);
float multiplica(int n, float coef[n], float X1, float X2);
int calculaIteracao(float a, float b, long precisao);
float bisseccao(int n, float coef[n], float a, float b, int quantIteracoes);

int main(){
    int ordem, quantIteracoes, i;
    float a, b;
    long precisao;

    printf("Insira a ordem de f(x): ");
    scanf("%d", &ordem);

    float coeficientes[ordem];
    printf("\nInsira os coeficientes: ");
    for(i = ordem; i > 0; i --){
        printf("x%d: ", ordem+1);
        scanf("%f", &coeficientes[ordem]);
    }

    printf("\nIntervalo [a, b]");
    printf("a = ");
    scanf("%f", &a);
    printf("b = ");
    scanf("%f", &b);

    printf("\nInsira a precisão desejada para a aproximação: ");
    scanf("%lf", &precisao);

    //verificação de zero no intervalo [a, b]
    float multiplicacao = multiplica(ordem, coeficientes, a, b);
    if(multiplicacao < 0){ //há 0 no intervalo
        quantIteracoes = calculaIteracao(a, b, precisao);

        float x = bisseccao(ordem, coeficientes, a, b, quantIteracoes);

        printf("Aproximação do zero: %f", x);
    } else{
        printf("Não há zero de função no intervalo [%d, %d].", a, b);
    }

    return 0;
}

float aplicaFuncao(int n, float coef[n], float x){
    int i;
    float res = coef[0];

    for(i = 1; i < n; i ++){
        res = res + x * pow(coef[i], i);
    }

    return res;
}

float multiplica(int n, float coef[n], float X1, float X2){
    float a, b;
    int i;

    a = aplicaFuncao(n, coef, X1);
    b = aplicaFuncao(n, coef, X2);

    return (a * b);
}

int calculaIteracao(float a, float b, long precisao){
    return log2((fabs(b) - fabs(a)) / precisao) / ln(2);
}

float bisseccao(int n, float coef[n], float a, float b, int quantIteracoes){
    int x, i;
    float mid;

    for(i = 0; i < quantIteracoes; i ++){
        mid = (a + b) / 2;
        float mult = multiplica(n, coef, a, mid);

        if(mult < 0){ //há um zero entre a e mid
            b = mid;
        } else{ // o zero está entre mid e b
            a = mid;
        }
    }

    return aplicaFuncao(n, coef, mid);
}