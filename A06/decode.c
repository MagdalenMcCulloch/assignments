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
  char symbolChar; 

  struct ppm_pixel *pixelArr; 
  pixelArr = read_ppm(argv[1], &width, &height); 

  char *message; 
  message = malloc((sizeof(char))*(width*height)); 

  //char *symbolNum; 
  //symbolNum = malloc((sizeof(char))*9);
  char symbolNum[8]; 
 
  for(int counter = 0; counter < (width*height); counter++){
    r = pixelArr[counter].red; 
    g = pixelArr[counter].green; 
    b = pixelArr[counter].blue; 
    // red cases
    if(r%2 == 0){
      message[mCounter] = '0';
      mCounter++;  
    }
    else if(r%2 == 1){
      message[mCounter] = '1'; 
      mCounter++; 
    }
    //green cases 
    if(g%2 == 0){
      message[mCounter] = '0';
      mCounter++;  
    }
    else if(g%2 == 1){
      message[mCounter] = '1'; 
      mCounter++; 
    }
    //blue cases s
    if(b%2 == 0){
      message[mCounter] = '0';
      mCounter++;  
    }
    else if(b%2 == 1){
      message[mCounter] = '1'; 
      mCounter++; 
    } 
  }
  
  printf("reading %s with width %i and height %i \n",argv[1],width,height); 
  printf("Max number of characters in the image: %i\n",((width*height*3)/8)); 
 
  int num = 0;
  for(int i = 0; i < mCounter; i++){  
    symbolNum[num] = message[i]; 
    num++; 
    if(i != 0 && num == 8){
      symbolChar = strtol(symbolNum,0,2); 
      printf("%c",symbolChar);
      num = 0; 
    } 
     
  }
  free(pixelArr);
  free(message); 
  return 0;
}

