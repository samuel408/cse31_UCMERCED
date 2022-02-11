 #include <stdio.h> 
 
 int main() { 
  int x, y, *px, *py; 
  int arr[10] =0;
  x=0,y=0;
  printf("Values of X is %d, Y is %d and arr is %d \n", x, y, *arr);

printf("Address of x: %p\n", &x);// displays address of x
printf("Address of y: %p\n", &y);//displays address of y
printf("\n");

px = &x; //px -> memory address of x
py = &y; //py -> memory address of y

printf("Address of pointer x: %p\n", (void *)px);//(void* ) is a void pointer and it can hold the adress of of any data type
printf("Value stored at address of pointer x: %d\n", *px);
printf("\n");

printf("Address of pointer y: %p\n", (void *)py);
printf("Value stored at address of pointer y: %d\n", *py);
printf("\n");


printf("Address of arr: %p\n", arr);
printf("Address of arr[0]: %p\n\n", &arr[0]);  


int *pi = 0;//pointer of i
int i = 0;
while(i < (sizeof(arr)/sizeof(*arr))){                      
    pi = arr+i;
    printf("Value stored at element %d is: %d\n", i, *pi);
    printf("Address of element %d is: %p\n\n", i, (void *)pi);
    i++;
}

 
  return 0; 
 } 