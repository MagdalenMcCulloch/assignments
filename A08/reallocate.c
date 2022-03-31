#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <time.h>
#include "rand.h"

int main (int argc, char* argv[]) {
  int tot = 0;  
  for (int i = 0; i < 11; i++){ 
    int *memory = NULL;
    memory = malloc(25*sizeof(int));
    printf("%ls\n",memory); 
    //tot += (int) memory;  
    free(memory);    
  }
  printf("total bytes malloced %i",tot); 
 
  return 0 ;
}
