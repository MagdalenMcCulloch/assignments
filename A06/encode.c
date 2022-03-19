#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
#include "read_ppm.h"

int main(int argc, char** argv) {
  //our variables
  int width = 0; 
  int height = 0; 
  
  int r = 0;
  int b = 0;
  int g = 0; 
   
  char *phrase; 
  phrase = malloc(sizeof(char)*34);
  //char newName [1024]; 
  int phraseLen = 0; 
   
  int maxChars = 0;
  //the array
  struct ppm_pixel *pixelArr; 
  pixelArr = read_ppm(argv[1], &width, &height);  
  maxChars = (((width*height*3)/8)-1); 

  //print statements 
  printf("Reading %s with width %i and height %i \n",argv[1],width,height);
  printf("Max number of characters in the image: %i\n",maxChars); 
  
  printf("Enter a phrase: ");
  scanf("%s",phrase); 
  strcat(argv[1],"-encoded.ppm");
  printf("Writing file %s\n",argv[1]);

  if(phrase == NULL){
    return 0; 
  }
  char currentChar; 
  phraseLen = strlen(phrase);
  char *binaryPhrase; 
  binaryPhrase = malloc(phraseLen*8 +1); 
  binaryPhrase[0] = '\0'; 

  for(int i = 0; i<phraseLen; i++){
    currentChar = phrase[i]; 
    for(int a = 7; a >= 0; a--){
      if(currentChar &(1<<a)){
        strcat(binaryPhrase,"1"); 
      }
      else{
        strcat(binaryPhrase,"0"); 
      }
    }
  }
  for(int i = (phraseLen*8 +1); i >= 0;i = i-3){
    r = pixelArr[i].red; 
    g = pixelArr[i].green; 
    b = pixelArr[i].blue; 

    //red cases
    if (binaryPhrase[i] == 0){
      // if its even we are good 
      // if its odd we need to make it even
      if(r%2 == 1){
        r--; 
        pixelArr[i].red = r; 
      }
    }
    else if (binaryPhrase[i] == 1){
      if(r%2 == 0){
        r--; 
        pixelArr[i].red = r; 
      }
    }
    //green
    if (binaryPhrase[i-1] == 0){
      if(g%2 == 1){
        g--;
        pixelArr[i].green = g; 
      }

    }
    else if (binaryPhrase[i-1] == 1){
      if(g%2 == 0){
        g--;
        pixelArr[i].green = g; 
      }
      
    }
    //blue cases
    if (binaryPhrase[i-2] == 0){
      if(b%2 == 1){
        b--;
        pixelArr[i].blue = b; 
      }
    }
    else if (binaryPhrase[i-2] == 1){
      if(b%2 == 0){
        b--;
        pixelArr[i].blue = b; 
      }
      
    }
  }

  write_ppm(argv[1],pixelArr,width,height); 
  free(phrase); 
  free(pixelArr);
  return 0;
}

