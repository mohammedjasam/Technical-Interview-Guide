# -*- coding: UTF-8 -*-

# Program to find minimum cost path
import sys

def min_cost_recursive(cost, i, j, m, n):
	'''Recursive solution to find the optimal find to reach the end of the matrix.
	   Starts from cell[0][0] and move toward cell[m-1][n-1]'''

	# If we reach the end cell, return the cost of the cell itself
	if i == m-1 and j == n-1:
		return cost[m-1][n-1]

	else:
		# cost when we move right
		right = min_cost_recursive(cost, i, j+1, m, n) if j+1 <= n-1 else sys.maxint
		# cost when we move down
		down = min_cost_recursive(cost, i+1, j, m, n) if i+1 <= m-1 else sys.maxint
		# cost when we move diagonally downward
		diagonal = min_cost_recursive(cost, i+1, j+1, m, n) if i+1 <= m-1 and j+1 <= n-1 else sys.maxint

		# Return the minimum of all the cost + cost of the cell itself
		return min(down, right, diagonal) + cost[i][j]


# Time-complexity: Exponential O(2^n) as each cell has 2 options either can be included in the path or not.
def min_cost(cell, i, j):
	'''Recursive approach to solve minimum cost path problem. Starts from the final cell and calculate the cost of reaching
		the initial cell at index 0, 0. 
	'''
	if i < 0 or j < 0:
		return sys.maxint

	if i == 0 and j == 0:
		return cell[i][j]

	else:
		min_left = min_cost(cell, i-1, j)
		min_top = min_cost(cell, i, j-1)
		min_diagonal = min_cost(cell, i-1, j-1)

		return min(min_left, min(min_top, min_diagonal)) + cell[i][j]

# Time-complexity: O(m*n) where m, n are dimensions of the matrix
def min_cost_dynamic(cell):
	'''Dynamic Programming approach to minimum cost path problem'''
	m = len(cell)
	n = len(cell[0])

	for i in range(m):
		for j in range(n):
			if i > 0 or j > 0:
				min_left = cell[i-1][j] if i-1 >=0 else sys.maxint
				min_top = cell[i][j-1] if j-1 >=0 else sys.maxint
				min_diagonal = cell[i-1][j-1] if j-1 >=0 and i-1 >=0 else sys.maxint

				cell[i][j] += min(min_left, min_top, min_diagonal)

	return cell[m-1][n-1]

import unittest
class MyTest(unittest.TestCase):
	def setUp(self):
		self.cell = [[1, 2, 3],
					 [4, 8, 2],
					 [1, 5, 3]]

	def test_min_cost_recursive(self):
		self.assertEqual(min_cost_recursive(self.cell, 0, 0, len(self.cell), len(self.cell[0])), 8)

	def test_min_cost(self):
		self.assertEqual(min_cost(self.cell, len(self.cell)-1, len(self.cell[0])-1), 8)

	def test_min_cost_dynamic(self):
		self.assertEqual(min_cost_dynamic(self.cell), 8)

if __name__ == "__main__":
	unittest.main()
