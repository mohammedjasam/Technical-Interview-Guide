# -*- coding: UTF-8 -*-
'''
	Given the two array of integers, compute the pair of values with the smallest difference. 
	Return the difference. 

	Time complexity: O(AlogA + BlogB)
'''
import sys

def smallest_difference(array1, array2):
	if not array1 or not array2:
		return None
	
	else:
		array1.sort()
		array2.sort()
		length1 = len(array1)
		length2 = len(array2)

		difference = sys.maxint
		a = 0
		b = 0		
		
		while a < length1 and b < length2:
			if abs(array1[a]-array2[b]) < difference:
				difference = abs(array1[a] - array2[b])
				pair = [array1[a], array2[b]]
			
			if array1[a] < array2[b]:
				a += 1
			else:
				b += 1

		
		return pair

print smallest_difference([1, 3, 15, 11, 2], [23, 127, 235, 19, 8])
