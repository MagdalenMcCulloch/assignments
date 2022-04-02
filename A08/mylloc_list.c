#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

struct chunk {
  int size;
  int inUse; 
  struct chunk *next;
};
struct chunk *flist = NULL;

void *malloc (size_t size) {
  if (size == 0){
    return NULL;
  }
  void *memory = sbrk(size + sizeof(struct chunk));
  if (memory == (void *) -1) {
    return NULL;
  } else {
    struct chunk* cnk = (struct chunk*) memory;
    return (void*) (cnk + 1);
  }
}

void free(void *memory) {
  return;
}

void fragstats(void* buffers[], int len) {

  int totNumU = 0; 
  int totNumF = 0;
  int total = 0;  

  int largest = 0; 
  int smallest = 1000000; 
  int totalUnused = 0; 
  int average = 0;

  int unused = 0;
 
  for(int i = 0; i < len; i++){

    //for the freed chunks 
    if(buffers[i] == NULL){
      totNumF++; 

    }
    //for the unfreed chunks 
    else if(buffers[i] != NULL){
      totNumU++; 
    } 
    unused = flist-> size - flist->inUse; 
    totalUnused += unused; 
    // calculate the largest chunk 
    if(largest < unused){
      largest = unused; 
    }
    //calculte the smallest 
    if(smallest > unused){
      smallest = unused; 
    } 
  }
  total = totNumU+totNumF;
  average = totalUnused % total; 

  printf("Total Blocks:  Free:  %i Unused: %i\n",len, total); 
  printf("Internal unused:  total: %i average: %i \n", totalUnused, average); 
  printf("smallest: %i  largest: %i \n",smallest, largest);

  return;
 
}

