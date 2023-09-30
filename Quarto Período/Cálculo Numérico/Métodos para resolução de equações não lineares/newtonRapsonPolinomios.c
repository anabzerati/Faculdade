/* Xi+1 = Xi - F(Xi)/F'(Xi) 
Diferença: usar algoritmo de Briot-Ruffini para calcular F(xi) e F´(Xi)
OBS: apenas se F(x) for função polinomial
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define f(x) 3*pow(x,2) + 5*x -1
#define g(x) 6*x + 5 //derivada de f(x)

#define grau 3
#define a2 3
#define a1 5
#define a0 -1

//aplica algoritmo de Briot-Ruffini para calcular F(x) e F'(x)
void briotRuffini(int coeficiente[grau], float x, float *f, float *g);

int main(){
    int i;
	float x0 , x1, e;
	 
	printf("Aproximação inicial: ");
	scanf("%f", &x0);

    printf("Precisão desejada: ");
    scanf("%f", &e);

    int coeficientes[grau] = {a0, a1, a2};

    x1 = x0;
	do { //ainda não atingiu precisão desejada
        x0 = x1;

        float f, g;
        briotRuffini(coeficientes, x0, &f, &g);

        if(g == 0){
            printf("Divisão por zero");
            exit(1);
        }

        x1 = x0 - f/g;

    } while(fabs(x1-x0) > e);
	 
	printf("\nA raíz é %f", x1);

    return 0;
}

void briotRuffini(int coeficiente[grau], float x, float *f, float *g){
    float bj, bi, cj, ci;
    int i;

    bj = coeficiente[grau - 1];
    cj = bj;

    for(i = grau - 2; i > 0; i --){
        bi = coeficiente[i] + bj * x;
        ci = bi + cj * x;

        bj = bi;
        cj = ci;
    }

    bi = coeficiente[0] + bj * x;

    *f = bi;
    *g = cj;
}