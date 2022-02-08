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
  // yes this is why its called insert sorted 
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
    struct snack currentSnack = *(struct snack*)malloc(sizeof(struct snack)); 
    //struct snack head;

    int snacksNum;
    printf("enter a number of snacks: ");
    scanf("%d",&snacksNum);

    for(int i =0; i<snacksNum; i++){
      printf("enter the snack name: ");
      scanf("%s", currentSnack.name); 
      
      printf("enter the cost: ");
      scanf("%f", &currentSnack.cost); 

      printf("enter the quantity: ");
      scanf("%d", &currentSnack.quantity);
    }
    //represents the current node 
    struct snack* currentSnack = (struct snack*)malloc(sizeof(struct snack)); 
    //struct snack head;
    

   if(head == NULL){
     printf("Error malloc\n"); 
     exit(1); 
   } 


  // todo
  return NULL;
}

// Delete (e.g. free) all nodes in the given list of snacks
// Param snacks: the first node in the list (NULL if empty)
void clear(struct snack* snacks) {
}

int main() {
  return 0;
}

