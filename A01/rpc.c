#include <stdlib.h>
#include <time.h>
//function 
// char array return type????
char game(char userchoice){
  char userchoice[8]; //user's choice between rock, paper, and scissors 
  int AIscore; 
  int UserScore; 

  printf("Which do you choose? rock, paper, or scissors?\n"); 
  scanf("%s",&userchoice);
  //int AIchoice = srand(time(0))%3;
  int AIchoice = rand() % 3;
  if(AIchoice = 0){
    printf("AI chose rock"); 
  }
  if(AIchoice = 1){
    printf("AI chose paper"); 
  }
  if(AIchoice = 2){
    printf("AI chose scissors"); 
  }
  int AIisRock  = strcmp(AIchoice, "rock"); 
  int AIisPaper = strcmp(AIchoice, "paper"); 
  int AIisScissors strcmp(AIchoice, "scissors");

  int UserisRock  = strcmp(userchoice, "rock"); 
  int UserisPaper = strcmp(userchoice, "paper"); 
  int UserisScissors strcmp(userchoice, "scissors"); 
  if(UserisRock > 0 || UserisPaper > 0 || UserisScissors > 0){
    printf("you entered an invalid choice %s/n",userchoice); 
  }
  // user winning cases 
  else  if(UserisRock = 0 && AIisScissors = 0){
    UserScore++; 
  }
  else  if(UserisPaper = 0 && AIisRock = 0){
    UserScore++; 
  }
  else  if(UserisScissors = 0 && AIisPaper =  0){
    UserScore++; 
  }
  //user loosing cases  
  else  if(UserisRock = 0 && AIisPaper = 0){
    AIscore++; 
  }
  else  if(UserisPaper = 0 && AIisScissors =0){
    AIscore++; 
  }
  else  if(UserisScissors = 0 && AIisRock =0){
    AIscore++; 
  }
  
}
int main() {
  //declare variables 
  int rounds; //number of rounds user choses to play 

   

  printf("Welcome to Rock, Paper, Scissors!\n");
  printf("How many rounds do you want to play?\n");  
  scanf("%d",&rounds); 
  for(int i =0; i < rounds; i++) {
  //printf("Which do you choose? rock, paper, or scissors?\n"); 
  //scanf("%s",&userchoice);
  // call game function  
  } 
 
  srand(time(0));
  return 0;
}

