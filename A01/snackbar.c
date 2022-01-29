#include <stdio.h>

struct snack{
  char snackName[20]; 
  double cost; 
  int quantity; 

}; // remember you need a semi colon at the end of a struct

int main() { //i think we need command line arguments here 
  // define variables for user input 
  double userMoneyAmount; 
  int userSnackChoice;

  struct snack snack1; 
  struct snack snack2; 
  struct snack snack3; 

//defining snack 1
  snack1.snackName[0] = 'p';
  snack1.snackName[1] = 'o'; 
  snack1.snackName[2] = 'p'; 
  snack1.snackName[3] = 'c'; 
  snack1.snackName[4] = 'o'; 
  snack1.snackName[5] = 'r'; 
  snack1.snackName[6] = 'n'; 
  // str.cpy

  snack1.cost = 1.5; 
  snack1.quantity = 3; 

//defining snack 2
  snack2.snackName[0] = 'c';
  snack2.snackName[1] = 'h'; 
  snack2.snackName[2] = 'e'; 
  snack2.snackName[3] = 'e'; 
  snack2.snackName[4] = 's'; 
  snack2.snackName[5] = 'e'; 
  
  snack2.cost = 2.0; 
  snack2.quantity = 2; 

//defining snack 3 
  snack3.snackName[0] = 'a';
  snack3.snackName[1] = 'p'; 
  snack3.snackName[2] = 'p'; 
  snack3.snackName[3] = 'l'; 
  snack3.snackName[4] = 'e';

  snack3.cost = 4.5; 
  snack3.quantity = 0;  

  struct snack snackArr[3]; 
  // add 1, 2, and 3 in there
  snackArr[0]= snack1;
  snackArr[1]= snack2;
  snackArr[2]= snack3; 


  //print statements 
  printf("Welcome to Steven Struct's Snack Bar.\n");
  printf("How much money do you have? "); 
  // gets the amount of monney the user has 
  scanf("%lf\n ",&userMoneyAmount); // theres an error with printing here but idk how  
  for(int i = 0; i <3; i++){
    printf("%d) %s\tcost: $%0.2f\t quantity: %d\n",i,snackArr[i].snackName,snackArr[i].cost,snackArr[i].quantity);
  }
  printf("What snack would you like to buy? [0,1,2]");
  scanf("%d\n", &userSnackChoice); 
  // if statements
  // if they dont have enought money 
  if(snackArr[userSnackChoice].cost > userMoneyAmount){
    printf("That is too expensive for you\n"); 
   // *break; 
  }
  // if the quantity of that snack is 0 
  else if(snackArr[userSnackChoice].quantity = 0){
    printf("Sorry, we ran out of %s\n",snackArr[userSnackChoice].snackName); 
    
  }
  // if they do have enough money 
  if(snackArr[userSnackChoice].cost < userMoneyAmount){
    printf("%s are a good choice\n",snackArr[userSnackChoice].snackName);
    double change =  userMoneyAmount-snackArr[userSnackChoice].cost;  
    printf("You have $%0.2f left\n",change); 
    
  }
}
