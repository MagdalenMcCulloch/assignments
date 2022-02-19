#include <stdio.h>
#include <stdlib.h>
#include "read_ppm.h"
#include "read_ppm.c"

int main() {

  int w = 0; 
  int h = 0; 
  int counter = 0; 
  //how do I decide how big to make it?? 
  //what should the parameters be??? 
  struct ppm_pixel *testArr; 
  testArr = read_ppm("feep-ascii.ppm", &w, &h); 

  printf("testing file feep-ascii.ppm: %i %i \n",w,h); 
  

  // todo: call read_ppm
  for(int i = 0; i < 2*sizeof(testArr); i++){
    printf("(%d,%d,%d) ",testArr[i].red, testArr[i].green, testArr[i].blue); 
     
    if(counter == w){
      printf("\n" ); 
      counter = 0; 
    }
    counter++;  
  }
  free(testArr); 
  return 0;
}

