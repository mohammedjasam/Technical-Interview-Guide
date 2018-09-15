# -*- coding: UTF-8 -*-

'''
    Given a 2D array binaryMatrix of 0s and 1s, implement a function getNumberOfIslands that returns the 
    number of islands of 1s in binaryMatrix.

    An island is defined as a group of adjacent values that are all 1s. A cell in binaryMatrix is considered 
    adjacent to another cell if they are next to each either on the same row or column. Note that two values of 
    1 are not part of the same island if they’re sharing only a mutual “corner” (i.e. they are diagonally neighbors).
'''

def add_elements_to_queue(queue, binaryMatrix, i, j):
    if binaryMatrix[i][j] not in [0, -1] :
        queue.append((i, j))
        binaryMatrix[i][j] = -1
 
 
 
count = 0
def getNumberOfIslands(binaryMatrix):
    global count
    row = len(binaryMatrix)
    column = len(binaryMatrix[0])
    queue = []
 
    for i in range(row):
        for j in range(column):
            add_elements_to_queue(queue, binaryMatrix, i, j)

            while queue:
                r, c = queue.pop(0)
                if r > 0:
                  add_elements_to_queue(queue, binaryMatrix, r-1, c)
                if r < row-1:
                  add_elements_to_queue(queue, binaryMatrix, r+1, c)
                if c > 0:
                  add_elements_to_queue(queue, binaryMatrix, r, c-1)
                if c < column-1:
                  add_elements_to_queue(queue, binaryMatrix, r-1, c+1)
                if not queue:
                  count += 1
                  break
 
if __name__ == "__main__":
    binaryMatrix = [ [0,    1,    0,    1,    0],
                     [0,    0,    1,    1,    1],
                     [1,    0,    0,    1,    0],
                     [0,    1,    1,    0,    0],
                     [1,    0,    1,    0,    1] ]

    getNumberOfIslands(binaryMatrix) 
    print count
