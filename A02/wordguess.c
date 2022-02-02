#include <stdio.h>
#include <string.h>
#include <stdlib.h>
 
int main() {
  // using one word instead of a file for now
  int turnNum = 0;
  char *word; // will be the word from the file read in
  // the entered string can be at most 20 chars long
  word = malloc(sizeof(char)*20);
  char *guessSpace;
  guessSpace = malloc(sizeof(char)*20);
  //makes every char necessary in guessSpace "_"
  for(int i=0; i < strlen(word); i++){
    printf("_");
  }
  FILE *infile;
 //char word[] = "bacteria";
  printf("welcome to Word Guess!!\n");
  for(int i = 0; i<strlen(word); i++){
  char currentGuess;
  printf("Turn: %d",turnNum);
  turnNum++;
  printf("%s",guessSpace);
  printf("guess a character: ");
  scanf("%c",&currentGuess);
  //fills in the guessed letter in the correct place in guessSpace
  for(int i = 0; i < strlen(word); i++){
    if(word[i] == currentGuess){
      guessSpace [i] = currentGuess;
    }
  }
  }  
  printf("You won in %d turns!\n", turnNum);
  return 0;
}
