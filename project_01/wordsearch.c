#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// Declarations of the two functions you will implement
// Feel free to declare any helper functions or global variables
void printPuzzle(char **arr);
void searchPuzzle(char **arr, char *word);
int bSize;
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
        {
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
    // This function will print out the complete puzzle grid (arr).
    // It must produce the output in the SAME format as the samples
    // in the instructions.
    // Your implementation here...
    for (int i = 0; i < bSize; i++) //accessing rows with i
    {
        for (int j = 0; j < bSize; j++) //accessing columns with j
        {
            printf("%c ", *(*(arr + i) + j)); // array2D
        }
        printf("\n");
    }
}

int next_func(int *row, int *col, char **arr, char *word, int previ, int prevj, int count)
{
    char *next = word + 1;
    printf(" %d %c", count, *next);
    if (*next == NULL)
    {
        printf("word is found! \n");
        return -1;
    }

    else
    {
        printf("Looking for: %c \n", *next);

        for (int i = 0; i < bSize; i++)
        {
            (*(row + i)) = i;
            for (int j = 0; j < bSize; j++)
            {
                if (*next == *(*(arr + i) + j))
                {
                    //printf("Found %c at [%d, %d]\n", *next, i, j);
                    //SAME ROW
                    if (i == previ)
                    {
                        *(row + i) = i;

                        //printf("same row \n");
                        if (j == prevj + 1)
                        {
                            printf("same-right \n");
                            printf("saved{%d,%d}\n", i, j);

                            int ff = next_func(row, col, arr, next, i, j, count + 1);
                            if (ff == -1)
                            {

                                *(col + count) = j;
                            }
                            else
                            {
                            return next_func(row, col, arr, next, i, j, count + 1);
                            }
                            
                            // return next_func(row, col, arr, next, i, j, count + 1);
                        }

                        else if (j == prevj - 1)
                        {
                            printf("same-left \n");
                        }
                    }

                    //ABOVE
                    else if (i == previ - 1)
                    {
                        *(row + i) = i;

                        //printf("up \n");
                        if (j == prevj)
                        {
                            printf("directly up\n");
                            *(col + count) = j;
                            printf("saved{%d,%d}\n", i, j);

                            return next_func(row, col, arr, next, i, j, count + 1);
                        }
                        else if (j == prevj + 1)
                        {

                            printf("up-right \n");
                        }
                        else if (j == prevj - 1)
                        {

                            printf("up-left \n");
                        }
                    }

                    //DOWN
                    else if (i == previ + 1)
                    {
                        *(row + i) = i;

                        //printf("down \n");
                        if (j == prevj)
                        {
                            printf("directly down \n");
                        }
                        else if (j == prevj + 1)
                        {
                            printf("down-right \n");
                            *(col + count) = j;
                            printf("saved{%d,%d}\n", i, j);

                            return next_func(row, col, arr, next, i, j, count + 1);
                        }
                        else if (j == prevj - 1)
                        {
                            printf("down-left \n");
                        }
                    }
                }
            }
        }
    }
    // printf("word is not found \n");
    return 0;
}

void printFinal(int *row, int *col)
{
    int **store = (int **)malloc(bSize * sizeof(int *));

    int hr = 0, hc = 0;
    int count = 1;
    int j = 0;
    for (int i = 0; i < bSize; i++)
    {
        *(store + i) = (int *)malloc(bSize * sizeof(int *));
        hr = *(row + i);
        hc = *(col + i);
        // if (*(*(store + hr) + hc) > 0)
        // {
        //     printf("(%d)", (*(*(store + hr) + hc) * 10) + count);
        //     *(*(store + hr) + hc) = (*(*(store + hr) + hc) * 10) + count;
        //     count++;
        // }

        *(*(store + hr) + hc) = count;
        count++;

        if (count > bSize)
        {
            break;
        }
        j++;
        // }
        // else {
        // (*(*(store + i) + j)) =0;
        // }
    }

    for (int i = 0; i < bSize; i++)
    {
        // *(store + i) = (int*)malloc(bSize* sizeof(int*));

        for (int j = 0; j < bSize; j++)
        {
            if ((*(*(store + i) + j)) > bSize)
            {
                (*(*(store + i) + j)) = 0;
            }
        }
    }
    // print

    for (int i = 0; i < bSize; i++) //accessing rows with i
    {
        for (int j = 0; j < bSize; j++) //accessing columns with j
        {
            printf(" %d ", *(*(store + i) + j)); // array2D
        }
        printf("\n");
    }
}

void searchPuzzle(char **arr, char *word)
{
    // This function checks if arr contains the search word. If the
    // word appears in arr, it will print out a message and the path
    // as shown in the sample runs. If not found, it will print a
    // different message as shown in the sample runs.
    // Your implementation here...

    //Convert lowercase letters into upper case

    int *row = (int *)malloc(bSize * sizeof(int));
    int *col = (int *)malloc(bSize * sizeof(int));

    for (int i = 0; *(word + i) != '\0'; i++)
    {
        if (*(word + i) >= 'a' && *(word + i) <= 'z')
        {
            *(word + i) = *(word + i) - 32;
        }
    }

    for (int i = 0; i < bSize; i++)
    {
        for (int j = 0; j < bSize; j++)
        {
            if (*word == *(*(arr + i) + j))
            {
                *(row + 0) = i;
                *(col + 0) = j;
                printf("\nFound %c at [%d, %d] \n", *word, i, j);
                // char *next = word + 1;
                // *(row+0)=i;
                // *(col+0)=j;

                int end = next_func(row, col, arr, word, i, j, 1);
                //printf("%c found at [%d, %d] \n", *next, i, j);

                printFinal(row, col);
            }
        }
    }
}
