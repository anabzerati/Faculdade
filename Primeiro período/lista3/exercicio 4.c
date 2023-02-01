#include <stdio.h>

int main() {
  float a, b, c, media;

  printf("Insira 3 números: ");
  scanf("%f %f %f", &a, &b, &c);

  media = a + b + c / 3;

  if(media>a || media>b || media>c){
    printf("A média é maior que um dos números digitados.");
  }
    return 0;
}
