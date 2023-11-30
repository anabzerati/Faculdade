// Integração numérica utilizando fórmulas de quadratura pela regra do trapézio
// It(f, a, b) = ((b-a)/2) * (f(a) + f(b))

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

    float h = b - a;
    float I = (h/2) * (f(a) + f(b));

    printf("\nI(f, %f, %f) = %f\n", a, b, I);

    return 0;
}