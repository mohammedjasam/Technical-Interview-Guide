# -*- coding: UTF-8 -*-

# Program to find the first and last occurence of an element in an array

def find_first(arr, element):

	for i in range(len(arr)):
		if arr[i] == element:
			return i

	return -1

def find_last(arr, element):

	index = -1
	for i in range(len(arr)):
		if arr[i] == element:
			if i+1 < len(arr) and arr[i+1] == element:
				index = i+1
			else:
				index = i
				break

	return index

arr = [1, 2, 3, 3, 3, 3, 4, 5, 5, 5, 6, 7, 7]
print find_first(arr, 3)
print find_last(arr, 7)

