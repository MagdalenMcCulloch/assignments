#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "read_ppm.h"
// TODO: Implement this function
// Feel free to change the function signature if you prefer to implement an 
// array of arrays
struct ppm_pixel* read_ppm(const char* filename, int* w, int* h) {
 
  //int magicConstant; 
  char *currentLine; 
  currentLine = malloc(sizeof(char)*34); 
  unsigned char r;
  unsigned char g;
  unsigned char b;


  //read in the file
  FILE* fp = fopen(filename, "r");
  if (fp == NULL) {
    printf("The name of the file is not valid"); 
    return(NULL); 
  }
  
  //reads the first line, should be "P3"
  currentLine =  fgets(currentLine, 32, fp); 

  //gets the width 
  currentLine =  fgets(currentLine, 32, fp);
  //int wi;  
  *w = (int)currentLine[0];
  //w = &wi; 
 
  //int hi; 
  //gets the height  
  *h = (int)currentLine[2]; 
 // h = &hi; 
  //2 bc there is a space between the numbers 

  //checks to see if the width and height are empty
  if((h==NULL)&&(w==NULL)){
    printf("the file is not valid. Memmory cannot be allocated for the image"); 
    return(NULL); 
  }

  //gets the magic constant 
  currentLine =  fgets(currentLine, 32, fp); 
  //magicConstant = atoi(currentLine); 
  
  //now we can allocate memory for the array of RGB triplets 
  struct ppm_pixel *pixArr = NULL; 
  pixArr = (struct ppm_pixel*)malloc(sizeof(struct ppm_pixel)*((*w)*(*h))); 
  
  for(int i =0; i < ((*w)*(*h)); i++){
    //fscanf returns 3 
    fscanf(fp, " %hhu %hhu %hhu", &r, &g, &b); 
    pixArr[i].red = r; 
    pixArr[i].green = g;
    pixArr[i].blue = b; 
    
  }  
   
  fclose(fp); 
  free(currentLine); 
  //free(pixArr); 
  return pixArr;
}