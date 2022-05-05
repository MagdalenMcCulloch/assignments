#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
#include "read_ppm.h"

struct ppm_pixel* read_ppm(const char* filename, int* w, int* h) {

  //variables 
  char currentLine [1024]; 

  //read in the file
  FILE* fp = fopen(filename, "rb");
  if (fp == NULL) {
    printf("The name of the file is not valid"); 
    return(NULL); 
  }
  //reads the first line, should be "P6"
  fgets(currentLine, 32, fp); 
  printf("%s", currentLine); 

  fgets(currentLine, 1024, fp);
  printf("%s", currentLine);  

  if(currentLine[0] == '#'){
    fgets(currentLine, 1024, fp);
    printf("%s", currentLine);  
  }
  //gets the dimensions 
  sscanf(currentLine,"%d %d",w,h);
  fgets(currentLine, 32, fp);
  printf("%s", currentLine); 
  

  //now we can allocate memory for the array of RGB triplets 
  struct ppm_pixel *pixArr = NULL; 
  pixArr = (struct ppm_pixel*)malloc(sizeof(struct ppm_pixel)*((*w)*(*h))); 

  fread(pixArr,sizeof(struct ppm_pixel),((*w)*(*h)),fp);

  fclose(fp);  
  return pixArr;
  return NULL;
}

void write_ppm(const char* filename, struct ppm_pixel* pixels, int w, int h) {

   // open the file 
  FILE* fp = fopen(filename, "wb");
  if (fp == NULL) {
    printf("The name of the file is not valid\n");  
  }
  fprintf(fp,"P6\n%d %d\n255\n",w,h); 
  fwrite(pixels,sizeof(struct ppm_pixel),(w*h),fp);
  fclose(fp);
}

