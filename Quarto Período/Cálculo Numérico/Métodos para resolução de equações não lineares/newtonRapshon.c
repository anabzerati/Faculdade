/* Xi+1 = Xi - F(Xi)/F'(Xi) */

#include<stdio.h>
#include <stdlib.h>
#include<math.h>

#define f(x) 3*x - cos(x) -1
#define g(x) 3 + sin(x) //derivada de f(x)

int main() {
	int i;
	float x0 , x1, e;
	 
	printf("Aproximação inicial: ");
	scanf("%f", &x0);

    printf("Precisão desejada: ");
    scanf("%f", &e);

    x1 = x0;
	do { //ainda não atingiu precisão desejada
        x0 = x1;

        float f = f(x0);
        float g = g(x0);

        if(g == 0){
            printf("Divisão por zero");
            exit(1);
        }

        x1 = x0 - f/g;

    } while(fabs(x1-x0) > e);
	 
	printf("\nA raíz é %f", x1);
	
	return(0);
}