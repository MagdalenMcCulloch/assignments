#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 //stores information about snack
struct snack {
  char name[32];
  float cost;
  int quantity;
};
 
int main() {
  int snacksNum;
  printf("enter a number of snacks: ");
  scanf("%d",&snacksNum);
  //creates variables for the struct as many snacks as the user wants
  struct snack *snacksStruct; 
  snacksStruct = malloc(snacksNum);

  //struct snack snacksStruct[snacksNum]; 
  
  for(int i = 0; i <snacksNum; i++){
    printf("enter the snack name: ");
    scanf("%s", snacksStruct[i].name); 
    
    printf("enter the cost: ");
    scanf("%f", &snacksStruct[i].cost); 

    printf("enter the quantity: ");
    scanf("%d", &snacksStruct[i].quantity);
  
  } // for loop
  // prints the snackbar
  for(int i = 0; i <snacksNum; i++){
    printf("%d) %s\tcost: $%0.2f\tquantity: %d\n",
            i,snacksStruct[i].name,snacksStruct[i].cost,
            snacksStruct[i].quantity);
  }
  free(snacksStruct); 
  return 0;
}
