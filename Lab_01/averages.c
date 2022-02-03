 #include <stdio.h> 

     
 int main() 
 { 
    
//    //create an empty array to hold all values.
//    int arr[100];
   //create  an array to hold odd numbers and an even array
   int arrEven[100];
     int arrOdd[100];
     //counters for even and odd numbers to compute average/
     int oddCount = 0, evenCount = 0;

    // keep asking for integers to fill unitl the user responds with 0;
    int response = 1 ;
    //increment counter
    int counter = 1;
    while ( response != 0){
        if (counter == 1){
            printf("Please enter the 1st integer:");
            scanf("%d",&response);
            if(response == 0){
                printf(" There is no average to compute.\n");
                // kill program if there is a 0 entered;
                return 0;
            }
            // arr[0] = response;
            counter++;
        }
        else if (counter == 2){
            printf("Please enter the 2nd integer:");
            scanf("%d", &response);
            // arr[1] = response;
            counter++;


        }
        else if (counter == 3){
            printf("Please enter the 3rd integer:");
            scanf("%d", &response);
            // arr[2] = response;
            counter++;

        }
        else{
            printf("Please enter the %dth integer:",counter);
            scanf("%d", &response);
            // arr[counter] = response;
            counter++;

            

        }
          //determine if odd or not 
       if(response % 2 == 1){

           //add to odd array
           arrOdd[oddCount] = response;
           oddCount++;
           
       }
       else{
           arrEven[evenCount] = response;
           evenCount++;
       }
    }
         int oddSum = 0, evenSum = 0;

    // for loop that adds up numbers
     for(int i = 0;i < oddCount; i++ ){
         oddSum += arrOdd[i];
                //   printf("%d\n",arrOdd[i]);


         
     }       
    //    printf("%d\n",oddSum);

          for(int i = 0;i < evenCount; i++ ){
         evenSum += arrEven[i];
                //   printf("%d\n",arrEven[i]);


         
     }       
    //    printf("%d\n",evenSum);
     double oddAvg = oddSum/oddCount;
     double evenAvg = evenSum/(evenCount -1); //the -1 is to compensate for the 0 that ends program

    //print
    if (evenCount != 0){
        printf("Average of inputs whose digits sum up to an odd number: %d\n",oddAvg );

    }
    if (evenCount != 0){
        printf("Average of inputs whose digits sum up to an odd number: %d\n",evenAvg );
        
    }
       return 0; 
 } 
