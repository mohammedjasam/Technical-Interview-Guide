# -*- coding: UTF-8 -*-

# Rat in a maze problem

# Rat is allowed to move only forward and down

def isSafe(board, x, y):

	if x < len(board) and y < len(board) and board[x][y]:
		return True

	return False

def get_coordinates(current, i):
	if i == 0:
		x, y = current['x']+1, current['y']
	elif i == 1:
		x, y = current['x'], current['y']+1

	return x, y

def rat_in_maze(board, current, destination, solution):
	
	# if rat current coordinates matches with its destination coordinates
	if current['x'] == destination['x'] and current['y'] == destination['y']:
		return True
	else:
		for i in range(2):
			x, y = get_coordinates(current, i)
			# Check if the rat is allowed to move to these coordinates
			if isSafe(board, x, y):
				solution[x][y] = 1
				current['x'] = x
				current['y'] = y
				# Recusive calling the same function
				if rat_in_maze(board, current, destination, solution):
					return True
				# Backtrack
				solution[x][y] = 0
				if i==0:
					current['x'] = x-1
				if i==1:
					current['y'] = y-1

size = 4
board = [[1, 0, 0, 0], [1, 1, 0, 1], [0, 1, 0, 0], [1, 1, 1, 1]]

# initialize source and destination coordinates
source = {'x':0, 'y':0}
destination = {'x':3, 'y':3}

# initialize solution matrix with all 0's
solution = []
for i in range(size):
	solution.append([0]*size)

# initialize current position of rat with its source position
current = source
solution[source['x']][source['y']] = 1
rat_in_maze(board, current, destination, solution)
print solution
