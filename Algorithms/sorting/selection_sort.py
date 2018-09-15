# coding: UTF-8

'''
	Selection sort

	The Selection sort algorithm is based on the idea of finding the minimum or maximum element in an unsorted array 
	and then putting it in its correct position in a sorted array.

	Complexity: O(n*n)
'''

def selection_sort(array):
	''' Sort a list using selection sort algorithm'''
	for i, _ in enumerate(array):
		# Initialize smallest element and index
		index = i
		for j in range(i, len(array)):
			if array[j] < array[index]:
				index = j
		
		if index != i:
			array[i], array[index] = array[index], array[i]

	return array
