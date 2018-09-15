# coding: UTF-8

'''
    Flood fill algorithm helps in visiting each and every point in a given area. It determines the area connected to a 
    given cell in a multi-dimensional array. 

    Problem: Micro just bought a maze, that can be represented as a matrix A of size M*N. Each cell of the matrix can be 
    either 0 or 1. If a cell is 0, that means it cannot be visited and if it is 1 then it can be visited. Allowed moves are 
    up, down, left and right. Help Micro to find out if he can reach from the cell (0, 0) to the cell (M-1, N-1), it is guaranteed 
    that the cells (0, 0) and (M-1, N-1) have values 1.
'''

def DFS(x, y, m, n, mat, visited):
    ''' Returns True if there is a path between (0, 0) and (M-1, N-1) and False otherwise'''
    if x < 0 or y < 0:
        return False
        
    if x >= m or y >= n:
        return False
        
    if x == m-1 and y == n-1:
        return True
        
    if mat[x][y] == 0:
        return False
        
    if visited[x][y]:
        return False

    visited[x][y] = True
    
    if DFS(x+1, y, m, n, mat, visited):
        return True
        
    
    if DFS(x-1, y, m, n, mat, visited):
        return True
        
    if DFS(x, y+1, m, n, mat, visited):
        return True
        
    if DFS(x, y-1, m, n, mat, visited):
        return True
    
    return False

if __name__ == "__main__":
    m = int(raw_input())
    n = int(raw_input())
    mat = [[] for i in range(m)]
    visited = [[False for i in range(n)] for i in range(m)]

    for i in range(m):
        for j in range(n):
                k = int(raw_input())
                mat[i].append(k)

    if DFS(0, 0, m, n, mat, visited):
        print "Yes"
    else:
        print "No"
