# -*- coding: UTF-8 -*-

# Cutting a rod

'''
	Given a rod of length n inches and an array of prices that contains prices of all pieces of size smaller than n.
	Determine the maximum value obtainable by cutting up the rod and selling the pieces.
'''
import sys

def cutting_a_rod(length, values):
	'''Recursive implementation to find the maximum values obtained by cutting a rod'''
	# If length is less than or equal to 0
	if length <= 0:
		return 0

	else:
		max_val = -sys.maxint
		for i in range(length):
			# Cut the rod at different lengths
			# length-i-1 because at index 0, length is 1
			max_val = max(values[i] + cutting_a_rod(length-i-1, values), max_val)

	return max_val


def cutting_a_rod_dynamic(values, length):
	'''Dynamic Programming implementation to find the maximum values obtained by cutting a rod'''
	soln = [0] * (length+1)

	for i in range(1, length+1):
		soln[i] = -sys.maxint
		for j in range(i):
			res = soln[i-j-1] + values[j]
			if res > soln[i]:
				soln[i] = res

	return soln[length]

def cutting_a_rod_recursive(length, values, index):
	if length <= 0 or index < 0:
		return 0

	if length == 1:
		return values[0]

	else:
		included = cutting_a_rod_recursive(length-index-1, values, index) + values[index]
		not_included = cutting_a_rod_recursive(length, values, index-1)

		return max(included, not_included)

import unittest

class MyTest(unittest.TestCase):
	def setUp(self):
		self.price = [1, 5, 8, 9]
		self.length = len(self.price)

	def test_cutting_a_rod(self):
		self.assertEqual(cutting_a_rod(self.length, self.price), 10)

	def test_cutting_a_rod_dynamic(self):
		self.assertEqual(cutting_a_rod_dynamic(self.price, self.length), 10)

	def test_cut_a_rod_recursive(self):
		self.assertEqual(cutting_a_rod_recursive(self.length, self.price, self.length-1), 10)


if __name__ == "__main__":
	unittest.main()
