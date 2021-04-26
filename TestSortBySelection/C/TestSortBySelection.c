//TestSortBySelection.c
//19/02/2021
#include <stdio.h>

void swap(double *xp, double *yp) 
{ 
    double temp = *xp; 
    *xp = *yp; 
    *yp = temp; 
}; 

//int sortBySelection(double array[], int sizeArray)
//Description: Return the input array sorted from low to high values 	
void sortBySelection(double array[], int sizeArray){
	int i, j, minIndex;
	
	for(i = 0; i < sizeArray - 1; i++){
		
		minIndex = i;
		for(j = i+1; j < sizeArray; j++){
			if (array[j] < array[minIndex]) 
				minIndex = j;
		}		
		swap(&array[minIndex], &array[i]);
	}	
};
	
// TEST
int main(){
	double array[5] = {5, 3, 6, 2, 10};
	int sizeArray = sizeof(array)/sizeof(double);
	
	/*Sort the array*/
	sortBySelection(array, sizeArray);
	
	/*Plot sorted array*/
	for(int i = 0; i < sizeArray; i++)
		printf("%f ", array[i]);
	
	return 0;
}	
