# -*- coding: UTF-8 -*- 

'''

	Problem: An image is represented by N*N matrix, where each pixel is four bytes. Write a method to rotate matrix by 90 degrees.

	example:
		1   2   3   4                               13  9   5  1
		5   6   7   8                 --->          14  10  6  2
		9   10  11  12                              15  11  7  3
		13  14  15  16                              16  12  8  4

'''

'''
	Approach 1: By taking an additional 2-D matrix and copying the elements from original matrix

	Complexity: O(n * 2) Space Complexity: O(n * 2)
'''
def rotate_90(matrix):
	
	N = len(matrix)

	new_matrix = [] * N

	for i in range(N):
		new_matrix.append([0]*N)

	for i in range(N):
		for j in range(N):
			new_matrix[j][N-i-1] = matrix[i][j]

	return new_matrix

'''
	Approach 2: Rotating the matrix by in-place changing the values of the original matrix

	Complexity: O(n * 2)
'''

# TODO : Implementation


# Writing unit-test for the above function
import unittest

class MyTest(unittest.TestCase):

	def test(self):
		self.assertEqual(rotate_90([[1, 2, 3, 4], [5, 6, 7, 8], [9, 10, 11, 12], [13, 14, 15, 16]]), [[13, 9, 5, 1], [14, 10, 6, 2], [15, 11, 7, 3], [16, 12, 8, 4]])

unittest.main()
