# -*- coding: UTF-8 -*-

# Maximum Sum Increasing subsequence

import sys

max_sum = -sys.maxint

# Time complexity: O(2 ^ n) which is the total number of subsequences possible
def maximum_sum_recursive(array, index):
	'''Calculating maximum sum increasing subsequence using recursion'''
	global max_sum

	# IF there is only one element present. 
	if index == 1:
		return array[index-1]

	else:
		max_value = -sys.maxint

		for i in range(1, index):
			res = maximum_sum_recursive(array, i)

			if array[i-1] < array[index-1] and res + array[index-1] > max_value:
				max_value = res + array[index-1]

		if max_value > max_sum:
			max_sum = max_value
	 	

	return max_value

# Time complexity: O(n*n)
def maximum_sum_dynamic(arr):
	'''Calculating maximum sum increasing subsequence using dynamic programming'''
	soln = [-sys.maxint] * len(arr)

	for i in range(len(arr)):
		soln[i] = arr[i]

	for i in range(1, len(arr)):
		for j in range(i):
			if arr[j] < arr[i] and soln[j] + arr[i] > soln[i]:
				soln[i] = soln[j] + arr[i]


	return max(soln)

import unittest

class MyTest(unittest.TestCase):
	def setUp(self):
		self.sequence = [1, 101, 2, 3, 100, 4, 5]
		self.length = len(self.sequence)
	
	def test_maximum_sum_recursive(self):
		maximum_sum_recursive(self.sequence, self.length)
		self.assertEqual(max_sum, 106)

	def test_maximum_sum_dynamic(self):
		self.assertEqual(maximum_sum_dynamic(self.sequence), 106)

if __name__ == "__main__":
	unittest.main()
