#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// Declarations of the two functions you will implement
// Feel free to declare any helper functions or global variables
void printPuzzle(char** arr);
void searchPuzzle(char** arr, char* word);
void  printFinal(int *row,int* col, int size);
int bSize;
// Main function, DO NOT MODIFY 
int main(int argc, char **argv) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <puzzle file name>\n", argv[0]);
        return 2;
    }
    int i, j;
    FILE *fptr;
    // Open file for reading puzzle
    fptr = fopen(argv[1], "r");
    if (fptr == NULL) {
        printf("Cannot Open Puzzle File!\n");
        return 0;
    }
    // Read the size of the puzzle block
    fscanf(fptr, "%d\n", &bSize);
    
    // Allocate space for the puzzle block and the word to be searched
    char **block = (char**)malloc(bSize * sizeof(char*));
    char *word = (char*)malloc(20 * sizeof(char));
    // Read puzzle block into 2D arrays
    for(i = 0; i < bSize; i++) {
        *(block + i) = (char*)malloc(bSize * sizeof(char));
        for (j = 0; j < bSize - 1; ++j) {
            fscanf(fptr, "%c ", *(block + i) + j);            
        }
        fscanf(fptr, "%c \n", *(block + i) + j);
    }
    fclose(fptr);
    printf("Enter the word to search: ");
    scanf("%s", word);
    
    // Print out original puzzle grid
    printf("\nPrinting puzzle before search:\n");
    printPuzzle(block);
    
    // Call searchPuzzle to the word in the puzzle
    searchPuzzle(block, word);
    
    return 0;
}


void printPuzzle(char** arr) {
// This function will print out the complete puzzle grid (arr). 
    // It must produce the output in the SAME format as the samples 
    // in the instructions.
    // Your implementation here...
    int size = bSize;

    for (int i = 0; i < size; i++) //accessing rows with i
    {
        for (int j = 0; j < size; j++) //accessing columns with j
        {
            printf(" %c ", *(*(arr + i) + j)); // array2D


        }
        printf("\n");
    }
    return;
}

void printFinal(int *row, int* col, int size){
    bSize =bSize ;
                            printf("(%d) \n",bSize);
                        // printf("(%d,%d)",row[0],col[0]);
int hr=0,hc=0;
   int  count = 1;
    //intitalize 2d array using pointer notation
//     int **store= (int**)malloc(bSize* sizeof(int*));
//     for (int i = 0; i < bSize ; i++){
//   *(store + i) = (int*)malloc(bSize* sizeof(int*));

//         for (int j = 0; j < bSize;j++){
//                         // printf("(%d,%d)",row[i],col[j]);

//         //      *(*(store + (row[i])) + (col[j])) = count;
//         // count ++;
//             // if ((*(*(store + i) + j) ) == (*(*(store + (row[i])) + col[j]))){
//                 // if (i==row[i]&& j ==col[j]){
//                     hr=row[i];
//                     hc =col[j];
                
       
//         *(*(store + hr) +hc) = count;
//         count ++;
     
        

//         if( count > bSize){
//             break;
//         }
//         // }
//         }
//         // else {
//         //     (*(*(store + i) + j)) =0;
//         // }

//     }
int j = 0;
  int **store= (int**)malloc(bSize* sizeof(int*));
    for (int i = 0; i < bSize ; i++){
  *(store + i) = (int*)malloc(bSize* sizeof(int*));
    
        
                        // printf("(%d,%d)",row[i],col[j]);

        //      *(*(store + (row[i])) + (col[j])) = count;
        // count ++;
            // if ((*(*(store + i) + j) ) == (*(*(store + (row[i])) + col[j]))){
                // if (i==row[i]&& j ==col[j]){
                    hr= *(row + i);
                    hc = *(col + j );
                
       if(*(*(store + hr) +hc) != 0){
           printf("(%d)",(*(*(store + hr) +hc) * 10)+ count);
              *(*(store + hr) +hc) = (*(*(store + hr) +hc) * 10)+ count ;


       }{
            *(*(store + hr) +hc) = count;
        count ++;
       }
       
     
        

        if( count > bSize){
            break;
        }
        j++;
        // }
        
        // else {
        //     (*(*(store + i) + j)) =0;
        // }

    }

    

          for (int i = 0; i < bSize ; i++){
//   *(store + i) = (int*)malloc(bSize* sizeof(int*));

for (int j = 0; j < bSize;j++){
           
            if ((*(*(store + i) + j) ) > bSize) {
                      
        
            (*(*(store + i) + j)) =0;
        

        }
}
          }
// print

 for (int i = 0; i < bSize ; i++) //accessing rows with i
    {
        for (int j = 0; j < bSize ; j++) //accessing columns with j
        {
            printf(" %d ", *(*(store + i) + j)); // array2D


        }
        printf("\n");
    }

}
void searchPuzzle(char** arr, char* word) {
    // This function checks if arr contains the search word. If the 
    // word appears in arr, it will print out a message and the path 
    // as shown in the sample runs. If not found, it will print a 
    // different message as shown in the sample runs.
    // Your implementation here...
    int size = strlen(word);
    int *row = (int*) malloc(6 * sizeof(int));
    int *col = (int*) malloc(6 * sizeof(int));
    for ( int i = 0; i < bSize;i++){
        *(row + i) = i;

    }

     for ( int j = 0; j < bSize;j++){
        *(col +j) = j;

    }

    // int row[6]={0,1,2,3,4,5};

    // int col[6]={3,3,3,3,3,3};
    
    printFinal(row,col,size);
      


    // printFinal()
}