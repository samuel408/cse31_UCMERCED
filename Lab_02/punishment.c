 #include <stdio.h> 

 int main() 
 { 
     int repeatTimes = 0;
     int typoLine ;
     
    //  printf("Enter the number of times to repeat the punishment phrase:");
    //  scanf("%d", &repeatTimes);

    //tracks number of iterations.
    int counter = 0;

     while(repeatTimes < 1){
    if( counter != 0){
        printf("You entered an invalid value for the number of repetitions! \n");
    }
     printf("Enter the number of times to repeat the punishment phrase:");
     scanf("%d", &repeatTimes);

    //iterattion count
     counter++;
     }
     //reset counter
    counter = 0 ;
     // repitition line input

     while(typoLine < 1 || typoLine > repeatTimes){
         if (counter !=0){
             printf("You entered an invalid value for the number of repetitions! \n");
         }
     printf("Enter the repetition line where you want to introduce the typo:");
     // grab input
     scanf("%d", &typoLine);
     
     //iteration 
     counter++;
     }

    //used this to test functionality
    //  printf("%d\n", typoLine);


    for(int i = 1; i < repeatTimes+1 ;i++){
        if(i == typoLine){
            printf("Programming in C is phun!\n");
      }
        else{
        printf("Programming in C is fun!\n");
        }
    }

       return 0; 
 } 
