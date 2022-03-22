#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Declarations of the two functions you will implement
// Feel free to declare any helper functions or global variables
void printPuzzle(char **arr);
void searchPuzzle(char **arr, char *word);

int bSize;
int k = 1;

int path ;

// Main function, DO NOT MODIFY
int main(int argc, char **argv)
{
    if (argc != 2)
    {
        fprintf(stderr, "Usage: %s <puzzle file name>\n", argv[0]);
        return 2;
    }
    int i, j;
    FILE *fptr;

    // Open file for reading puzzle
    fptr = fopen(argv[1], "r");
    if (fptr == NULL)
    {
        printf("Cannot Open Puzzle File!\n");
        return 0;
    }

    // Read the size of the puzzle block
    fscanf(fptr, "%d\n", &bSize);

    // Allocate space for the puzzle block and the word to be searched
    char **block = (char **)malloc(bSize * sizeof(char *));
    char *word = (char *)malloc(20 * sizeof(char));

    // Read puzzle block into 2D arrays
    for (i = 0; i < bSize; i++)
    {
        *(block + i) = (char *)malloc(bSize * sizeof(char));
        for (j = 0; j < bSize - 1; ++j)
        { // remeber -1
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

void printPuzzle(char **arr)
{
    // This function will print out the complete puzzle grid (arr). It
    //must produce the output in the SAME format as the samples in the instructions.

    for (int i = 0; i < bSize; i++)
    { //<
        for (int j = 0; j < bSize; j++)
        {
            printf("%c ", *(*(arr + i) + j));
        }
        printf("\n");
    }
}
//used to clear the array when trying  a new path
int mod(int **newArr)
{
    for (int i = 0; i < bSize; i++)
    {
        for (int j = 0; j < bSize; j++)
        {
            *(*(newArr + i) + j) = 0;
        }
        printf("\n");
    }
}
//prints final path 
void finalcall(int **newArr)
{
   
    for (int i = 0; i < bSize; i++)
    {
        for (int j = 0; j < bSize; j++)
        {
            printf("%d\t ", (*(*(newArr + i) + j)));
        }
        printf("\n");
    }
}

int next_func(char **arr, char *word, int **newArr, int previ, int prevj)
{
   
    char *next = word + 1;//points to the next word in the string

    if (*next == NULL)//if the next word does not exist
    {
        //if the length of the path is shorter than the length of the word doesnt exist.
        
        if (path < strlen(word))
        {
            printf("\nWord Not found!\n");
        }
        else//else found word
        {
            printf("\nWord found!\n");
            finalcall(newArr);
        }

        return 1;
    }

    else
    {
        
        for (int i = 0; i < bSize; i++) //iterate
        {
            for (int j = 0; j < bSize; j++)
            {
                

                if (*next == *(*(arr + i) + j))
                {
                    
                    //SAME ROW
                    if (i == previ)
                    {
                        //printf("same row \n");
                        if (j == prevj + 1)
                        {
                            //printf("same-right \n");
                            path++;
                            // *(*(newArr + i) + j) = path;
                            if (path > 0)//if path is taken by a non zero number the route is already in progress and we have to over lap.
                            {
                                (*(*(newArr + i) + j)) = (*(*(newArr + i) + j) * 10) + (path);// overlap equation
                            }
                            else
                            {
                                (*(*(newArr + i) + j)) = (*(*(newArr + i) + j) * 10) + path;
                                printf("path = %d \n", path);
                                *(*(newArr + i) + j) = path;
                            }
                            //path++;

                            return next_func(arr, next, newArr, i, j);// recursion
                        }
                        if (j == prevj - 1)
                        {
                            //printf("same-left \n");
                            path++;
                            // *(*(newArr + i) + j) = path;
                            if (path > 0)
                            {
                                (*(*(newArr + i) + j)) = (*(*(newArr + i) + j) * 10) + (path);
                            }
                            else
                            {
                                (*(*(newArr + i) + j)) = (*(*(newArr + i) + j) * 10) + path;
                                printf("path = %d \n", path);
                                *(*(newArr + i) + j) = path;
                            }
                            //path++;

                            return next_func(arr, next, newArr, i, j);
                        }
                    }

                    //ABOVE
                    if (i == previ - 1)
                    {
                        //printf("up \n");
                        if (j == prevj)
                        {
                            //printf("directly up\n");
                            path++;
                            // *(*(newArr + i) + j) = path;
                            if (path > 0)
                            {
                                (*(*(newArr + i) + j)) = (*(*(newArr + i) + j) * 10) + (path);
                            }
                            else
                            {
                                (*(*(newArr + i) + j)) = (*(*(newArr + i) + j) * 10) + path;
                                printf("path = %d \n", path);
                                *(*(newArr + i) + j) = path;
                            }
                            //path++;

                            return next_func(arr, next, newArr, i, j);
                        }
                        if (j == prevj + 1)
                        {
                            //printf("up-right \n");
                            path++;
                            // *(*(newArr + i) + j) = path;
                            if (path > 0)
                            {
                                (*(*(newArr + i) + j)) = (*(*(newArr + i) + j) * 10) + (path);
                            }
                            else
                            {

                                (*(*(newArr + i) + j)) = (*(*(newArr + i) + j) * 10) + path;
                                printf("path = %d \n", path);
                                *(*(newArr + i) + j) = path;
                            }
                            //path++;
                            return next_func(arr, next, newArr, i, j);
                        }
                        if (j == prevj - 1 && bSize > 5)
                        {
                            //printf("up-left \n");
                            //return next_func(arr, next, i, j);
                            path++;
                            // *(*(newArr + i) + j) = path;
                            if (path > 0)
                            {
                                (*(*(newArr + i) + j)) = (*(*(newArr + i) + j) * 10) + (path);
                            }
                            else
                            {
                                (*(*(newArr + i) + j)) = (*(*(newArr + i) + j) * 10) + path;
                                printf("path = %d \n", path);
                                *(*(newArr + i) + j) = path;
                            }
                            //path++;

                            return next_func(arr, next, newArr, i, j);
                        }
                    }

                    //DOWN
                    if (i == previ + 1)
                    {
                        //printf("down \n");
                        if (j == prevj)
                        {
                            //printf("directly down \n");
                            path++;
                            // *(*(newArr + i) + j) = path;
                            if (path > 0)
                            {
                                (*(*(newArr + i) + j)) = (*(*(newArr + i) + j) * 10) + (path);
                            }
                            else
                            {
                                (*(*(newArr + i) + j)) = (*(*(newArr + i) + j) * 10) + path;
                                printf("path = %d \n", path);
                                *(*(newArr + i) + j) = path;
                            }
                            //path++;

                            return next_func(arr, next, newArr, i, j);
                        }
                        if (j == prevj + 1)
                        {
                            //printf("down-right \n");
                            path++;
                            // *(*(newArr + i) + j) = path;
                            if (path > 0)
                            {
                                (*(*(newArr + i) + j)) = (*(*(newArr + i) + j) * 10) + (path);
                            }
                            else
                            {
                                (*(*(newArr + i) + j)) = (*(*(newArr + i) + j) * 10) + path;
                                printf("path = %d \n", path);
                                *(*(newArr + i) + j) = path;
                            }
                            //path++;

                            return next_func(arr, next, newArr, i, j);
                        }
                        if (j == prevj - 1)
                        {
                            //printf("down-left \n");
                            path++;

                            if (path > 0)
                            {
                                (*(*(newArr + i) + j)) = (*(*(newArr + i) + j) * 10) + (path);
                            }
                            else
                            {
                                (*(*(newArr + i) + j)) = (*(*(newArr + i) + j) * 10) + path;
                                printf("path = %d \n", path);
                                *(*(newArr + i) + j) = path;
                            }
                            //path++;

                            return next_func(arr, next, newArr, i, j);
                        }
                    }
                }
            }
        }
        //printf("word not found\n");
    }
    return 0;
}

void searchPuzzle(char **arr, char *word)
{
    //Convert lowercase letters into upper case
    for (int i = 0; *(word + i) != '\0'; i++)
    {
        if (*(word + i) >= 'a' && *(word + i) <= 'z')
        {
            *(word + i) = *(word + i) - 32;
        }
    }

    //CREATING NEW ARRAY TO STORE OUR NEW ARRAY WITH THE PATH
    int **newArr = (int **)malloc(bSize * sizeof(int *));

    //INITIALIZE THE NEW ARRAY WITH 0 FOR EACH ELEMENT

    for (int i = 0; i < bSize; i++)
    {
        *(newArr + i) = (int *)malloc(bSize * sizeof(int *));
        for (int j = 0; j < bSize; j++)
        {
            *(*(newArr + i) + j) = 0;
        }
    }

    //measures the length of the word we are looking for
    int wordCount = 0;
    for (int i = 0; *(word + i) != '\0'; i++)
    {
        wordCount++;
    } //+1
    int first;
    for (int i = 0; i < bSize; i++)
    { //goes through the rows of the word search puzzle
        mod(newArr);
        path = 0;
        for (int j = 0; j < bSize; j++)
        { //goes through the collums of the word search puzzle

            // *(word) points to the first character of our string
            if (*(word) == *(*(arr + i) + j))
            {
                path++;
                first=1;
                //path = 1;
                *(*(newArr + i) + j) = path;
                // if ((*(*(newArr + i) + j)) > 0)
                // {
                //     (*(*(newArr + i) + j)) = (*(*(newArr + i) + j) * 10) + i;
                // }
                next_func(arr, word, newArr, i, j);
            }
        }
    }
    
    if (first !=1 )
    {
        printf("Word Not Found!\n");
    }
}