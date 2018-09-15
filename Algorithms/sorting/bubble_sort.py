# coding: UTF-8

'''
	Bubble Sort

	Bubble sort is based on the idea of repeatedly comparing pairs of adjacent elements and then swapping their positions if 
	they exist in the wrong order.

	Complexity: O(n*n)
'''

def bubble_sort(array):

	for i in range(len(array)-1):
		for j in range(i, len(array)):
			if array[i] > array[j]:
				array[i], array[j] = array[j], array[i]

	return array
