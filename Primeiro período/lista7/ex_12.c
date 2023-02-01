//a partir do registro indicado para resolver o exercicio 11, crie uma estrutura chamada retangulo. faça um programa q receba via teclado as infirmações que permitem definir um retangulo e informe area e 
//comprimento de cada asresta

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define n 4

int main(){
    struct retangulo{
        float x, y, dist;
    } ret[n];

    printf("Coordenadas para retangulo: ");
    for(int i=0; i<n; i++){
        if(i<2){
            printf("\nPontos da parte superior: ");
        } else{
            printf("\nPontos da parte inferior: ");
        }
        printf("(x,y): ");
        scanf("%f %f", &ret[i].x, &ret[i].y);
    }

    ret[0].dist = sqrt(pow(ret[0].x - ret[1].x, 2) + pow(ret[0].y - ret[1].y, 2));
	ret[1].dist = sqrt(pow(ret[2].x - ret[3].x, 2) + pow(ret[2].y - ret[3].y, 2));
	ret[2].dist = sqrt(pow(ret[0].x - ret[2].x, 2) + pow(ret[0].y - ret[2].y, 2));
	ret[3].dist = sqrt(pow(ret[1].x - ret[3].x, 2) + pow(ret[1].y - ret[3].y, 2));
    
    if(ret[0].dist==ret[1].dist && ret[2].dist==ret[3].dist){
        printf("\nComprimento das arestas do retangulo: %f e %f.", ret[0].dist, ret[2].dist);
        printf("\nÁrea do retangulo: %f.", ret[0].dist * ret[2].dist);
    } else{
        printf("Com essas coordenadas não é possível formar um retangulo.");
    }



    return 0;
}