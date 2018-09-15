# -*- coding: UTF-8 -*-

'''
	Imagine a robot sitting on the upper left corner of the grid with r rows and c columns. The robot can only move
	in two directions, right and down, but certain cells are off limits such that the robot cannot step on them.
	Design an algorithm to find the path for the robot from the top left to the bottom right.
'''
def find_path(cur_i, cur_j, grid, path):
	
	if cur_i < 0 or cur_j < 0:
		return False

	if grid[cur_i][cur_j] in ['X', 'P']:
		return False

	if (cur_i == 0 and cur_j == 0) or find_path(cur_i-1, cur_j, grid, path) or find_path(cur_i, cur_j-1, grid, path):
		path.append((cur_i, cur_j))
		return True

	grid[cur_i][cur_j] = 'P'

	return False

def find_path_dynamic(cur_i, cur_j, grid, path, cache):
	
	if cur_i < 0 or cur_j < 0:
		return False

	if grid[cur_i][cur_j] == 'X':
		return False

	key = (cur_i, cur_j)

	if key in cache:
		return cache[key]

	success = False
	if (cur_i == 0 and cur_j == 0) or find_path(cur_i-1, cur_j, grid, path) or find_path(cur_i, cur_j-1, grid, path):
		path.append((cur_i, cur_j))
		success = True

	cache[(cur_i, cur_j)] = success
	return success

if __name__ == "__main__":
	grid = []
	for i in range(6):
		grid.append(['']*5)
	
	grid[0][2] = "X"
	grid[1][4] = "X"
	grid[2][3] = "X"
	grid[4][0] = "X"
	print grid
	path = []
	find_path(len(grid)-1, len(grid[0])-1, grid, path)
	print path
	path = []
	cache = {}
	find_path_dynamic(len(grid)-1, len(grid[0])-1, grid, path, cache)
	print path
