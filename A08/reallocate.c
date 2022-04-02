#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <time.h>
#include "rand.h"

int main (int argc, char* argv[]) {
  int tot = 0;  
  for (int i = 0; i < 11; i++){ 
    size_t size = 25*sizeof(int); 
    tot += size; 
    int *memory = NULL; 
    memory = malloc(size); 
    free(memory);    
  }
  printf("total bytes malloced %i\n",tot); 
 
  return 0 ;
}
