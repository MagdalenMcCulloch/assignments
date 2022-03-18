#include <stdio.h>
#include <stdlib.h>
#include "read_ppm.h"

int main(int argc, char** argv) {
  //variables
  int width = 0; 
  int height = 0; 
  int r = 0;
  int b = 0;
  int g = 0; 
  int mCounter = 0; 
  //char symbolChar; 

  struct ppm_pixel *pixelArr; 
  pixelArr = read_ppm(argv[1], &width, &height); 

  char *message; 
  message = malloc((sizeof(char))*(width*height)); 

  char *symbolNum; 
  symbolNum = malloc((sizeof(char))*9);
 
  for(int counter = 0; counter < (width*height); counter++){
    r = pixelArr[counter].red; 
    g = pixelArr[counter].green; 
    b = pixelArr[counter].blue; 
    printf("%i %i %i",r,g,b); 
    // red cases
    if(r%2 == 0){
      message[mCounter] = 0;
      mCounter++;  
    }
    else if(r%2 == 1){
      message[mCounter] = 1; 
      mCounter++; 
    }
    //green cases 
    if(g%2 == 0){
      message[mCounter] = 0;
      mCounter++;  
    }
    else if(g%2 == 1){
      message[mCounter] = 1; 
      mCounter++; 
    }
    //blue cases s
    if(b%2 == 0){
      message[mCounter] = 0;
      mCounter++;  
    }
    else if(b%2 == 1){
      message[mCounter] = 1; 
      mCounter++; 
    }
    counter++; 
  }
  
  printf("reading %s with width %i and height %i \n",*argv,width,height); 
  printf("Max number of characters in the image: %i\n",((width*height*3)/8)); 
 // wont read anything after the previous print statement 
 // int num = 0;
  //printf("%i", mCounter); 
  for(int i = 0; i < mCounter; i++){
    printf("hi"); 
    printf("%c",message[i]); 

  }
    /*
    symbolNum[num] = message[i]; 
    
    if(i != 0 && (i+1)%8 == 0){
      symbolChar = strtol(symbolNum,0,2); 
      printf("%c",symbolChar); 
      num = 0; 
    }
    num++;  
  }
  */ 
  free(pixelArr);
  free(message); 
  free(symbolNum);
  return 0;
}

