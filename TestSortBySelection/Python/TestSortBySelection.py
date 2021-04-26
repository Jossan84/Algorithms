#TestSortBySelection.py
#19/02/2021

# findMin(array)
# Description: Find the index for the array position with less value
def findMin(array):
	minor = array[0]
	minIndex = 0
	for i in range(1, len(array)):
		if array[i] < minor:
			minor = array[i]
			minIndex = i
	return minIndex

# sortBySelection(array)
# Description: Return the input array sorted from low to high values 	
def sortBySelection(array):
	sortedArray = []
	for i in range(len(array)):
		minIndex = findMin(array)
		sortedArray.append(array.pop(minIndex))
	return sortedArray

# TEST
sortedArray = sortBySelection([5, 3, 6, 2, 10])
print(sortedArray)		
	
