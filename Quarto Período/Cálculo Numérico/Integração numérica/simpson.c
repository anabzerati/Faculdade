// Integração numérica utilizando fórmulas de quadratura pela regra 1/3 de simpson
// Is(f, a, b) = h/3 * (f(a) + 4f((a+b)/2) f(b)), sendo h = (b-a)/2

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float f(float x){
    return (1 / (1 + pow(x, 2)));
}

int main(){
    float a, b;

    printf("Insira o intervalo de integração [a,b]:\n");
    printf("a = ");
    scanf("%f", &a);

    printf("b = ");
    scanf("%f", &b);

    float h = (b - a)/2;
    float c = (a+b)/2;
    float I = (h/3) * (f(a) + 4*f(c) + f(b));

    printf("\nIs(f, %f, %f) = %f\n", a, b, I);

    return 0;
}