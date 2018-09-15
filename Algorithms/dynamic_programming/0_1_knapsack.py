# -*- coding: UTF-8 -*-

# 0-1 Knapsack Problem
'''
	Given weights and values of n items, put these items in a knapsack of capacity W to get the maximum total value in the
	knapsack. In other words, given two integer arrays val[0..n-1] and wt[0..n-1] which represent values and weights
	associated with n items respectively. Also given an integer W which represents knapsack capacity, find out the maximum
	value subset of val[] such that sum of the weights of this subset is smaller than or equal to W.
'''

# recursive solution to solve 0-1 knapsack problem
# Time complexity : O(2^n)
def knapsack_recursion(weights, values, W):
	'''Finding the maximum value for 0-1 knapsack using recursion'''

	# Base case
	if not W or not weights:
		return 0

	# If weight of the 0th item is more than Knapsack capacity W, then this item cannot be included in the optimal solution.
	elif weights[0] > W:
		return knapsack_recursion(weights[1:], values[1:], W)

	else:
		# Return the maximum of two cases:
		# (1) 0th item included
		# (2) 0th item not included
		return max(knapsack_recursion(weights[1:], values[1:], W), knapsack_recursion(weights[1:], values[1:], W-weights[0]) \
			+ values[0])



# time-complexity : O(W*n)
def knapsack_dynamic(values, weights, W):
	'''Dynamic programming implementation of knapsack problem'''
	n = len(weights)

	# Initialize a two matrix where row represents weights array and column represent weight W
	K = [[0]*(W+1) for i in range(n+1)]

	for i in range(n+1):
		for w in range(W+1):
			# Base case
			if not i or not w:
				K[i][w] = 0
			# Check for the two cases:
			# (1) 0th item included
			# (2) 0th item not included
			elif weights[i-1] <= w:
				K[i][w] = max(values[i-1]+K[i-1][w-weights[i-1]], K[i-1][w])
			# If weights[i-1] > w, remove the i-1 element
			else:
				K[i][w] = K[i-1][w]

	return K[n][W]

import unittest

class MyTest(unittest.TestCase):
	def setUp(self):
		self.values = [60, 100, 120]
		self.weights = [10, 20, 30]
		self.W = 50

	def test_knapsack_recursive(self):
		self.assertEqual(knapsack_recursion(self.weights, self.values, self.W), 220)

	def test_knapsack_dynamic(self):
		self.assertEqual(knapsack_dynamic(self.values, self.weights, self.W), 220)

if __name__ == "__main__":
	unittest.main()
