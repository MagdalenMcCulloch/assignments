#include <stdio.h>
#include <stdlib.h>
#include "read_ppm.h"

int main(int argc, char** argv) {
  // todo
  int width; 
  int height; 
  struct ppm_pixel *asciiArr;
  asciiArr = read_ppm("smile-ascii.ppm", &width, &height); 
  int currentSymbol = 0; 
   
  
  printf("Reading %s with width %i and height %i\n",*argv,width,height); 
  for(int i=0; i<(width*height); i++){
    currentSymbol += asciiArr[i].red; 
    currentSymbol += asciiArr[i].green; 
    currentSymbol += asciiArr[i].blue; 
    currentSymbol = (currentSymbol/3); 
    
    if(currentSymbol<26){
       printf("@"); 
    }
    else if ((currentSymbol>25)&&(currentSymbol<51)){
      printf("#"); 
    }
    else if ((currentSymbol>50)&&(currentSymbol<76)){
      printf("o/o"); 
    }
    else if ((currentSymbol>75)&&(currentSymbol<101)){
      printf("*"); 
    }
    else if ((currentSymbol>100)&&(currentSymbol<126)){
      printf("o"); 
    }
    else if ((currentSymbol>125)&&(currentSymbol<151)){
      printf(";"); 
    }
    else if ((currentSymbol>150)&&(currentSymbol<176)){
      printf(":"); 
    }
    else if ((currentSymbol>175)&&(currentSymbol<201)){
      printf(","); 
    }
    else if ((currentSymbol>200)&&(currentSymbol<226)){
      printf("."); 
    }
    else if ((currentSymbol>225)&&(currentSymbol<256)){
      printf(" "); 
    }
    currentSymbol = 0;  
    
    if(i != 0 &&((i+1)% width==0)){
      printf("\n");  
    }   
  } 
  
  free(asciiArr); 
  return 0;
}

