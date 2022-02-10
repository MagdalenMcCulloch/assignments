//---------------------------------------------------------------------
// magic_square.c 
// CS223 - Spring 2022
// Identify whether a matrix is a magic square
// Name: Magdalen McCulloch 
//
#include <stdio.h>
#include <stdlib.h>

int main() { // I think this needs to take the arg of the text file? 
    // variables 
    int columnsNum = 0;
    int rowsNum = 0; 
    int magicConstant = 0; 

    //read in the file 
    //she says to use scanf, but we still need to do this right? 
    FILE *infile = NULL;
    infile = fopen("magic1.c","r"); 

    fscanf(" %d, %d",&columnsNum,rowsNum);  
    
    
    int* valArr;
    valArr = malloc(sizeof(int)*(columnsNum*rowsNum)); 

    for(int i = 0; i<(columnsNum*rowsNum); i++){
        fscanf("%d",valArr); 
    }
    
    int count = 0; 
    int rowsMagicConstant [rowsNum]; 
    while(valArr[count] != NULL){
        for(int i=0; i <rowsNum; i++){
            rowsMagicConstant[i] += valArr[count]; 
            count++; 
        }
    }





    //compares the magic constant for each row
    //this can go near the bottom 
    int rFirstMagicConstant = rowsMagicConstant[0]; 
    for(int a = 0; a <rowsNum; a++){
        if(rFirstMagicConstant != rowsMagicConstant[a]){
            printf("This is not a magic square"); 
        }
    }




}

