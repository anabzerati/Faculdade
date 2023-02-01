//exercicios complementares função - Escreva uma função	que	calcule e	retorne a	distância	entre	dois	pontos	(x1, y1)	e	 (x2, y2).	Todos	os números	e	 valores	de	 retorno	devem	ser	do	tipo	float.

#include <stdio.h>
#include <math.h>

#define n 2

float distancia(float x1, float x2, float y1, float y2);

int main(){
    struct pontos{
        float x, y;
    } pontos[n];

    for(int i=0; i<n; i++){
        printf("Inisra as coordenadas em (x,y): ");
        scanf("%f %f", &pontos[i].x, &pontos[i].y);
    }

    printf("A distancia entre os pontos é de: %f", distancia(pontos[0].x,pontos[1].x, pontos[0].y, pontos[1].y));
    return 0;
}

float distancia(float x1, float x2, float y1, float y2){
    return sqrt(pow((x1-x2),2)+pow((y1-y2),2));
}