#include <stdio.h>
#define total 50

int main()
{
	char sexo;
	int num_h=0, num_m=0;
	float altura, maior_h, menor_h, maior_m, menor_m, total_h, total_m, diferenca;
	
	for(int i=0; i<total; i++)
	{  
		do
		{
			printf("Digite o Sexo <m>asculino ou <f>eminino:\n");
			scanf(" %c",&sexo);			
		}while(sexo!='m' && sexo!='f');// valida a entrada	

		printf("\nDigite a altura em metros: ");
		scanf("%f", &altura);
		
		if(sexo=='m')
		{
			if (num_h==0) 
			{ 
				maior_h=altura;
				menor_h=altura;
				total_h=altura; 
			}
			else
			{
				if(altura>maior_h)
				{
					maior_h=altura; 
				}
				else if(altura<menor_h)
				{
					menor_h=altura; 
				}
				total_h=total_h+altura; 
			}
			num_h++; 
		}
		else
		{
			if (num_m==0) 
			{ 
				maior_m=altura;
				menor_m=altura;
				total_m=altura;
			}
			else
			{
				if(altura>maior_m)
				{
					maior_m=altura; 
				}
				else if(altura<menor_m)
				{
					menor_m=altura; 
				}
				total_m=total_m+altura; 
			}
			num_m++; 
		}
	}
	//item (a)
	printf("\n\n\t Maior altura - homem: %.2f",maior_h);
	printf("\n\n\t Menor altura - homem: %.2f",menor_h);
	printf("\n\n\t Maior altura - mulher: %.2f",maior_m);
	printf("\n\n\t Menor altura - mulher: %.2f",menor_m);
	//item (b)
	printf("\n\n\t Altura m�dia - mulheres: %.3f",total_m/num_m);
	printf("\n\n\t Altura m�dia - homens: %.3f",total_h/num_h);
	//item (c)
	printf("\n\n\t N�mero de homens: %d",num_h);
	diferenca=total_h-total_m;
	
	if (diferenca!=0)
		diferenca=(diferenca/(total_h+total_m))*100;
				
	printf("\n\n\t Diferen�a de altura entre homens e mulheres: %.2f%%",diferenca);
	
	//system("PAUSE");
	return 0;
}	
