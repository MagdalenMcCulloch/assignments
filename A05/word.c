#include <stdio.h>

int main() {
  // variables 
  char word[4]; 

  unsigned int num = 0x00000000; 

  //gets the word as a char array
  printf("Enter a word: ");
  scanf("%s", word);

  //change each character to hexidecimal 
  for(int i = 3; i > -1; i--){
    printf("Debug: %c = 0x%0x \n",word[i], word[i]); 

  }
   
  printf("Your number is: %u (0x",num); 
  for(int i = 0; i < 4; i++){
    printf("%0x",word[i]); 
  }
  printf(")\n"); 

  return 0;
}
