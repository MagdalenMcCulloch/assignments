#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <assert.h>
#include <time.h>
#include <pthread.h>
#include <sys/time.h>
#include <string.h>
#include "read_ppm.h"

pthread_mutex_t mutex; 

struct thread_data{
  long id; 
  int size;
  float xmin; 
  float xmax;
  float ymin;
  float ymax;
  int maxIterations;
  float xfrac; 
  float yfrac;
  float x0; 
  float y0; 
  float x; 
  float y;  
  int iter; 
  float xtemp; 
  int rVal; 
  int gVal; 
  int bVal; 
  int cstart;
  int cend;
  int rstart; 
  int rend;
  struct ppm_pixel* threadMandelbrot; 

}; 

void* routine(void* args){
  // generate pallet
  struct thread_data *data = (struct thread_data *)args; 
  int rcstart = data->cstart; 
  int rcend = data-> cend;
  int rrstart = data-> rstart; 
  int rrend = data-> rend;
  int rsize = data->size;
  float rxmin = -2.0; 
  float rxmax = 0.47;
  float rymin = -1.12;
  float rymax = 1.12;
  int rmaxIterations = 1000;
  float rxfrac = data-> xfrac; 
  float ryfrac = data-> yfrac;
 
  float rx0 = data-> x0; 
  float ry0 = data-> y0; 

  float rx = data-> x; 
  float ry = data-> y;  
 
  int riter = data->iter; 
  float rxtemp = data->xtemp; 
  int rrVal = data->rVal; 
  int rgVal = data->gVal; 
  int rbVal = data->bVal; 
  struct ppm_pixel *rMandelbrot = data->threadMandelbrot; 
    for(int row = rrstart; row < rrend;row++){ // goes through each row
    for(int col = rcstart; col < rcend;col++){ //goes through each col  
      float r = row;
      float c = col; 
      float mySize = rsize; 
      rxfrac = r / mySize; 
      ryfrac = c / mySize;
      
      rx0 = rxmin + rxfrac * (rxmax - rxmin); 
      ry0 = rymin + ryfrac * (rymax - rymin); 

      rx = 0; 
      ry = 0; 
      riter = 0;
       
      while(riter < rmaxIterations && rx*rx + ry*ry < 2*2){
          rxtemp = (rx*rx) - (ry*ry) + rx0;
          ry = (2*rx*ry) + ry0;
          rx = rxtemp;  
          riter++; 
      }
      pthread_mutex_lock(&mutex);
      if(riter < rmaxIterations){ //escaped 
        rrVal = rand()%225; 
        rgVal = rand()%225;
        rbVal = rand()%225;
        rMandelbrot[(row*rsize)+col].red = rrVal; 
        rMandelbrot[(row*rsize)+col].blue = rgVal; 
        rMandelbrot[(row*rsize)+col].green = rbVal; 
      }
      else{
        rMandelbrot[(row*rsize)+col].red = 0; 
        rMandelbrot[(row*rsize)+col].blue = 0; 
        rMandelbrot[(row*rsize)+col].green = 0; 
      }
      pthread_mutex_unlock(&mutex);  
    }  
  }
  free(data); 
  rMandelbrot[(rsize*rsize)].red = 0; 
  rMandelbrot[(rsize*rsize)].blue = 0; 
  rMandelbrot[(rsize*rsize)].green = 0;  
}

int main(int argc, char* argv[]) {
  int size = 480;
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
  printf("Generating threaded mandelbrot with size %dx%d\n", size, size);
  
  printf("  Num processes = %d\n", numProcesses);
  printf("  X range = [%.4f,%.4f]\n", xmin, xmax);
  printf("  Y range = [%.4f,%.4f]\n", ymin, ymax);
  
  // todo: your code here
    //#1 calculate and output the number of seconds needed to generate the image
  struct timeval tstart, tend; 
  double timer;
  
  struct ppm_pixel *mandelbrot; 
  mandelbrot = malloc(sizeof(struct ppm_pixel)*size*size); 
  char name [1000]; 
  char timestamp [20]; 
  char sz [10]; 
  strcpy(name, "thread-mandelbrot-");  
  time_t now = time(0);  
  strftime(timestamp,20, "%Y-%m-%d %H:%M:%S", localtime(&now)); 
  sprintf(sz,"%d",size); 
  strcat(name,sz); 
  strcat(name,timestamp);  
  strcat(name,".ppm");
  printf("%s\n",name);

  srand(time(0));
  gettimeofday(&tstart,NULL);
  
  pthread_t threads[4]; 
  struct thread_data mdata[4]; 
  pthread_mutex_init(&mutex,NULL); 
  for(int i = 0; i < 4; i++){
    pthread_create(&threads[i], NULL,routine, &mdata[i]);
    mdata[i].id = i; 
    mdata[i].size = size; 
    mdata[i].xmin = xmin;
    mdata[i].xmax = xmax;
    mdata[i].ymin = ymin;
    mdata[i].ymax = ymax; 
    mdata[i].maxIterations = maxIterations; 
    mdata[i].xfrac = 0; 
    mdata[i].yfrac = 0; 
    mdata[i].x0 = 0; 
    mdata[i].y0 = 0; 
    mdata[i].x = 0;
    mdata[i].y = 0;
    mdata[i].iter = 0;
    mdata[i].xtemp = 0;
    mdata[i].rVal = 0;
    mdata[i].gVal = 0;
    mdata[i].bVal = 0;
    mdata[i].threadMandelbrot = mandelbrot; 

    if(i ==0){
      mdata[i].cstart = 0; 
      mdata[i].cend = size/2; 
      mdata[i].rstart = 0; 
      mdata[i].rend = size/2;
      printf("Thread %i) sub image block: cols (0, %i) to rows (0,%i)\n",i,(size/2),(size/2)); 
    }
    else if(i == 1){
      mdata[i].cstart = size/2;
      mdata[i].cend = size;
      mdata[i].rstart = 0;
      mdata[i].rend = size/2;
      printf("Thread %i) sub image block: cols (%i, %i) to rows (0,%i)\n",i,(size/2),size,(size/2)); 
    }
    else if(i ==2){
      mdata[i].cstart = 0; 
      mdata[i].cend = size/2;
      mdata[i].rstart = size/2;
      mdata[i].rend = size;
      printf("Thread %i) sub image block: cols (0, %i) to rows (%i,%i)\n",i,(size/2),(size/2),size); 
    }
    else if(i ==3){
      mdata[i].cstart = size/2;
      mdata[i].cend = size; 
      mdata[i].rstart = size/2;
      mdata[i].rend = size; 
      printf("Thread %i) sub image block: cols (%i, %i) to rows (%i,%i)\n",i,(size/2),size,(size/2),size); 
    }
  
  }
 
  for(int i = 0; i < 4; i++){
    pthread_join(threads[i], NULL); 
    printf("Thread %i) finished",i); 
  }
  pthread_mutex_destroy(&mutex); 
  // generate pallet
   // compute image
  gettimeofday(&tend,NULL);
  write_ppm(name,mandelbrot,size,size); //why is write in the loops in the assignment description??
  timer = tend.tv_sec - tstart.tv_sec + (tend.tv_usec - tstart.tv_usec)/1.e6;
  //printf("Launched child complete: %i\n",pid);
  printf("Computed threaded mandelbrot set (480x480) in %g seconds\n",timer);  
  free(mandelbrot); 
 
}
