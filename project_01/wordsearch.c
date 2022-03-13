#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Declarations of the two functions you will implement
// Feel free to declare any helper functions or global variables
void printPuzzle(char** arr);
void searchPuzzle(char** arr, char* word);
int bSize;
void declarePointer(int order, char *arr);
void printPath(char* word, char** arr,int count);
//declare bunch of char pointers
char *ptr0=NULL,*ptr1=NULL,*ptr2=NULL,*ptr3=NULL,*ptr4=NULL,*ptr5=NULL,*ptr6=NULL,*ptr7=NULL,*ptr8=NULL;


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

//declared 
 void declarePointer(int order, char *arr){
    switch(order) {

   case 0  :
      ptr0 = arr;
      break; /* optional */
	
   case 1 :
         ptr1 = arr;

      break; /* optional */
    
    case 2 :
          ptr2 = arr;

      break; /* optional */

    case 3 :
          ptr3 = arr;

      break; /* optional */

    case 4 :
          ptr4 = arr;


      break; /* optional */

    case 5:
          ptr5 = arr;

      break; /* optional */
    
    case 6 :
          ptr6 = arr;

      break; /* optional */
    
    case 7 :
          ptr7 = arr;

      break; /* optional */
    
    case 8 :
          ptr8 = arr;

      break; /* optional */

}

}


void printPuzzle(char** arr) {
	// This function will print out the complete puzzle grid (arr). 
    // It must produce the output in the SAME format as the samples 
    // in the instructions.
    // Your implementation here...


    // int i, j;
    // int size = sizeof(arr);
    // //print a for loop.
    // for(i = 0; i < size; i++){    // using pointer notation to traverse 2d array

    //     for (j = 0; i < size ;j++){
    //         printf("%c", *arr);
    //     }

    // }

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
    //free(size);
}


void printPath(char* word, char** arr,int count){
if( count = 0){//we have reached the end kill program
    return;
}
int wordSize = strlen(word);//checks word size
    // printf("%d",wordSize);
    

         int size = bSize;// size of array rows and columns


    for (int i = 0; i < size; i++) //accessing rows with i
    {
        for (int j = 0; j < size; j++) //accessing columns with j
        {
            if(word[0] == (*(*(arr + i) + j))){//if number is equal print wordsize to label path number;
                printf("0");
            }
            else {
              printf("0");//if number is irrelevant print 0

            }
        }
    }
    count = count -1;
    printPath( word, arr, count);
    return;
    
}

void searchPuzzle(char** arr, char* word) {
    // This function checks if arr contains the search word. If the 
    // word appears in arr, it will print out a message and the path 
    // as shown in the sample runs. If not found, it will print a 
    // different message as shown in the sample runs.
    // Your implementation here...

    //converts all letters to capital letters.

    for (int i = 0; *(word + i) != '\0'; i++)
    {
        if (*(word + i) >= 'a' && *(word + i) <= 'z')
        {
            *(word + i) = *(word + i) - 32;
        }
    }

    //check to see if the word is inside 

    int wordSize = strlen(word);//checks word size
    // printf("%d",wordSize);

     int size = bSize;

     //loop that creates variables based on how many letters there are

    //  for( int i =0; i < wordSize; i++){
    //      char* ptr = NULL;
    //  }
    int count = 0;
    int first =0;

    for (int i = 0; i < size; i++) //accessing rows with i
    {
        for (int j = 0; j < size; j++) //accessing columns with j
        {
            for(int k = 0; k < wordSize;k++){// checks to see if the letter matches.

                if(word[k] == (*(*(arr + i) + j))){
                    count ++;
                    declarePointer(k, (*(*(arr + i) + j)));

                }
                if(word[0] == (*(*(arr + i) + j))){
                    first = 1;
                
                }
            }
        }
    }

    if (first == 1 &&  count >=1){
        printf("Word found!");
    }
    else {
        printf("Word not found!");
        return ;
    }

    printf("\n");
// printf("%x %x %x %x %x ",&ptr0, &ptr1, &ptr2, &ptr3, &ptr4 );

// printing path 
printf("Printing the search path: \n");
    
    printPath(word, arr, wordSize);

    return ;


}
