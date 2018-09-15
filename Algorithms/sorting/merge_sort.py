# coding: UTF-8

'''
	Merge sort

	Merge sort is a divide-and-conquer algorithm based on the idea of breaking down a list into several sub-lists until each 
	sublist consists of a single element and merging those sublists in a manner that results into a sorted list.


	Time Complexity: O(N * logN)
'''

def merge(a, b):
	''' Merge the two arrays in sorted order'''
	p = 0 
	q = 0

	new_array = []
	# newlist.append is a function reference that is reevaluated each time through the loop
	# Hence, storing it in a variable is a better idea
	append = new_array.append
	
	while (p < len(a) and q < len(b)):
		if a[p] < b[q]:
			append(a[p])
			p += 1

		else:
			append(b[q])
			q += 1

	while (q < len(b)):
		append(b[q])
		q += 1

	while(p  < len(a)):
		append(a[p])
		p += 1

	return new_array

def merge_sort(array):
	length = len(array)
	
	if length == 1:
		return array

	mid = length / 2
	a = array[:mid]
	b = array[mid:]

	# Call recursion on the remaining elements
	l1 = merge_sort(a)
	l2 = merge_sort(b)

	# Merge the two arrays
	return merge(l1, l2)

a = [12, 11, 13, 5, 6, 7, 3, 55, 21, 77, 4]
a = merge_sort(a)
print a
