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

    int* val; 

    //read in the file 
    scanf(" %d",&val); 
    //assign values to the rows and columns 
    columnsNum = val[0]; 
    rowsNum = val[1]; 
    //initialize the matrix
    int** matrixSquare; 
    
    matrixSquare = malloc(columnsNum* sizeof(int)); 
    for(int i =0; i < rowsNum; i++){
        matrixSquare[i] = malloc(rowsNum * sizeof(int)); 
    }

    //define in the matrix 
    // it will go column by column 
    for (int i = 0; i < columnsNum; i++){
        matrixSquare = i; 
        //it will stop at every spot in each row 
        for(int i = 0; i <rowsNum; i++){

             
        }

    }



}

