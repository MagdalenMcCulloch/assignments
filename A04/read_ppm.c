#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "read_ppm.h"
// TODO: Implement this function
// Feel free to change the function signature if you prefer to implement an 
// array of arrays
// the pointers to width and height here are set up outside the function because 
// functions can only return one thing 
struct ppm_pixel* read_ppm(const char* filename, int* w, int* h) {
 
  char currentLine [1024];
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
  fgets(currentLine, 1024, fp); 

  fgets(currentLine, 1024, fp);
  if(currentLine[0] == '#'){
    fgets(currentLine, 1024, fp); 
  }
  //gets the dimensions 
  sscanf(currentLine,"%d %d",w,h); 

  //checks to see if the width and height are empty
  if((h==NULL)&&(w==NULL)){
    printf("the file is not valid. Memmory cannot be allocated for the image"); 
    return(NULL); 
  }

  //gets the magic constant 
  fgets(currentLine, 32, fp);  
  
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
  return pixArr;
}