/*Entrada: uma linha inteiro N (maior q 3 e menor q 10000), uma linha com número O de 1 a 7, linhas seguem de acordo com a opção
Saída: N linhas com resultado das contas, duas casas decimais.
0 = 1 - dist maru
  = 2 - vel mru
  = 3 - tempo mru
  = 4 - distancia mruv
  = 5 - vrl final mruv
  = 6 - vel inicial mruv
  = 7 - tempo mruv  
*/

#include <math.h>
#include <stdio.h>

double mru_vel(double temp, double dist);
double mru_dist(double vel, double temp);
double mru_temp(double vel,  double dist);
double mruv_dist(double vel, double ac, double temp);
double mruv_vel_final(double vel, double ac, double temp);
double mruv_vel_inicial(double dist, double ac, double temp); 
double mruv_temp(double dist, double vel, double ac);

int main(){
    long int N;
    int O, i;
    double vel, temp, dist, ac, vel_final;

    scanf("%ld", &N);

    for(i=0; i<N; i++){
        scanf("%d", &O);
        switch(O){
            case 1: //distancia mru
                scanf("%lf %lf", &vel, &temp);
                printf("%.2lf\n", mru_dist(vel, temp));
                break;
            case 2: //velocidade mru
                scanf("%lf %lf", &dist, &temp);
                printf("%.2lf\n", mru_vel(temp, dist));
                break;
            case 3: //tempo mru   
                scanf("%lf %lf", &dist, &vel);
                printf("%.2lf\n", mru_temp(vel, dist));
                break;
            case 4: //distancia mruv
                scanf("%lf %lf %lf", &vel, &ac, &temp);
                printf("%.2lf\n", mruv_dist(vel, ac, temp));
                break;
            case 5: //vel final mruv
                scanf("%lf %lf %lf", &vel, &ac, &temp);
                printf("%.2lf\n", mruv_vel_final(vel, ac, temp));
                break;
            case 6: //vel inicial mruv
                scanf("%lf %lf %lf", &dist, &ac, &temp);
                printf("%.2lf\n", mruv_vel_inicial(dist, ac, temp));
                break;
            case 7: //tempo mruv     
                scanf("%lf %lf %lf", &dist, &vel, &ac);
                printf("%.2lf\n", mruv_temp(dist, vel, ac));
                break;
        }
    } 

    return 0;
}

double mru_vel(double temp, double dist){
    double vel;
    vel = dist / temp;
    return vel;
}

double mru_dist(double vel, double temp){
    double dist;
    dist = vel * temp;
    return dist;
}

double mru_temp(double vel,  double dist){
    double temp;
    temp = dist / vel;
    return temp;
}

double mruv_dist(double vel, double ac, double temp){
    double dist;
    dist = (vel*temp) + (ac*temp*temp)/2;
    return dist;
}

double mruv_vel_final(double vel, double ac, double temp){
    double vel_f;
    vel_f = vel + (ac*temp);
    return vel_f;
}

double mruv_vel_inicial(double dist, double ac, double temp){
    double vel_i;
    vel_i = (dist - (ac*temp*temp)/2)/temp;
    return vel_i;
}

double mruv_temp(double dist, double vel, double ac){
    double temp, vel_f;
    vel_f = sqrt((vel*vel) + (2*ac*dist));
    temp = (vel_f - vel)/ac;
   return temp;
}