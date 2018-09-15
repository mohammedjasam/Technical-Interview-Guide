# -*- coding: UTF-8 -*-

'''
	Magic Index
	
	A magic index in an array A[0 ... n-1] is defined to be an index such that A[i] = i. Given a sorted array of
	distict integers, write a method to find a magic index, if one exists, in array A.
'''

def magic_index(array, start, end):

	if start > end:
		return -1

	mid = (start+end) / 2

	if array[mid] == mid:
		return mid

	if array[mid] > mid:
		return magic_index(array, start, mid-1)

	else:
		return magic_index(array, mid+1, end)

array = [-40, -20, -1, 1, 2, 3, 5, 7, 9, 12, 13]
print magic_index(array, 0, len(array)-1)

'''
	If the array does not contain distinct numbers
'''

def magic_index_2(array, start, end):

	if start > end:
		return -1

	mid = (start+end) / 2

	if array[mid] == mid:
		return mid

	if array[mid] > mid:
		index = min(array[mid], mid-1)
		return magic_index(array, start, index)

	else:
		index = max(array[mid], mid+1)
		return magic_index(array, index, end)


array = [-10, -5, 2, 2, 2, 3, 4, 7, 9, 12, 13]
print magic_index_2(array, 0, len(array)-1)
