/* Elabore uma func¸ao que receba duas strings como par ˜ ametros e verifique se a segunda ˆ
string ocorre dentro da primeira. Use aritmetica de ponteiros para acessar os caracteres ´
das strings.*/

#include <stdio.h>

int compara(char *s1, char *s2);

int main(){
    char s1[20], s2[20];
    int flag;

    scanf("%s", s1);
    scanf(" %s", s2);

    flag = compara(s1,s2);

    if(flag==0){
        printf("Não está contida!");
    } else{
        printf("Está contida!");
    }

    return 0;
}

int compara(char *s1, char *s2){
    int i=0, j=0;
    for(i=0; *(s1+i)!= '\0'; i++){
        while(*(s1+i) == *(s2+i)){
            i++; j++;
            if(*(s2+i)=='\0'||*(s2+i)=='\n'){
                return 1;
            }
    }
    return 0;
}
}