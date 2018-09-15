# https://www.hackerrank.com/challenges/3d-surface-area/problem?h_r=next-challenge&h_v=legacy
# Medium

# Crazy Algorithm:
# For every element in the matrix, it adds top and bottom area
# (which are 1 unit each one), and then, for each side of every element,
# the area from top of the element to top of their neighbours.
#
# For instance, in this example:
# 0 1 0
# 2 4 2
# 0 0 0
#
# Analyzing the element '1' it will add 2 units to the area
# (top and bottom squares) and 1 unit for north, east and west sides
# (no unit at south because 4 is larger than 1).
# Then, for instance at element 4 it will add 2 units (top and bottom units),
# then 3 units at north (4-1), 2 units at east and west (4-2) and
# 4 units at south (4-0).


def surfaceArea(H, W, A):
    area = 0
    neighbours = [[-1, 0], [0, 1], [1, 0], [0, -1]]

    for x in range(H):
        for y in range(W):
            el = A[x][y]
            # add base and top area
            area += 2
            for dx, dy in neighbours:
                try:
                    # Raise index exception if trying to access index -1
                    if -1 in [x + dx, y + dy]:
                        raise IndexError

                    # Add area of actual element from neighbours as base
                    new = el - A[x + dx][y + dy]
                    if new > 0:
                        area += new
                # Add area corresponding to the sides of the figure
                except IndexError:
                    area += el
    return area
print(surfaceArea(3, 3, [[1, 3, 4], [2, 2, 3], [1, 2, 4]]))

# TAGS: Array traversal, 3d analysis, visual interpretation, O(n^2)
