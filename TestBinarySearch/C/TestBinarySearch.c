//TestBinarySearch.c
//23/02/2021
#include <stdio.h>
#include <math.h>

double BinarySearch(double list[], int listSize, double element){
	
	int medium = 0;
	int minor = 0;
	int mayor = listSize - 1;
	double estimated = 0;
	
	while(minor <= mayor){
		medium = minor + (mayor - minor)/2;
		estimated = list[medium];
		if(estimated == element){
			return medium;
		}
		if(estimated < element){
			minor = medium + 1;
		}
		else{
			mayor = medium - 1;
		}	
	}
		return -1;
};

int main(){
	
	double list[5] = {1, 3, 5, 7, 9};
	double pos;
	double element = 9;
	pos = BinarySearch(list, sizeof(list)/sizeof(double),  element);
	printf("Element is in position %f", pos);
	
	return 0;
}
