#include <stdio.h>
#include "read_ppm.h" 

int main(int argc, char** argv) {
  // first read it in 
   int w = 0; 
  int h = 0; 
  int counter = 0; 
  
  struct ppm_pixel *testArr; 
  testArr = read_ppm(*argv, &w, &h);
  //then modify   
  for(int i = 0; i < 2*sizeof(testArr); i++){
    testArr[i].red = testArr[i].red << (rand() % 2); 
    testArr[i].red++; 
    testArr[i].green = testArr[i].green << (rand() % 2); 
    testArr[i].blue = testArr[i].blue << (rand() % 2); 
    
      
  }
  // then write
  strcat(argv,"-glitch.ppm");  
  write_ppm(*argv,testArr,&w,&h); 


  free(testArr); 
  return 0;
}
