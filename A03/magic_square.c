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
    char currentLine [1024]; 
 
    //read in the file
    FILE *infile = NULL;
    infile = fopen("magic1.txt","r");
    
    //gets the number of columns and rows 
    fgets(currentLine,1024,infile); 
    sscanf(currentLine,"%d %d",&rowsNum,&columnsNum);  
   
   
    int* valArr;
    valArr = malloc(sizeof(int)*(columnsNum*rowsNum)); 
    
    for(int b = 0; b<(columnsNum*rowsNum); b++){
        fscanf(infile," %i",&valArr[b]); 
        printf("%i ",valArr[b]); 
        if(b != 0 && ((b+1) % columnsNum == 0)){
            printf("\n"); 
        }
    }  
   
    int count = 0;
    int columnCount = 0;
    int rowsMagicConstant [rowsNum];
    int columnsMagicConstant [columnsNum];
    int d1MagicConstant;
    int d2MagicConstant;
    /*
    //while(valArr[count] != 0){
    for(int z = 0; z < rowsNum; z++){
        rowsMagicConstant[count] = 0; 
        //finds the magic constant of each row
        for(int i=0; i <columnsNum; i++){
            
           // printf(" %i\n",valArr[count]); 
            rowsMagicConstant[i] += valArr[count];
            printf("%i ",rowsMagicConstant[i]); 
            count++;
        }
    } */ 

    for(int i = 0; i < (columnsNum*rowsNum); i++){
        rowsMagicConstant[count] += valArr[i];
        printf(" %i",rowsMagicConstant[count]);
         if(i != 0 && ((i+1) % columnsNum == 0)){
            count++; 
        }
        

    }

    /*
        //adds the columns
        for(int i =0; i <columnsNum; i++){
            for(int a = 0; a <rowsNum; a++){
             columnsMagicConstant[i] += valArr[i*rowsNum*columnCount];
            }
            columnCount++;
        }
        //for the diagnal which begins with the first element in the array
        for(int i=0; i<columnsNum; i += (columnsNum+1)){
            d1MagicConstant+= valArr[i];
        }
        //for the diagnol which begins with the right most
            //element in the first row of the array
        for(int i = rowsNum; i<columnsNum; i +=(columnsNum-1) ){
            d2MagicConstant+= valArr[i];
        }
   
 
    //compares the magic constant for each row and column
    //this can go near the bottom
    int rFirstMagicConstant = rowsMagicConstant[0];
    int cFirstMC = columnsMagicConstant[0];
    for(int b = 0; b <columnsNum; b++){
        if(rFirstMagicConstant != cFirstMC != d1MagicConstant != d2MagicConstant){
            printf("This is not a magic square");
            return 0; 
        }
        else if(cFirstMC != cFirstMC != d1MagicConstant != d2MagicConstant){
            printf("This is not a magic square");
            return 0; 
        }
        else{
            printf("M is a magic square (magic constant %d)", rFirstMagicConstant);
            return 0; 
        }
   
    } */
    
    free(valArr);
    fclose(infile);  
    
}
