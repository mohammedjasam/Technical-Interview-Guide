# -*- coding: UTF-8 -*-

# Minimum number of jumps to reach end

import sys
def minimum_step(steps_array, index, length):
	'''Calculating the minimum number of steps to reach the top of stairs using recursion'''
	if index == length-1:
		return 0

	if steps_array[index] == 0:
		return sys.maxint

	else:
		steps = steps_array[index]
		min_steps = sys.maxint
		
		for i in range(index+1, index+steps+1):
			if i < length:
				step = minimum_step(steps_array, i, length)

			if step + 1 < min_steps:
				min_steps = step + 1
				
		return min_steps

# Recursive approach
def min_jump(arr, start, end):
	if start == end:
		return 0

	if arr[start] == 0:
		return sys.maxint

	minimum = sys.maxint
	i = start+1
	while i <= start+arr[start] and  i <= end:
		res = min_jump(arr, i, end)
		if res != sys.maxint and res + 1 < minimum:
			minimum = res + 1

		i+=1

	return minimum

def minimum_step_dynamic(steps_array, length):
	
	if not length or not steps_array[0]:
		return sys.maxint

	soln = [sys.maxint] * length
	soln[0] = 0
	
	for i in range(1, length):
		for j in range(i):
			if i <= steps_array[j] + j and steps_array[j] != sys.maxint:
				soln[i] = min(soln[i], soln[j] + 1)

	return soln[length-1]


# Dynamic Programmic implementation
def min_jump_dynamic(arr):
	n = len(arr)

	if n == 0 or arr[0] == 0:
		return sys.maxint

	soln = [0] * n

	for i in range(1, n):
		soln[i] = sys.maxint
		for j in range(i):
			if i <= j + arr[j] and soln[j] != sys.maxint:
				soln[i] = min(soln[i], soln[j]+1)
				break

	return soln[n-1]

import unittest

class MyTest(unittest.TestCase):
	def setUp(self):
		self.array = [1, 3, 5, 8, 9, 2, 6, 7, 6, 8, 9]
		self.length = len(self.array)
	
	def test_minimum_step_recursive(self):
		self.assertEqual(minimum_step(self.array, 0, self.length), 3)

	def test_minimum_step_dynamic(self):
		self.assertEqual(minimum_step_dynamic(self.array, self.length), 3)

if __name__ == "__main__":
	unittest.main()
