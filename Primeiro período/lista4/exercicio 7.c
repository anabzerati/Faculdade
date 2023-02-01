
#include <stdio.h>


int main()
{
	int numero, i;
	
	printf("\nDigite um multiplicando\n");
	scanf("%d", &numero);
	
	for (i=0; i<=10;i++)
	{
		printf("\n%d x %d = %d", numero, i, numero*i);	
	}
	//system("PAUSE");
	return 0;
}
