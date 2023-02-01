/*printar soma dos n primeiros termos da sequencia de fibonacci*/

#include <stdio.h>

int calc_fibonacci(int n);
int sum_fibonacci(int n);

int sum=0;

int main(){
    int quant, i;

    scanf("%d", &quant);
    
    printf("Soma dos %d primeiros termos da sequencia: %d", quant, sum_fibonacci(quant));

    return 0;
}

int sum_fibonacci(int n){
    int valor;
    if(n==1||n==2){
        sum = n;
    }else{
        valor = calc_fibonacci(n);
        sum_fibonacci(n-1);
        sum = sum + valor;
    }
    return sum;
}

int calc_fibonacci(int n){
    if(n==1||n==2){
        return 1;
    } else{
        return calc_fibonacci(n-1) + calc_fibonacci(n-2);
    }
}