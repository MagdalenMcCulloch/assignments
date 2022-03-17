#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "read_ppm.h"

// TODO: Implement this function
// Feel free to change the function signature if you prefer to implement an 
// array of arrays
struct ppm_pixel* read_ppm(const char* filename, int* w, int* h) {
  
 
  char currentLine [1024];   

  //read in the file
  FILE* fp = fopen(filename, "rb");
  if (fp == NULL) {
    printf("The name of the file is not valid"); 
    return(NULL); 
  }
  //reads the first line, should be "P6"
  fgets(currentLine, 1024, fp); 

  fgets(currentLine, 1024, fp);
  if(currentLine[0] == '#'){
    fgets(currentLine, 1024, fp); 
  }
  //gets the dimensions 
  sscanf(currentLine,"%d %d",w,h);

  fgets(currentLine, 1024, fp); 
  
  //print the dimensions
    printf("reading %s with width %ls and height %ls\n",*filename, w, h); 

  //now we can allocate memory for the array of RGB triplets 
  struct ppm_pixel *pixArr = NULL; 
  pixArr = (struct ppm_pixel*)malloc(sizeof(struct ppm_pixel)*((*w)*(*h))); 
  
 // for(int i =0; i < ((*w)*(*h)); i++){
    //fscanf returns 3 
   // fscanf(fp, " %hhu %hhu %hhu", &r, &g, &b); 
   //copies in the pixel data to the array as one big block 
   fread(pixArr,sizeof(struct ppm_pixel),((*w)*(*h)),fp); 
 
   
  fclose(fp); 
  //free(pixArr); 
  return pixArr;
 // return NULL;
}

// TODO: Implement this function
// Feel free to change the function signature if you prefer to implement an 
// array of arrays
extern void write_ppm(const char* filename, struct ppm_pixel* pxs, int w, int h) {
  
  // open the file 
  FILE* fp = fopen(filename, "wb");
  if (fp == NULL) {
    printf("The name of the file is not valid");  
    return 0; 
  }
  printf("Writing file %s\n",filename); 
  fprintf(fp,"P6\n %d %d\n 255",w,h); 
  fwrite(pxs,sizeof(struct ppm_pixel),(w*h),fp); 


  fclose(fp); 
  
  

}
