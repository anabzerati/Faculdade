// Integração numérica pela regra 1/3 de simpson repetida
// Isr(f, a, b, n) = (h/3) * (f(a) + 4f(x1) + 2f(x2) + 4f(x3) + ... + f(b)), sendo h = (b-a)/n

#include<stdio.h>
#include<math.h>

float f(float x){
    return (1 / (1 + pow(x, 2)));
}

float simpsonRepetido(int n, float x[n], int h);

int main(){
    int n;
    float a, b;

    printf("Insira o intervalo de integração [a,b]:\n");
    printf("a = ");
    scanf("%f", &a);

    printf("b = ");
    scanf("%f", &b);

    printf("\nInsira a quantidade de subintervalos: ");
    scanf("%d", &n);

    float h = (b - a) / n;

    int i;
    float x[n];
    for(i = 0; i <= n; i++){
        x[i] = a + i * h; // calculando x
    }

    printf("Integral estimada para f em [%d, %d] = %f\n", a, b, simpsonRepetido(n, x, h));

    return 0;
}

float simpsonRepetido(int n, float x[n], int h){
    int i;
    float somaPar = 0, somaImpar = 0;

    for(i = 1; i < n-1; i ++){ // todos os elementos menos as extremidadas
        if(i%2 == 0){ // i for par
            somaPar += 2 * f(x[i]);
        } else{ // i for ímpar
            somaImpar += 4 * f(x[i]);
        }
    }

    return (h / 2) * (f(x[0]) + somaPar + somaImpar + f(x[n-1]));
}