# https://www.hackerrank.com/challenges/the-grid-search/problem

def gridSearch(G, R, C, P, r, c):
    filRow = R - r + 1
    filCol = C - c + 1

    for i in range(filRow):
        for j in range(filCol):
            daffuq = []
            for x in range(r):
                daffuq.append(G[i + x][j : j + c])
            print(daffuq)
            if daffuq == P:
                return "YES"
    return "NO"

G = [[1, 2, 3, 4, 1, 2],
     [5, 6, 1, 2, 1, 2],
     [1, 2, 3, 6, 1, 2],
     [7, 8, 1, 2, 3, 4]]
P = [[1, 2], [3, 4]]

print(gridSearch(G, 4, 6, P, 2, 2))

# TAGS: Grid, filter, search, n^2
