#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <time.h>
#include "rand.h"

int main (int argc, char* argv[]) {

  // YES GOLD DUST IN THE AIR BLOWING IN THE WIND OFF
  //THE BUTTERFLY'S WINGS SCENTING EVERY BREATH WITH CHERRY BLOSSOMS

  void *init = sbrk(0); 

  printf("the initial top of the heap is %p\n",init); 

  void *second = sbrk(0); 

  printf("the current top of the heap is %p\n",second); 

  int tot = (int) (second - init); 

  printf("increased by %i (0x%x) bytes\n",tot,tot); 

  free(init); 
  free(second); 
  return 0 ;
}
