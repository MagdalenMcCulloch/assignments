#include <stdio.h>
#include <string.h>
#include <stdlib.h>
 
int main() {
  // using one word instead of a file for now
  int turnNum = 0;
  
  char *word; // will be the word from the file read in
  // the entered string can be at most 32 chars long
  word = malloc(sizeof(char)*32);

  char *guessSpace;
  guessSpace = malloc(sizeof(char)*32); 

  //reads in from the file 
  FILE *infile = NULL;
  infile = fopen("wordlist.txt","r");

  //reads the first line 
  //how do i know what int to put here?? 
  char *fgets(char *word, int 10, FILE *infile); 


  //makes every char necessary in guessSpace "_"
  for(int i=0; i < strlen(word); i++){
    guessSpace[i] = '_'; 
  }

  printf("welcome to Word Guess!!\n");
  //goes at most the length of the alphabet 
  //think i need a while loop 
  for(int i = 0; i<26; i++){ 
    char currentGuess;
    //prints the number of the current turn 
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
    }// for loop
    //prints a statement if the letter they guessed is not in the word 
    if(char *strchr(char *word, char currentGuess) == NULL){
      printf("%c is not in the word",currentGuess); 
    } //if 

  }  // greater for loop 

  printf("You won in %d turns!\n", turnNum);
  return 0;
  free(word); 
  free(guessSpace); 
}
