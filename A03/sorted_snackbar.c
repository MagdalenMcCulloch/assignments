//---------------------------------------------------------------------
// sorted_snackbar.c 
// CS223 - Spring 2022
// Ask the user for a list of snacks and store them in alphabetical order
// Name: Magdalen McCulloch 
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct snack { // this is the node i think 
  char name[32];
  int quantity;
  float cost;
  struct snack* next;
};

// Insert a new node to a list (implemented as a linked list).   
// The new node should store the given properties
// Param snacks: the first item in the list (NULL if empty)
// Param name: the snack name (max length is 32 characters)
// Param quantity: the snack quantity
// Param cost: the snack cost
// Returns the first item in the list
struct snack* insert_sorted(struct snack* snacks, 
  const char* name, int quantity, float cost) {
    //represents the current node 
    // not sure if the way I used pointers will work
    struct snack* currentSnack = malloc(sizeof(struct snack)); 
    //struct snack head;
    if(currentSnack == NULL){
      printf("ERROR: Out of space!\n"); 
      exit(1); 
    }

    if(currentSnack -> name >= snacks -> name){
    
      currentSnack -> name = snacks -> name; 
      currentSnack -> quantity = snacks -> quantity; 
      currentSnack -> cost = snacks -> cost; 
      currentSnack -> next = snacks -> next; 

    }

    else if (currentSnack -> name < snacks -> name){
      // i feel like in this case we need the previous pointing at the current snack
    currentSnack->name = name; 
    currentSnack->quantity = quantity; 
    currentSnack-> cost = cost; 
    currentSnack-> next = snacks; 
    } 
  // todo
  return currentSnack;
}
// Delete (e.g. free) all nodes in the given list of snacks
// Param snacks: the first node in the list (NULL if empty)
void clear(struct snack* snacks) {
  //how do we know what to free if we don't know how many nodes?? 
  free(snacks); 
}


int main() {
  //should the head be dynamically allocated 
  struct snack* head = NULL; 
  int snacksNum;
  char snackName[32]; 
  float snackCost;
  int snackQuantity; 


    printf("enter a number of snacks: ");
    scanf("%d",&snacksNum);
    //does this look good?/why is there an error?
    for(int i =0; i<snacksNum; i++){
      printf("enter the snack name: ");
      scanf("%s", snackName); 
      
      printf("enter the cost: ");
      scanf("%f", &snackCost); 

      printf("enter the quantity: ");
      scanf( "%d", &snackQuantity);
    }
    insert_sorted(head, snackName, snackQuantity, snackCost); 

  return 0;

}

