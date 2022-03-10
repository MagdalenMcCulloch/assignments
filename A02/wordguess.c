#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include<time.h>
 
int main() {
  // using one word instead of a file for now
  int turnNum = 0;
  
  char *word; // will be the word from the file read in
  // the entered string can be at most 32 chars long
  word = malloc(sizeof(char)*32);

  //creates the array of "_"
  char *guessSpace;
  guessSpace = malloc(sizeof(char)*32); 
  //represents the number of words in the file 
  int wordsNum = 0; 
  int randomNum = 0; 
  //reads in from the file 
  FILE *infile = NULL;
  infile = fopen("words.txt","r");
  
  //reads the first line 
  word = fgets(word, 32, infile); 

  wordsNum = atoi(word); 

  //finds a random word in the list 
  srand(time(0));
  randomNum = rand(); 
  randomNum = (randomNum%(wordsNum-1))+1;
  for(int i =0; i < randomNum; i++) {
    fgets(word,32,infile); 
  }
  int wordLength = strlen(word); 

  //makes every char necessary in guessSpace "_"
  for(int i=0; i < wordLength-2; i++){
    guessSpace[i] = '_'; 
  }

  printf("welcome to Word Guess!!\n");
  
  //goes until the user fills in all the letters
  while((strchr(guessSpace,'_'))!= NULL){
    
    char currentGuess;
    //prints the number of the current turn 
    printf("Turn: %d\n",turnNum);
    turnNum++;
    printf("%s",guessSpace);
    printf("\nguess a character: ");
    scanf(" %c",&currentGuess);
    //fills in the guessed letter in the correct place in guessSpace
    for(int i = 0; i < wordLength; i++){
      if(word[i] == currentGuess){
        guessSpace [i] = currentGuess;
      }
    }// for loop
    //prints a statement if the letter they guessed is not in the word 
    
    if(strchr(word, currentGuess) == NULL){
      printf("%c is not in the word\n",currentGuess); 
    } //if   

  }  // greater for loop 
  printf("the word was: %s",word); 
  printf("You won in %d turns!\n", turnNum);
  
  //frees the dynamically allocated space 
  free(word); 
  free(guessSpace); 
  free(infile); 
  return 0;
}
