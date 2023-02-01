#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define n 5 

int main (){
struct coordenadas{
float x, y;
}coord[n];

float dist[n-1], menor_dist;
int indice, i=0;

//inserção dos pontos
for( i=0; i<n; i++){
printf("Insira as coordenadas em x e y do ponto: ");
scanf("%f %f", &coord[i].x, &coord[i].y);
}

//calculo das distancias
//ref=coord[0].x coord[0].y
for( i=0; i<n-1; i++){
      dist[i]= sqrt(pow((coord[i+1].x-coord[0].x), 2) + pow((coord[i+1].y-coord[0].y), 2));
        if(i==0){
        menor_dist=dist[0];
        } else{
          if(dist[i]<menor_dist){
            menor_dist=dist[i];
            indice = i+1;
          }
        }
        printf("\n(%.2f,%.2f) - (%.2f,%.2f) = %.2f", coord[0].x, coord[0].y, coord[i+1].x, coord[i+1].y, dist[i]);
    }
    
    printf("\nMenor distancia: (%.2f, %.2f) - (%.2f, %.2f) = %.2f", coord[0].x, coord[0].y, coord[indice].x, coord[indice].y, menor_dist);

return 0;
}