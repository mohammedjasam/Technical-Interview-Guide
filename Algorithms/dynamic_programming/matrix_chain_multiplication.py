# -*- coding: UTF-8 -*-

# Matrix chain multiplication

'''
	Given a sequence of matrices, find the most efficient way to multiply these matrices together. The problem is not 
	actually to perform the multiplications, but merely to decide in which order to perform the multiplications.

	Example:
			Input: p[] = {40, 20, 30, 10, 30}
  			Output: 26000

			There are 4 matrices of dimensions 40x20, 20x30, 30x10 and 10x30. Let the input 4 matrices be A, B, C and D.
			The minimum number of multiplications are obtained by putting parenthesis in following way (A(BC))D -->
			20*30*10 + 40*20*10 + 40*10*30
'''
import sys

def matrix_multiplication(array):
	'''Recursive implementation to find the minimum cost of matrix multiplication'''
	min_cost = sys.maxint

	if len(array) < 3:
		return 0

	for i in range(1, len(array)-1):
		cost =  (array[i-1] * array[i] * array[i+1]) + matrix_multiplication((array[:i] + array[i+1:]))
		if cost < min_cost:
			min_cost = cost

	return min_cost

def matrix_multiplication_2(arr, i, j):
	'''Recursive implementation by passing indexes in the argument'''

	if i == j:
		return 0

	min_count = sys.maxint
	for k in range(i, j):
		count = matrix_multiplication_2(arr, i, k) + matrix_multiplication_2(arr, k+1, j) + arr[i-1]*arr[k]*arr[j]

		if count < min_count:
			min_count = count

	return min_count

def matrix_dynamic(arr):
	'''Minimum count of matrix multiplication using dynamic implementation'''
	n = len(arr)

	# Initialize n * n matrix with None
	mat = [[0] * n for i in range(n)]

	# Considering all the possible chain lengths
	for L in range(2, n):
		for i in range(n-L+1):
			j = i+L-1
			# Cost would be zero when multiplying one matrix
			if i == j:
				matrix[i][j] = 0
			else:
				mat[i][j] = sys.maxint
				for k in range(i, j):
					res = mat[i][k] + mat[k+1][j] + arr[i-1] * arr[k] * arr[j]

					if res < mat[i][j]:
						mat[i][j] = res

	return mat[1][n-1]

import unittest

class MyTest(unittest.TestCase):
	def setUp(self):
		self.array = [40, 20, 30, 10, 30]

	def test_recursive_matrix_multiplication(self):
		self.assertEqual(matrix_multiplication(self.array), 26000)

	def test_recursive_matrix_multiplication_2(self):
		self.assertEqual(matrix_multiplication_2(self.array, 1, len(self.array)-1), 26000)

	def test_matrix_dynamic(self):
		self.assertEqual(matrix_dynamic(self.array), 26000)

if __name__ == "__main__":
	unittest.main()
