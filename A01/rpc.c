#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>

void game(int rounds); 

int main() {
  int r = 0; 
  printf("how many rounds would you like to play?\n");
  scanf("%i", &r);
  game(r);
  return r;  
}

//function
void game(int rounds){
 
  int AIscore = 0;
  int UserScore = 0;
  char AIchoice[10]; 
  char userchoice[10]; 
 
  for(int i =0; i < rounds; i++) {
    printf("Which do you choose? rock, paper, or scissors?\n");
    scanf("%s",userchoice);
 
  //choses rock paper or scissors for the computer
    int AInum = rand() % 3;
    if(AInum == 0){
      strcpy(AIchoice,"rock"); 
   }
    else if(AInum == 1){
      strcpy(AIchoice,"paper");
   }
   else if(AInum == 2){
     strcpy(AIchoice,"scissors");
   }
  //game result cases
  // rock v rock 
  // if(userchoice == "rock" && AInum == 0){
    if(strstr(userchoice,"rock")&& AInum == 0){
     printf("AI chose rock\n"); 
     printf("its a tie!\n");
     printf("AI score: %i, Player Score: %i\n",AIscore,UserScore); 
   }
  //rock v paper
   else if(strstr(userchoice,"rock") && AInum == 1){
    printf("AI chose paper\n"); 
    printf("paper covers rock\n");
    AIscore++; 
    printf("AI score: %i, Player Score: %i\n",AIscore,UserScore); 
   }
   //rock v scissors 
   else if(strstr(userchoice,"rock") && AInum == 2){
     printf("AI chose scissors\n"); 
     printf("rock bashes scissors\n"); 
     UserScore++; 
     printf("AI score: %i, Player Score: %i\n",AIscore,UserScore); 
   }
   //paper v rock
  else if(strstr(userchoice,"paper") && AInum == 0){
    printf("AI chose rock\n"); 
    printf("paper covers rock\n");
    UserScore++; 
    printf("AI score: %i, Player Score: %i\n",AIscore,UserScore); 
   }
   //paper v paper
   else if(strstr(userchoice,"paper") && AInum == 1){
     printf("AI chose paper\n");
     printf("its a tie!\n");
     printf("AI score: %i, Player Score: %i\n",AIscore,UserScore); 
   }
   //paper v scissors
   else if(strstr(userchoice,"paper") && AInum == 2){
     printf("AI chose scissors\n"); 
     printf("scissors cut paper\n");
     AIscore++; 
     printf("AI score: %i, Player Score: %i\n",AIscore,UserScore); 
   }
  //scissors v rock 
   else if(strstr(userchoice,"scissors") && AInum == 0){
    printf("AI chose rock\n");
    printf("rock bashes scissors\n");
    AIscore++; 
    printf("AI score: %i, Player Score: %i\n",AIscore,UserScore); 
   }
   //scissors v paper
   else if(strstr(userchoice,"scissors") && AInum == 1){
     printf("AI chose paper\n");
     printf("scissors cut paper\n"); 
     UserScore++; 
     printf("AI score: %i, Player Score: %i\n",AIscore,UserScore); 
   }
   //scissors v scissors
   else if(strstr(userchoice,"scissors") && AInum == 2){
     printf("AI chose scissors\n"); 
     printf("its a tie!");
     printf("AI score: %i, Player Score: %i\n",AIscore,UserScore); 
   }
   else{
    printf("AI chose %s\n",AIchoice); 
    printf("You entered an invalid choice: %s\n",userchoice); 
    printf("AI score: %i, Player Score: %i\n",AIscore,UserScore); 
   }
  }
  if(UserScore < AIscore){
    printf("The computer won!!\n"); 
  }
  else if(UserScore > AIscore){
    printf("You win!!\n");     
  }
  else{
    printf("You tied with the computer!\n"); 
  }
}
