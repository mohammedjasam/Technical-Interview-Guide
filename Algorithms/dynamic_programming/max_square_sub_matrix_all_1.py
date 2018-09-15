# -*- coding: UTF-8 -*-

# Maximum size square sub-matrix with all 1s

max_square = -1000000

# Recursive approach
def sub_matrix(mat, i, j):
	global max_square
	if i == 0 or j == 0:
		return mat[i][j]

	else:
		if mat[i][j] == 1:
			left = sub_matrix(mat, i-1, j)
			top = sub_matrix(mat, i, j-1)
			diagonal = sub_matrix(mat, i-1, j-1)
			res = min(left, min(top, diagonal)) + 1
		else:
			res = 0

	if res > max_square:
		max_square = res

	return res


def sub_matrix_dynamic(mat, m, n):
	soln = []

	for i in range(m):
		soln.append([None]*n)

	# Copying first columns elements to solution
	for i in range(m):
		soln[i][0] = mat[i][0]
	# Copying first row elements from matrix
	for j in range(n):
		soln[0][j] = mat[0][j]

	for i in range(1, m):
		for j in range(1, n):
			if mat[i][j] == 1:
				soln[i][j] = min(soln[i-1][j], min(soln[i-1][j-1], soln[i][j-1])) + 1
			else:
				soln[i][j] = 0


	maximum = soln[0][0]
	for i in range(m):
		for j in range(n):
			if soln[i][j] > maximum:
				maximum = soln[i][j]

	return maximum


mat = [[0, 1, 1, 0, 1], 
       [1, 1, 0, 1, 0], 
       [0, 1, 1, 1, 0],
       [1, 1, 1, 1, 0],
       [1, 1, 1, 1, 1],
       [0, 0, 0, 0, 0]]

sub_matrix(mat, 4, 4)
print max_square
print "Solving by DP"
print sub_matrix_dynamic(mat, 5, 5)