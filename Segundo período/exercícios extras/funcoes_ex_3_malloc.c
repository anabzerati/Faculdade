#include <stdio.h>
#include <stdlib.h>

int main(){
    int *pa,*pb;

    pa=malloc(sizeof(int));
    pb=malloc(sizeof(int));

    *pa=4;
    *pb=9;

    printf("%d %d",*pa, *pb);
    printf("\n%p||%p",pa,pb);

    if(pa>pb){
        printf("\n%d",*pa);
    }else{
        printf("\n%d", *pb);
    }

    return 0;
}