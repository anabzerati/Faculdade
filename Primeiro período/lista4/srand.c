#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
  srand(time(NULL));
 
  for(int i = 0; i<4; i++)
      printf(" %d ", rand()%10);
 
    return 0;
}