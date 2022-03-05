#include <stdio.h>
#include <stdlib.h>
#include "read_ppm.h"

int main(int argc, char** argv) {
  int w = 0; 
  int h = 0; 

  
  struct ppm_pixel *testArr; 
  testArr = read_ppm("feep-raw.ppm", &w, &h); 
  write_ppm("test.ppm",testArr,w,h); 
  free(testArr); 
  testArr = read_ppm("test.ppm",&w,&h); 

  printf("testing file feep-raw.ppm: %i %i \n",w,h); 
  
  // todo: call read_ppm
  for(int i = 0; i < (w*h); i++){
    if(i%w == 0){
      printf("\n" );  
    }
    printf("(%d,%d,%d) ",testArr[i].red, testArr[i].green, testArr[i].blue); 
       
  }
  free(testArr); 
  return 0;
}

