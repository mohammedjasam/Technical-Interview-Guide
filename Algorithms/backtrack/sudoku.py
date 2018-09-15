# -*- coding: UTF-8 -*-

# Sudoku 

def isSafe(board, size, row, col, value):

	if row < 0 or row >= size or col < 0 or col >= size:
		return False

	# check for all the columns for current row
	for i in range(size):
		if board[row][i] == value:
			return False

	# check for all the rows for current column
	for j in range(size):
		if board[j][col] == value:
			return False

	# check for all the values in its box
	row_in = row-row%3
	col_in = col-col%3
	for i in range(3):
		for j in range(3):
			if board[i+row_in][j+col_in] == value:
				return False

	return True

def findUnassignedLocation(board, size):
	for i in range(size):
		for j in range(size):
			if board[i][j] == 0:
				return i, j
	else:
		return -1, -1

def sudoku(board, size):

	# Look for unassigned locations
	row, col = findUnassignedLocation(board, size)

	if row == -1 and col == -1:
		return True
	else:
		for i in range(1, size+1):
			if isSafe(board, size, row, col, i):
				board[row][col] = i
				if sudoku(board, size):
						return True
				# Backtrack
				board[row][col] = 0
	
	return False


# initialize a sudoku board
board = [
	[3, 0, 6, 5, 0, 8, 4, 0, 0],
	[5, 2, 0, 0, 0, 0, 0, 0, 0],
	[0, 8, 7, 0, 0, 0, 0, 3, 1],
	[0, 0, 3, 0, 1, 0, 0, 8, 0],
	[9, 0, 0, 8, 6, 3, 0, 0, 5],
	[0, 5, 0, 0, 9, 0, 6, 0, 0],
	[1, 3, 0, 0, 0, 0, 2, 5, 0],
	[0, 0, 0, 0, 0, 0, 0, 7, 4],
	[0, 0, 5, 2, 0, 6, 3, 0, 0]
	]
size = len(board)

if sudoku(board, size):
	for i in board:
		print i
else:
	print "Solution does not exist"