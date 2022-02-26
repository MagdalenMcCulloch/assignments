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
    FILE *infile = NULL;
    infile = fopen("magic1.txt","r");
 
    scanf(" %d, %d",&columnsNum,&rowsNum);  
   
   
   
    int* valArr;
    valArr = malloc(sizeof(int)*(columnsNum*rowsNum));
 
    for(int i = 0; i<(columnsNum*rowsNum); i++){
        scanf("%d",valArr);
    }
   
    int count = 0;
    int columnCount = 0;
    int rowsMagicConstant [rowsNum];
    int columnsMagicConstant [columnsNum];
    int d1MagicConstant;
    int d2MagicConstant;
    while(valArr[count] != 0){
        //finds the magic constant of each row
        for(int i=0; i <rowsNum; i++){
            rowsMagicConstant[i] += valArr[count];
            count++;
        }
    }
        //adds the columns
        for(int i =0; i <columnsNum; i++){
            for(int a = 0; a <rowsNum; a++){
             columnsMagicConstant[i] += valArr[i*rowsNum*columnCount];
            }
            columnCount++;
        }
        //for the diagnal which begins wit the first element in the array
        for(int i=0; i<columnsNum; i += (rowsNum+1)){
            d1MagicConstant+= valArr[i];
        }
        //for the diagnol which begins with the right most
            //element in the first row of the array
        for(int i = rowsNum; i<columnsNum; i +=(rowsNum-1) ){
            d2MagicConstant+= valArr[i];
        }
   
 
    //compares the magic constant for each row and column
    //this can go near the bottom
    int rFirstMagicConstant = rowsMagicConstant[0];
    int cFirstMC = columnsMagicConstant[0];
    for(int a = 0; a <rowsNum; a++){
        if(rFirstMagicConstant != rowsMagicConstant[a] != d1MagicConstant != d2MagicConstant){
            printf("This is not a magic square");
        }
        if(cFirstMC != columnsMagicConstant[a] != d1MagicConstant != d2MagicConstant){
            printf("This is not a magic square");
        }
        else{
            printf("M is a magic square (magic constant %d)", rFirstMagicConstant);
        }
   
    }
 
    free(valArr);
    fclose(infile);  
 
}
