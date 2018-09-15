'''
	Problem: Write an algorithm such that if an element in an M * N matrix is zeo, its entire row and column is set to 0

	Solution: Loop over the matrix and look for element who's value is 0. Take two arrays whose length is equal to 
	number of rows and columns respectively. If any element is zero mark that value of row and column in each array as true. 

	Time Complexity: O(M * N)
	Space Complexity: O(M + N)

'''

def zeroMatrix(matrix):

	row_len = len(matrix)
	col_len = len(matrix[0])

	# Will store True if the row contains any zero
	row_array = [False] * row_len
	# Will store True if the column contains any zero
	col_array = [False] * col_len

	# store the row and column index with value 0
	for i in range(row_len):
		for j in range(col_len):

			if matrix[i][j] == 0:
				row_array[i] = True
				col_array[j] = True

	# Check for each row and make the entire row zero if found True
	for i in range(row_len):

		if row_array[i]:
			# nullify row
			for j in range(col_len):
				matrix[i][j] = 0

	# If any zero found for a column, make the entire column zero
	for i in range(col_len):

		if col_array[i]:
			# nullify column
			for j in range(row_len):
				matrix[j][i] = 0


	return matrix

'''
	Second approach: We can reduce the space complexity to O(1) by using the first row as a replacement for the row array
	and first column as the replacement for the column array.
'''

def setZeroes(matrix):
	rowHasZero = False
	columnHasZero = False

	# Checking for the elements in the first column, i.e. checking for matrix[i][0]
	for row in matrix:
		if row[0] == 0:
			rowHasZero = True

	# Checking for the elements in the first row ie. matrix[0][j]
	for j in matrix[0]:
		if j == 0:
			columnHasZero = True

	# Check for each element in the rest of matrix 
	for i in range(1, len(matrix)):
		for j in range(1, len(matrix[0])):
			if matrix[i][j] == 0:
				matrix[i][0] = 0
				matrix[0][j] = 0

	# For all the zero elements in the first column, nullify row whose first element is zero
	for i in range(1, len(matrix)):
		if matrix[i][0] == 0:
			nullifyRow(matrix, i)

	# For all the zero elements in first row, nullify all columns whose first element is zero
	for j in range(1, len(matrix[0])):
		if matrix[0][j] == 0:
			nullifyCol(matrix, j)


	if rowHasZero:
		nullifyRow(matrix, 0)

	if columnHasZero:
		nullifyCol(matrix, 0)

	return matrix

def nullifyRow(matrix, i):
	if i >= len(matrix):
		return
	
	for j in range(len(matrix[i])):
		matrix[i][j] = 0

def nullifyCol(matrix, j):
	if j > len(matrix[0]):
		return

	for i in range(len(matrix)):
		matrix[i][j] = 0


# Writing unit-test for the above functions
import unittest

class MyTest(unittest.TestCase):

	def test(self):
		self.assertEqual(zeroMatrix([[1, 2, 3], [4, 5, 6], [7, 8, 0]]), [[1, 2, 0], [4, 5, 0], [0, 0, 0]])
		self.assertEqual(setZeroes([[1, 2, 3], [4, 5, 6], [7, 8, 0]]), [[1, 2, 0], [4, 5, 0], [0, 0, 0]])

unittest.main()
