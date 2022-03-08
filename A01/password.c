//password
#include <stdio.h>
#include <string.h>
int main() {
// declaring variables
char word[64]; //char array for entered word
printf("type in a word to create a bad password: ");
scanf("%s", word);
 
for (int i=0; i <strlen(word); i++){
  char currentChar = word[i];
  if (word[i] == 'e'){
    word[i] = '3'; 
  }
  else if (word[i]== 'l'){
    word[i] = '1';
  }
  else if(word[i]== 'a'){
    word[i] = '@';
  }  
}
 printf("%s\n",word);
}
