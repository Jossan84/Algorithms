#TestBinarySearch
#19/02/2021

#binarySearch(list, element)
#Description: The function return the position for a element of a list.
def binarySearch(list, element):
	minor = 0
	mayor = len(list) - 1
	
	while minor <= mayor:
		medium = round((minor + mayor)/2)
		estimated = list[medium]
		if estimated == element:
			return medium
		if estimated > element:
			mayor = medium
		else:
			minor = medium + 1
	return "Not found"

#TEST	
myList = [1, 3, 5, 7, 9]
print(binarySearch(myList, 9))
# print(binarySearch(myList, -1)) # The function brokes searching negative numbers
	