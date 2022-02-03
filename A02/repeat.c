#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
int main() {
  char *s; // char pointer array for the string entered
  // should n be dynamic???
  int n;
  // the entered string can be at most 32 chars long
  s = malloc(sizeof(char)*32);
 
  printf("Enter a word: ");
  scanf("%s",s);
  printf("Enter a count: ");
  scanf("%d",&n);
 
 //prints the string n times 
  for(int i =0; i <n; i++){
    printf("%s",s);
  }
  printf("\n");
  free(s);
 
  return 0;
}
