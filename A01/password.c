#include <stdio.h> 
#include <string.h>
int main() {

// declaring variables
//int mem; //memory location
char word[10]; //char array for entered word
printf("type in a word to create a bad password:\t");
scanf("%s", &word); 

char* eOccurence; 
eOccurence = strchr(word,'e'); 
while (eOccurence != NULL){
  strcpy(eOccurence,"3"); 
}
char* lOccurence; 
eOccurence = strchr(word,'l'); 
while (eOccurence != NULL){
  strcpy(eOccurence,"1"); 
}
char* aOccurence; 
eOccurence = strchr(word,'a'); 
while (eOccurence != NULL){
  strcpy(eOccurence,"@"); 
}

printf("%s\n",word); 
return 0; 
/*
for (int i=0; i <strlen(word); i++){ 
  char currentChar = word[i]; 
  
  if (word[i] = 'e'){
   // word[i] = '3'; // do we need to de reference??
   //the one you want to change, then the one you are changig it to
   strcpy(word[i],"3"); 
  }
  else if (word[i]= 'l'){
  //  word[i] = '1'; 
    strcpy(word[i],"1"); 
  }
  else if(word[i]= 'a'){
  //  word[i] = '@'; 
    strcpy(word[i],"@"); 
  }

  printf("%s\n",word[i]); 
} */ 

 // return 0;
}
