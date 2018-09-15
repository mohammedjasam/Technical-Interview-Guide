import sys
'''
	Given a sorted array keys[0.. n-1] of search keys and an array freq[0.. n-1] of frequency counts, where freq[i] is the 
	number of searches to keys[i]. Construct a binary search tree of all keys such that the total cost of all the searches 
	is as small as possible.
'''

def optimal_bst(keys, frequency, height, i, j):
	'''Calculate the cost of optimal bst using recursion'''
	# If there is no element left
	if i == j:
		return 0

	# When only one element is present
	if i == j-1:
		return frequency[i]

	else:
		fsum = sum(frequency[i:j])
		min_cost = sys.maxint
		for index in range(i, j):
			cost = optimal_bst(keys, frequency, height+1, i, index) + \
												optimal_bst(keys, frequency, height+1, index+1, j)

			if cost < min_cost:
				min_cost = cost 

		return min_cost + fsum

def optimal_bst_dynamic(keys, frequency):
	'''Calculate the cost of optimal bst using dynamic programming'''
	length = len(keys)

	soln = [[sys.maxint]*length for i in range(length)]

	for i in range(length):
		soln[i][i] = frequency[i]

	# Length of subsequence will be from 2 to length
	for L in range(2, length+1):
		# Finding all possible subsequence of length L
		for i in range(length-L+1):
			j = L + i - 1
			soln[i][j] = sys.maxint
			# Select the root at an index r between i, j 
			for r in range(i, j+1):
				left_tree = soln[i][r-1] if r > i else 0
				right_tree = soln[r+1][j] if r < j else 0
				cost =  left_tree + right_tree + sum(frequency[i:j+1])

				if cost < soln[i][j]:
					soln[i][j] = cost
				
	return soln[0][length-1]

import unittest

class MyTest(unittest.TestCase):
	def setUp(self):
		self.keys = [10, 12, 20]
		self.frequency = [34, 8, 50]
	
	def test_maximum_sum_recursive(self):
		self.assertEqual(optimal_bst(self.keys, self.frequency, 1, 0, len(self.keys)), 142)

	def test_maximum_sum_dynamic(self):
		self.assertEqual(optimal_bst_dynamic(self.keys, self.frequency), 142)

if __name__ == "__main__":
	unittest.main()
