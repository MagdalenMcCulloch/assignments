//---------------------------------------------------------------------
// match_braces.c
// CS223 - Spring 2022
// Identify matched braces from a given file
// Name: Magdalen McCulloch
//
#include <stdio.h>
#include <stdlib.h>
 
struct node {
  char sym;
  int linenum;
  int colnum;
  struct node* next;
};
 
// Push a new node to a stack (implemented as a linked list).
// The new node should store the given symbol, line number, and column number
// Param sym: a character symbol, '{' for this program
// Param line: the line number of the symbol
// Param line: the column number of the symbol
// Param top: the top node of the stack (NULL if empty)
// Returns the new top of the stack
struct node* push(char sym, int line, int col, struct node* top) {
 
  struct node* newNode = (struct node*)malloc(sizeof(struct node));
  newNode -> sym = sym;
  newNode -> linenum = line;
  newNode -> colnum = col;
  //where should this point
  newNode -> next = top;
  return NULL;
}
 
// Pop the top node from a stack (implemented as a linked list) and frees it
// Param top: the top node of the current stack (NULL if empty)
// Returns the new top of the stack
struct node* pop(struct node* top) {
  if(top != NULL){
    struct node* temp = top;
    top = top -> next;
    free(temp);
  }
  else{
    printf("ERROR: the stack is empty.\n");
  }
 
 
  return NULL;
}
 
// Delete (e.g. free) all nodes in the given stack
// Param top: the top node of the stack (NULL if empty)
void clear(struct node* top) {
  // does this need some sort of loop to free all of them?
  while(top->next != NULL){
    free(top);
  }
  free(top);
}
// Print all nodes in the given stack (from top to bottom)
// Param top: the top node of the stack (NULL if empty)
void print(struct node* top) {
  // how do we print every case of matching braces?
  if(top != NULL){
    printf("Found matching braces");
  }
  else{
    printf("The stack is empty. \n");
  }
}
 
int main(int argc, char* argv[]) {
 
  FILE *infile = fopen("prog1.c","r");
  //int i is our place in the file, maybe the column
  int i = 0;
  int line = 0;
  char currentChar;
  //struct node* stackTop = NULL;  
 // struct node* root = (struct node*)malloc(sizeof(struct node));
 struct node* stackTop = (struct node*)malloc(sizeof(struct node));
 
  //should this have the ampersan??
  while(infile != NULL){
    currentChar = fgetc(infile);
 
    //wait a mean old minute. is that one char or two??
    if(currentChar == '\n'){
      line++;
    }
    else if(currentChar == '{'){
      //{, the line number,the column number,  
      push(currentChar,line,i, stackTop);
    }
    else if(currentChar == '}'){
      //is this what I should be poping?
      pop(stackTop);
      printf("Found matching braces: (%d,%d) -> (%d,%d)",stackTop->linenum, stackTop->colnum,line, i);
    }
  //increase the character count
  i++;
  }
 
  //should these be the variables here??
  print(stackTop);
  clear(stackTop);
  fclose(infile);
 
 
  return 0;
}
