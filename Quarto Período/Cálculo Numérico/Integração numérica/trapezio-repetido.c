// Integração numérica pela regra do trapézio repetida
// Itr(f, a, b, n) = ((b-a)/n) * (f(a) + 2 * f(x2) + 2 * f(x3) + ... + f(b))

#include<stdio.h>
#include<math.h>

float f(float x){
    return (1 / (1 + pow(x, 2)));
}

float trapezioRepetido(int n, float x[n], float y[n], int h);

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
    float x[n], y[n];
    for(i = 0; i <= n; i++){
        x[i] = a + i * h; // calculando x
        y[i] = f(x[i]);
    }

    printf("Integral estimada para f em [%d, %d] = %f\n", a, b, trapezioRepetido(n, x, y, h));

    return 0;
}

float trapezioRepetido(int n, float x[n], float y[n], int h){
    int i;
    float soma = 0;

    for(i = 1; i < n-1; i ++){ // todos os elementos menos as extremidadas
        soma = soma + 2 * x[i];
    }

    return (h / 2) * (y[0] + soma + y[n-1]);
}