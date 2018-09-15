# -*- coding: UTF-8 -*-

# Find out the majority element in the array using Moore's algorithm

# A majority element in an array A[] of size n is an element that appears more than n/2 times (and hence there is at most one such element).

def majority_element(ar):

	count = 1
	maj_index = 0

	for i in range(len(ar)):
		if count == 0:
			maj_index = i
			count = 1
		if ar[i] == ar[maj_index]:
			count += 1
		else:
			count -= 1

	return ar[maj_index]

print majority_element([2, 2, 3, 5, 2, 2, 6])