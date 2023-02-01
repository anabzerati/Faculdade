//recursion mario

#include <stdio.h>

void draw(int n);

int main(){
    int height;

    printf("Height: ");
    scanf("%d", &height);

    draw(height);

    return 0;
}

void draw(int n){
    if(n<=0){
        return;
    }
    draw(n-1);
    for(int i=0; i<n; i++){
        printf("#");
    }
    printf("\n");
}