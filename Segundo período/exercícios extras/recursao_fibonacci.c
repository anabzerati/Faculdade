/*printar n primeiros termos da sequencia de fibonacci*/

#include <stdio.h>

int fibonacci(int n);

int main(){
    int quant, i;

    scanf("%d", &quant);
    
    for(i=0; i<quant; i++){
        printf("%d ", fibonacci(i));
    }

    return 0;
}

int fibonacci(int n){
    if(n==0||n==1){
        return n;
    } else{
        return fibonacci(n-1) + fibonacci(n-2);
    }
}