# -*- coding: UTF-8 -*-

# Program to search a element in bitonic array

def bitonic_search(arr, low, high):

	if not arr:
		return "List is empty"

	if low == high:
		return arr[high]

	mid = (low + high)/2

	if arr[mid] < arr[mid+1]:
		return bitonic_search(arr, mid+1, high)
	elif arr[mid] < arr[mid-1]:
		return bitonic_search(arr, low, mid-1)
	else:
		return arr[mid]


arr = [3, 4, 5, 7, 8, 13, 56, 44, 32, 9, 1]

print bitonic_search(arr, 0, len(arr)-1)