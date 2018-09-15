# coding: UTF-8

'''
	Binary Search is a searching algorithm that is very efficient and most commonly used techniques used in solving problems. 

	Binary search divides the problem into half at each iteration. It works on a sorted set, and the number of iterations can
	always be reduced on the basis of value that is being searched. 

	Complexity: O(log n)


'''

def binary_search(low, high, key, array):
	''' Search for the key and return the index of the key.
		If not found, returns -1'''
	while(low <= high):
		mid = (low + high) / 2

		if array[mid] == key:
			return mid

		elif array[mid] > key:
			low = mid + 1

		elif array[mid] < key:
			high = mid - 1


	return -1
