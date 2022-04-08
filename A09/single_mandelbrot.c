#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <sys/time.h>
#include <string.h>
#include "read_ppm.h"

int main(int argc, char* argv[]) {
  int size = 480;
  float xmin = -2.0;
  float xmax = 0.47;
  float ymin = -1.12;
  float ymax = 1.12;
  int maxIterations = 1000;
 
  int opt;
  while ((opt = getopt(argc, argv, ":s:l:r:t:b:")) != -1) {
    switch (opt) {
      case 's': size = atoi(optarg); break;
      case 'l': xmin = atof(optarg); break;
      case 'r': xmax = atof(optarg); break;
      case 't': ymax = atof(optarg); break;
      case 'b': ymin = atof(optarg); break;
      case '?': printf("usage: %s -s <size> -l <xmin> -r <xmax> -b <ymin> -t <ymax>\n", argv[0]); break;
    }
  }
  printf("Generating mandelbrot with size %dx%d\n", size, size);
  printf("  X range = [%.4f,%.4f]\n", xmin, xmax);
  printf("  Y range = [%.4f,%.4f]\n", ymin, ymax);

  // todo: your work here

  //#1 calculate and output the number of seconds needed to generate the image
  struct timeval tstart, tend; 
  double timer;
  
  struct ppm_pixel *mandelbrot; 
  mandelbrot = malloc(sizeof(struct ppm_pixel)*size*size); 
  char name [1000]; 
  char timestamp [20]; 
  char sz [10]; 
  strcpy(name, "mandelbrot2-"); 
  
  time_t now = time(0);  
  strftime(timestamp,20, "%Y-%m-%d %H:%M:%S", localtime(&now)); 
  sprintf(sz,"%d",size); 
  strcat(name,sz); 
  strcat(name,timestamp);  
  strcat(name,".ppm");
  printf("%s\n",name);

  int xfrac = 0; 
  int yfrac = 0;
 
  int x0 = 0; 
  int y0 = 0; 

  int x = 0; 
  int y = 0;  
 
  int iter = 0; 
  int xtemp = 0; 
  int rVal = 0; 
  int gVal = 0; 
  int bVal = 0; 
  srand(time(0));
  gettimeofday(&tstart,NULL);
  
  for(int r = 0; r < size;r++){ // goes through each row
    for(int c = 0; c < size;c++){ //goes through each col
      
      xfrac = r / size; 
      yfrac = c / size; 
      x0 = xmin + xfrac * (xmax - xmin); 
      y0 = ymin + yfrac * (ymax -ymin); 

      x = 0; 
      y = 0; 
      iter = 0;
       
      while(iter < maxIterations && x*x + y*y < 2*2){
          xtemp = (x*x) - (y*y) + x0;
          y = (2*x*y) + y0;
          x = xtemp;
          printf("%i",iter);  
          iter++; 
      }
       
      if(iter < maxIterations){ //escaped 
        rVal = rand()%225; 
        gVal = rand()%225;
        bVal = rand()%225;
        mandelbrot[iter].red = rVal; 
        mandelbrot[iter].blue = gVal; 
        mandelbrot[iter].green = bVal; 
      }
      else{
        mandelbrot[iter].red = 0; 
        mandelbrot[iter].blue = 0; 
        mandelbrot[iter].green = 0; 
      } 
    }  
  }
  mandelbrot[(size*size)].red = 0; 
  mandelbrot[(size*size)].blue = 0; 
  mandelbrot[(size*size)].green = 0;
  
  // generate pallet
 // srand(time(0));

  // compute image
  gettimeofday(&tend,NULL);
  write_ppm(name,mandelbrot,size,size); //why is write in the loops in the assignment description??
  timer = tend.tv_sec - tstart.tv_sec + (tend.tv_usec - tstart.tv_usec)/1.e6;
  printf("Computed mandelbrot set (480x480) in %g seconds\n",timer);  

   
}
