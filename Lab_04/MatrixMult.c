
#include <stdio.h>
// #include <malloc.h>

int** matMult(int **a, int **b, int size) {
	// (4) Implement your matrix multiplication here. You will need to create a new matrix to store the product.
	 //dynamucally allocates memory for the product of both arrays.
	int **matC = (int**)malloc(size * sizeof(int*));

	for(int i = 0; i < size; i++){
		*(matC + i) = (int*)malloc(size * sizeof(int));
		for(int j = 0; j < size; j++){
			*(*(matC + i )+ j) = 0;
			for(int k = 0; k < size; k++){
				// cross multiplies the 2 matrices
				*(*(matC + i) + j) = *(*(a + i) + k) * (*(*(b + k) + j)); 
			}
		}
	}
}

void printArray(int **arr, int n) {
	// (2) Implement your printArray function here

// array double pointer gets on the values of arr
int **matD = arr; 

// iterates the rows
for(int i = 0; i < n; i++){ 
	// iterates the coloumns.
	for(int j = 0; j < n; j++){ 

	printf("%d ", *(*(matD+i)+j));


}
}
}

int main() {
	int n = 0;
	int **matA, **matB, **matC;
	// (1) Define 2 (n x n) arrays (matrices). 



	matA = (int**)malloc(n * sizeof(int*));
	matB = (int**)malloc(n * sizeof(int*));
	matC = (int**)malloc(n * sizeof(int*));


for(int i = 0; i < n; i++){
	*(matA + i) = (int*)malloc(n * sizeof(int));
	for(int j = 0; j < n; j++){
		*(*(matA + i)+j) = 2;
	}
}


for(int i = 0; i < n; i++){
	*(matB + i) = (int*)malloc(n * sizeof(int));
	for( int j= 0; j < n; j++){
		*(*(matB + i)+j) = 6;
	}
}


for(int i = 0; i < n; i++){
	*(matC + i) = (int*)malloc(n * sizeof(int));
	for(int j= 0; j < n; j++){
		*(*(matC + i)+j) = 1;
	}
}

	// (3) Call printArray to print out the 2 arrays here.
	printf("Array 1:");
	printArray(matA, n);
	printf("Array 2:");
	printArray(matB, n);
	
	// (5) Call matMult to multiply the 2 arrays here.
	matC = matMult(matA, matB, n);

	
	// (6) Call printArray to print out resulting array here.
	printf("Array 3: \n");
	printArray(matC, n);

    return 0;
}