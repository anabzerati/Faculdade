#include <stdio.h>
#include <math.h>
#include <string.h>

int main(){
    int N, M, i, j, op, indice1, indice2;
    char planeta1[21], planeta2[21];
    double dist;

    typedef struct planeta{
        char nome[21];
        double peso, x, y, z;
    }Tplaneta;

    
    scanf("%d %d", &N, &M);

    Tplaneta planetas[N];

    for(i=0;i<N;i++){
        scanf(" %s %lf %lf %lf %lf", planetas[i].nome, &planetas[i].peso, &planetas[i].x, &planetas[i].y, &planetas[i].z);
    }

    for(i=0;i<M;i++){
        scanf(" %d",&op);
            if(op==1){
                scanf(" %s", planeta1);
                scanf(" %s", planeta2);
                for(j=0;j<N;j++){
                  if(strcmp(planetas[j].nome,planeta1)==0){
                    indice1=j;
                    } 
                    if(strcmp(planetas[j].nome,planeta2)==0){ 
                    indice2=j;
                        }
                    }
                dist = sqrt(pow(planetas[indice2].x-planetas[indice1].x,2)+pow(planetas[indice2].y-planetas[indice1].y,2)+pow(planetas[indice2].z-planetas[indice1].z,2));
                printf("%.2lf\n", dist);
            } 
            if(op==2){
                scanf(" %s", planeta1);
                for(j=0;j<N;j++){
                  if(strcmp(planetas[j].nome,planeta1)==0){
                    indice1=j;
                        }
                    }
                printf("%.lf %.lf %.lf\n",planetas[indice1].x, planetas[indice1].y, planetas[indice1].z);
            } 
            if(op==3){ 
                scanf(" %s", planeta1);
                for(j=0;j<N;j++){
                  if(strcmp(planetas[j].nome,planeta1)==0){
                    printf("%.2lf\n",planetas[j].peso);
                    }
                 }                
            }
                    
        }
    return 0;
    }   