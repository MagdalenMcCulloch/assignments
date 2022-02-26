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
  int elementsNum = 0; 
 // unsigned char r;
 // unsigned char g;
//  unsigned char b;

  //read in the file
  FILE* fp = fopen(filename, "rb");
  if (fp == NULL) {
    printf("The name of the file is not valid"); 
    return(NULL); 
  }
  //reads the first line, should be "P6"
  currentLine =  fgets(currentLine, 32, fp); 
  //reads the second line 
  currentLine =  fgets(currentLine, 32, fp);
   //gets the width 
  *w = (int)currentLine[0];
  //gets the height  
  *h = (int)currentLine[2]; 
  //done this way 2 bc there is a space between the numbers 

  //checks to see if the width and height are empty
  if((h==NULL)&&(w==NULL)){
    printf("the file is not valid. Memmory cannot be allocated for the image"); 
    return(NULL); 
  }
  //gets the number of elements in the file  
  currentLine =  fgets(currentLine, 32, fp); 
  elementsNum = atoi(currentLine); 

  
  //now we can allocate memory for the array of RGB triplets 
  struct ppm_pixel *pixArr = NULL; 
  pixArr = (struct ppm_pixel*)malloc(sizeof(struct ppm_pixel)*((*w)*(*h))); 
  
 // for(int i =0; i < ((*w)*(*h)); i++){
    //fscanf returns 3 
   // fscanf(fp, " %hhu %hhu %hhu", &r, &g, &b); 
   //copies in the pixel data to the array as one big block 
   fread(pixArr,sizeof(struct ppm_pixel),elementsNum,fp); 

   // I don't think I can really use the colors
   // maybe make a for loop to assign colors in 3s to the values 
    //pixArr[i].red = strtol(r,0,2); 
   // pixArr[i].green = strtol(g,0,2); 
   // pixArr[i].blue = strtol(b,0,2); 
   //pixArr[i].red = r; 
   // pixArr[i].green = g;
   // pixArr[i].blue = b; 
    
 // }  
   
  fclose(fp); 
  free(currentLine); 
  //free(pixArr); 
  return pixArr;
  return NULL;
}

// TODO: Implement this function
// Feel free to change the function signature if you prefer to implement an 
// array of arrays
extern void write_ppm(const char* filename, struct ppm_pixel* pxs, int w, int h) {
  
  // open the file 
  FILE* fp = fopen(filename, "wb");
  if (fp == NULL) {
    printf("The name of the file is not valid");  
  }
  fwrite(pxs,sizeof(struct ppm_pixel),(w*h),fp); 
  // really pxs should be pixArr

  //how do we change the name?
  //char *newName; 
  //newName = malloc(sizeof(char)*34);  
  //newName = filename + "-glitch.ppm";
  //rename(filename, newName); 

  fclose(fp); 
  

}
