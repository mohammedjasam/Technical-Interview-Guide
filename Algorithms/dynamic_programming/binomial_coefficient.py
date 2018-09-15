# -*- coding: UTF-8 -*-

# Binomial Coefficient (Dynammic Programming)


def binomial_coefficient(n, k):
	'''Calculating bionomial coefficient using recursion'''
	if k == 0 or k == n:
		return 1

	return binomial_coefficient(n-1, k-1) + binomial_coefficient(n-1, k)


def binomial_coefficient_dynamic(n, k):
	'''Calculating bionomial coefficient using Dynammic Programming'''
	soln = []
	for i in range(n+1):
		soln.append([0]*(k+1))

	for i in range(n+1):
		for j in range(k+1):

			if j == 0 or j == n:
				soln[i][j] = 1

			else:
				soln[i][j] = soln[i-1][j-1] + soln[i-1][j]

	return soln[n][k]

import unittest

class MyTest(unittest.TestCase):
	def setUp(self):
		self.n = 5
		self.k = 2

	def test_maximum_sum_recursive(self):
		self.assertEqual(binomial_coefficient(self.n, self.k), 10)

	def test_maximum_sum_dynamic(self):
		self.assertEqual(binomial_coefficient_dynamic(self.n, self.k), 10)

if __name__ == "__main__":
	unittest.main()
