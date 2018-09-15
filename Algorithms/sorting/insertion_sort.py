# coding: UTF-8

'''
	Insertion sort

	Insertion sort is based on the idea that one element from the input elements is consumed in each iteration to find 
	its correct position i.e. the position to which it belongs in a sorted array.

	Time complexity: O(n*n)
'''

def insertion_sort(array):

	for i in range(1, len(array)):

		current_value = array[i]
		position = i

		while ( position > 0 and current_value < array[position-1]):
			array[position] = array[position-1]
			position = position-1

		array[position] = current_value

	return array
