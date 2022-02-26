#include <stdio.h>
#include <stdlib.h> 

int main() {
  // variables 
  char binaryNum[8]; 
  char symbol; 
  //get the binary character
  printf("Enter 8 bits: "); 
  scanf("%s", binaryNum);

  // transform it 
  symbol = strtol(binaryNum,0,2); 

  // print the ascii 
  printf("Your character is: %c\n",symbol); 

  return 0;
}
