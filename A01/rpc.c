#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>
//function
// char array return type????
void game(int rounds){
 
  int AIscore;
  int UserScore;
 
 
  int UserisRock  = strcmp(userchoice, "rock");
  int UserisPaper = strcmp(userchoice, "paper");
  int UserisScissors = strcmp(userchoice, "scissors");
 
  for(int i =0; i < rounds; i++) {
    printf("Which do you choose? rock, paper, or scissors?\n");
    scanf("%s",&userchoice);
 
  //choses rock paper or scissors for the computer
    int AIchoice = rand() % 3;
    if(AIchoice = 0){
      printf("AI chose rock\n");
   }
 
    if(AIchoice = 1){
      printf("AI chose paper\n");
   }
   if(AIchoice = 2){
     printf("AI chose scissors\n");
   }
 
  if(UserisRock > 0 || UserisPaper > 0 || UserisScissors > 0){
    printf("you entered an invalid choice %s/n",userchoice);
  }
  // user winning cases
  else  if((UserisRock == 0) && (AIchoice == 2)){ //ai chose scissors
    UserScore++;
  }
  else  if((UserisPaper == 0) && (AIchoice == 0)){ //ai chose rock
    UserScore++;
  }
  else  if((UserisScissors == 0) && (AIchoice == 1)){ //ai chose paper
    UserScore++;
  }
  //user loosing cases  
  else  if((UserisRock == 0) && (AIchoice == 1)){ //ai chose paper
    AIscore++;
  }
  else  if((UserisPaper == 0) && (AIchoice == 2)){ //ai chose scissors
    AIscore++;
  }
  else  if((UserisScissors == 0) && (AIchoice == 0)){ //ai chose rock
    AIscore++;
  }
}
   
  printf("AI score: %d, Player score: %d",scores[0],scores[1]);
}
int main() {
  //declare variables
  int rounds; //number of rounds user choses to play
  char userchoice[9]; //user's choice between rock, paper, and scissors
 
  printf("Welcome to Rock, Paper, Scissors!\n");
  printf("How many rounds do you want to play?\n");  
  scanf("%d",&rounds);
 
  // the user and computer will play the game rounds times
  for(int i =0; i < rounds; i++) {
    printf("Which do you choose? rock, paper, or scissors?\n");
    scanf("%s",&userchoice);
 
   //remember to call the function
  // int results[] = game(char userchoice[]);
  // printf("AI score: %d, Player score:%d",results[0],results[1]);
   
   
 
  }
  printf("AI score: %d, Player score: %d",scores[0],scores[1]);
 
 
 // srand(time(0));
  return 0;
}
