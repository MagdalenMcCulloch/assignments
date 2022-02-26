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
    struct snack* currentSnack = malloc(sizeof(struct snack));
   
    if(currentSnack == NULL){
      printf("ERROR: Out of space!\n");
      exit(1);
    }
    strcpy(currentSnack -> name, name);
    currentSnack->quantity = quantity;
    currentSnack->cost = cost;
    // currentSnack cannot be null
    // need to end when it reached the right place in the list,
    // not when null
    // is this good???
    
    //if its the first snack in the list
    if(snacks == NULL){
      snacks = currentSnack;
    }
    //if the current snack is lexographically earleir than the first snack
    else if((strcmp(snacks-> name, currentSnack -> name))>0){
      // the pointer of current snack will point at the current head 
      currentSnack-> next = snacks; 
      // making currentSnack the head
      snacks = currentSnack; 
    } 
    // if the current snack is lexographically later than the one on the top
    else if((strcmp(currentSnack -> name, snacks-> name))>0){
      currentSnack = currentSnack -> next;
    }
    else{
      while(currentSnack->next != NULL){
       // if the current snack name is lexographically earlier than the one on the top
       if((strcmp(currentSnack -> name, snacks-> name))<0){
     
        strcpy(currentSnack -> name, snacks->name);  
        currentSnack -> quantity = snacks->quantity;
        currentSnack -> cost = snacks->cost;
 
        }
     
      } 
    } 
  // todo
  return snacks;
}
// Delete (e.g. free) all nodes in the given list of snacks
// Param snacks: the first node in the list (NULL if empty)
void clear(struct snack* snacks) {
  //how do we know what to free if we don't know how many nodes??
  // frees each node of snacks except the last
  /*
  for(snacks->next != NULL){
    free(snacks);
  }
  //frees the tail
  free(snacks); */ 
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
 
     head = insert_sorted(head, snackName, snackQuantity, snackCost);  
    }
   
    for(int a = 0; a<snacksNum; a++){
    //for(current = head; current != NULL; current = current-> next)
     // printf("%d) %s\tcost: $%0.2f\tquantity: %d\n",a, current->name, head->cost, head->quantity);
    }  
  
  //clear(*snack); 
  return 0;
 
}

