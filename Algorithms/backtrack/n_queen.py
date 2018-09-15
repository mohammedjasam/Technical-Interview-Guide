# -*- coding: UTF-8 -*-

# N Queen Problem

'''
	The N Queen is the problem of placing N chess queens on an N×N chessboard so that no two queens attack each other. 

	Solution: The idea is to place queens one by one in different columns, starting from the leftmost column. When we place a queen 
	in a column, we check for clashes with already placed queens. In the current column, if we find a row for which there is no 
	clash, we mark this row and column as part of the solution. If we do not find such a row due to clashes then we backtrack and 
	return false.
'''

def is_safe(board, N, row, col):
	'''Check if the current position (row, column) are safe from attack from other queens
		As we are placing column wise, we need to check only for all previous columns, upper diagonal and lower diagonal
	'''

	# check for columns on left side
	for i in range(col):
		if board[row][i]:
			return False

	# check for upper right diagonal
	i = row
	j = col
	while i < N and j >=0:
		if board[i][j]:
			return False
		i += 1
		j -= 1

	# check for upper left diagonal
	i = row
	j = col
	while i >= 0 and j >= 0:
		if board[i][j]:
			return False
		i -= 1
		j -= 1

	return True


def n_queen_backtrack(N, board, col):
	'''Backtrack function that places queen column wise and check if it is feasible and backtrack otherwise'''
	if col >= N:
		return True

	else:
		for row in range(N):
			if is_safe(board, N, row, col):
				board[row][col] = 1
				# recursively check for further columns
				if n_queen_backtrack(N, board, col+1):
					return True
				# Backtarck
				board[row][col] = 0

		return False

def n_queen(N):
	'''Initialize a board of size N*N and call backtrack function to place the queens'''
	board = [[0] * N for n in range(N)]
	
	if n_queen_backtrack(N, board, 0):
		print board
	else:
		print "Solution does not exist"

if __name__ == "__main__":
	n_queen(5)
