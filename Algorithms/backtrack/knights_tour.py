# -*- coding: UTF-8 -*-

# Knights tour problem

'''
	Problem : A knight is placed on the first block of an empty board and, moving according to the rules of chess, must 
	visit each square exactly once.
'''

def get_possible_moves(board, N, row, col):
	'''Return all the possible moves from the current row and col'''
	moves = []

	for r in [row-2, row+2]:
		for c in [col-1, col+1]:
			if r >= 0 and c >= 0 and r < N and c < N and board[r][c] < 0:
				moves.append((r, c))

	for r in [row-1, row+1]:
		for c in [col-2, col+2]:
			if r >= 0 and c >= 0 and r < N and c < N and board[r][c] < 0:
				moves.append((r, c))

	return moves


def knights_tour_backtrack(board, N, row, col, count):
	'''Backtrack function to visit nodes in a board'''

	# If count is equal to (N*N), it means that knight has visited all the nodes
	if count == (N * N):
		return True

	# Get all the possible moves from the current position
	possible_moves = get_possible_moves(board, N, row, col)

	for move in possible_moves:
		r, c = move
		# Assign the count value for a row and column when found it is safe
		board[r][c] = count
		# Now, visit the board from the current row and column and increase the count by 1
		if knights_tour_backtrack(board, N, r, c, count+1):
			return True

		# Backtrack if it's not possible to visit all the nodes
		board[r][c] = -1

	return False

def knights_tour(N):
	'''Initialize a board of size N*N and call backtrack function to place the knights'''
	board = [[-1] * N for n in range(N)]

	# Initialize the position of the knight with (0, 0) and count to 0
	board[0][0] = 0

	# Calling knights tour for count 1
	if knights_tour_backtrack(board, N, 0, 0, 1):
		print board
	else:
		print "Solution does not exist"

if __name__ == "__main__":
	knights_tour(5)
