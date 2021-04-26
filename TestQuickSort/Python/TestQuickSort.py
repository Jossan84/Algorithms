#TestQuickSort
#24/03/2021

#quickSort(array)
#Description: The function return the input array sorted with quick sort algorithm
def quickSort( array ):
	if len( array ) < 2:
		return array
	else:
		pivot = array[0]
		minors = [i for i in array[1:] if i <= pivot]
		mayors = [i for i in array[1:] if i > pivot]
		return quickSort( minors ) + [pivot] + quickSort( mayors )
	
#TEST	
array = [9, 7, 3, 5, 1]
print(quickSort(array))