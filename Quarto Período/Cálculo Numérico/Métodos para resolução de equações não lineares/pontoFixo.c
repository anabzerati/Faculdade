/*Método do ponto fixo*/

#include<stdio.h>
#include<math.h>

#define f(x) cos(x)-3*x+1
#define g(x) (1+cos(x))/3

int main()
{
	int i=1, max = 100;
	float x0, x1, e;
	 
	printf("Aproximação inicial: ");
	scanf("%f", &x0);
	printf("Precisão da aproximação: ");
	scanf("%f", &e);
	 
	do{
		x1 = g(x0);
		i++;
		
		if(i > max){
			printf("Sequência não converge.");
			exit(0);
		}
		  
		x0 = x1;
	}while(fabs(f(x1)) > e);
	 
	printf("\nA raíz é %f", x1);
	
	return(0);
}