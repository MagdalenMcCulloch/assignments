#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "read_ppm.h" 

int main(int argc, char** argv) {
  // first read it in 
  int width = 0; 
  int height = 0;  
  
  struct ppm_pixel *testArr; 
  testArr = read_ppm(argv[1], &width, &height);
  //printf("%ls",w); 
  //printf("%ls",h); 
  
  //then modify   
  for(int i = 0; i < (width*height); i++){
    testArr[i].red = testArr[i].red << (rand() % 2); 
    testArr[i].green = testArr[i].green << (rand() % 2); 
    testArr[i].blue = testArr[i].blue << (rand() % 2); 
  }
  // then write
  strcat(argv[1],"-glitch.ppm");  
  printf("%s\n",argv[1]); 
  write_ppm(argv[1],testArr, width, height); 
  free(testArr); 
  return 0;
}
