#TestRecursiveSum
#23/03/2021

#sum(array)
#Description: The function return the sum of an array
def sum(array):
	result = 0
	for i in array:
		result += i 
	return result

#recursiveSum(array)
#Description: The function return the sum of an array computed recursively
def recursiveSum(array):
	if len(array)==0:
		return 0
	else:
		return array[0] + recursiveSum(array[1:])
	
	
#TEST	
array = [1, 3, 5, 7, 9]
print(sum(array))
print(recursiveSum(array))