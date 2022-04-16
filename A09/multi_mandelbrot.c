#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <assert.h>
#include <time.h>
#include <sys/wait.h>
#include <sys/time.h>
#include <sys/shm.h>
#include <sys/ipc.h>
#include "read_ppm.h"
#include <string.h>

int main(int argc, char* argv[]) {
  int size = 2000;
  float xmin = -2.0;
  float xmax = 0.47;
  float ymin = -1.12;
  float ymax = 1.12;
  int maxIterations = 1000;
  int numProcesses = 4;

  int opt;
  while ((opt = getopt(argc, argv, ":s:l:r:t:b:p:")) != -1) {
    switch (opt) {
      case 's': size = atoi(optarg); break;
      case 'l': xmin = atof(optarg); break;
      case 'r': xmax = atof(optarg); break;
      case 't': ymax = atof(optarg); break;
      case 'b': ymin = atof(optarg); break;
      case '?': printf("usage: %s -s <size> -l <xmin> -r <xmax> "
        "-b <ymin> -t <ymax> -p <numProcesses>\n", argv[0]); break;
    }
  }
  printf("Generating mandelbrot with size %dx%d\n", size, size);
  printf("  Num processes = %d\n", numProcesses);
  printf("  X range = [%.4f,%.4f]\n", xmin, xmax);
  printf("  Y range = [%.4f,%.4f]\n", ymin, ymax);

  // todo: your code here
  // code from single!!! 
  //#1 calculate and output the number of seconds needed to generate the image
  struct timeval tstart, tend; 
  double timer;
  
  struct ppm_pixel *mandelbrot; 
  mandelbrot = malloc(sizeof(struct ppm_pixel)*size*size); 
  char name [1000]; 
  char timestamp [20]; 
  char sz [10]; 
  strcpy(name, "multi-mandelbrot-"); 
  
  time_t now = time(0);  
  strftime(timestamp,20, "%Y-%m-%d %H:%M:%S", localtime(&now)); 
  sprintf(sz,"%d",size); 
  strcat(name,sz); 
  strcat(name,timestamp);  
  strcat(name,".ppm");
  printf("%s\n",name);

  // i think we start the forking here; only needs one name 
  int cstart = 0; 
  int cend = 0;
  int rstart = 0; 
  int rend = 0;

  pid_t pid; 

  for(int i = 0; i < 4; i++){
    pid = fork(); 
     
  
    if(i == 0){ 
      cstart = 0; 
      cend = size/2;
      rstart = 0; 
      rend = size/2; 
    }
    else if(i == 1){
      cstart = size/2; 
      cend = size;
      rstart = 0; 
      rend = size/2;
    }
    else if(i == 2){ 
      cstart = 0; 
      cend = size/2;
      rstart = size/2; 
      rend = size; 
    }
    else if(i == 3){
      cstart = size/2; 
      cend = size;
      rstart = size/2; 
      rend = size;
    } 
    printf("Launched child process: %i\n",pid);
    printf("sub image block: col (%i,%i) to rows (%i,%i)\n",cstart,cend,rstart,rend); 


  float xfrac = 0; 
  float yfrac = 0;
 
  float x0 = 0; 
  float y0 = 0; 

  float x = 0; 
  float y = 0;  
 
  int iter = 0; 
  float xtemp = 0; 
  int rVal = 0; 
  int gVal = 0; 
  int bVal = 0; 
  srand(time(0));
  gettimeofday(&tstart,NULL);
  // generate pallet
  for(int row = rstart; row < rend;row++){ // goes through each row
    for(int col = cstart; col < cend;col++){ //goes through each col 
      float r = row;
      float c = col; 
      float mySize = size; 
      xfrac = r / mySize; 
      yfrac = c / mySize;
      
      x0 = xmin + xfrac * (xmax - xmin); 
      y0 = ymin + yfrac * (ymax -ymin); 
      /* used for testing 
      if((c > 400) && (r == 1)){
           printf(" %f",r); 
           printf(" %f",c);
           printf(" %f",x0); 
           printf(" %f\n",y0); 
          } 
         */ 

      x = 0; 
      y = 0; 
      iter = 0;
       
      while(iter < maxIterations && x*x + y*y < 2*2){
          xtemp = (x*x) - (y*y) + x0;
          y = (2*x*y) + y0;
          x = xtemp;  
          iter++; 
      }
       
      if(iter < maxIterations){ //escaped 
        rVal = rand()%225; 
        gVal = rand()%225;
        bVal = rand()%225;
        mandelbrot[(row*size)+col].red = rVal; 
        mandelbrot[(row*size)+col].blue = gVal; 
        mandelbrot[(row*size)+col].green = bVal; 
      }
      else{
        mandelbrot[(row*size)+col].red = 0; 
        mandelbrot[(row*size)+col].blue = 0; 
        mandelbrot[(row*size)+col].green = 0; 
      } 
    }  
  }
  }
  mandelbrot[(size*size)].red = 0; 
  mandelbrot[(size*size)].blue = 0; 
  mandelbrot[(size*size)].green = 0;  

  // compute image
  gettimeofday(&tend,NULL);
  write_ppm(name,mandelbrot,size,size); //why is write in the loops in the assignment description??
  timer = tend.tv_sec - tstart.tv_sec + (tend.tv_usec - tstart.tv_usec)/1.e6;
   printf("Launched child complete: %i\n",pid);
  printf("Computed mandelbrot set (480x480) in %g seconds\n",timer);  
  free(mandelbrot); 
}
