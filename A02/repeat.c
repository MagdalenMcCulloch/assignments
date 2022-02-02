#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
int main() {
  char *s; // char pointer array for the string entered
  // should n be dynamic???
  int n;
 // char *repeatS; //char pointer array for the string produced
  // the entered string can be at most 20 chars long
  s = malloc(sizeof(char)*20);
 
  printf("Enter a word: ");
  scanf("%s",s);
  printf("Enter a count: ");
  scanf("%d",&n);
 
  //allocated an array of size n* (the size of an int [4]) * (the length of s) on the heap
  // must be after print statements  
  //repeatS = malloc(sizeof(char)*strlen(s)*20);
 
  for(int i =0; i <n; i++){
    printf("%s",s);
  }
  printf("\n");
  free(s);
 
  return 0;
}
