//TestRecursiveSum.c
//23/03/2021
#include <stdio.h>
#include <math.h>

double recursiveSum(double array[], int arraySize){
	
	if(arraySize < 0){
		return 0;
	}
	else{
		return array[arraySize] + recursiveSum( array, arraySize-1);
	}	
};

int main(){
	
	double array[5] = {1, 3, 5, 7, 9};
	double result = 0;
	result = recursiveSum(array, sizeof(array)/sizeof(double));
	printf("The sum of array is %f", result);
	
	return 0;
}
