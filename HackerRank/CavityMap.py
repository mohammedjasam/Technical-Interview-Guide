# https://www.hackerrank.com/challenges/cavity-map/problem


def cavityMap(grid):
    grid = [[int(x) if x != " " for x in row]for row in grid]
    matrix = []
    for row in grid:
        row = [int(x) for x in row]
        matrix.append(row)
    print(matrix)

    for i in range(1, len(matrix) - 1):
        for j in range(1, len(matrix) - 1):
            print(matrix[i - 1][j], matrix[i][j])
            if matrix[i - 1][j] < matrix[i][j] and \
                matrix[i + 1][j] < matrix[i][j] and \
                matrix[i][j - 1] < matrix[i][j] and \
                matrix[i][j + 1] < matrix[i][j]:
                matrix[i][j] = -1

    res = []
    for i in range(len(matrix)):
        s = ""
        for j in range(len(matrix)):
            if matrix[i][j] == -1:
                s += "X"
            else:
                s += str(matrix[i][j])
        res.append(s)
    return res

print(cavityMap(["1 2", "1 2"]))


# C ++
# vector<string> cavityMap(vector<string> grid) {
#
#  vector<string> cavityGrid = grid;
#
#  for(int i = 1 ; i < grid.size() - 1; i++)
#     for(int j = 1; j < grid[i].size() - 1; j++)
#       if(grid[i][j] > grid[i][j+1] && grid[i][j-1] < grid[i][j] &&
#          grid[i][j] > grid[i+1][j] && grid[i-1][j] < grid[i][j])
#             cavityGrid[i][j] = 'X';
#
#  return cavityGrid;


# TAGS: Find smallest among adjacent values, cavity
