# https://www.hackerrank.com/challenges/queens-attack-2/problem

def queensAttack(n, k, rowQueen, colQueen, obstacles):
    # Find all possible attack positions in each directions
    N = n - rowQueen
    S = rowQueen - 1
    E = n - colQueen
    W = colQueen - 1
    NE = min(N, E)
    NW = min(N, W)
    SE = min(S, E)
    SW = min(S, W)

    for obs in obstacles:
        rowObstacle, colObstacle = obs[0], obs[1]

        # If they're the obstacle is on the same col as the Queen
        if(colObstacle == colQueen):
            if(rowObstacle > rowQueen):
                N = min(N, rowObstacle - rowQueen - 1) # Update num of atttack in North
            else:
                S = min(S, rowQueen - rowObstacle - 1) # Update num of atttack in South

        # If they're the obstacle is on the same row as the Queen
        elif(rowObstacle == rowQueen):
            if(colObstacle > colQueen):
                E = min(E, colObstacle - colQueen - 1) # Update num of atttack in East
            else:
                W = min(W, colQueen - colObstacle - 1) # Update num of atttack in West

        # Checking for the diagonals!
        elif(abs(rowObstacle - rowQueen) == abs(colObstacle - colQueen)):
            # Checking if the object is to the right of the queen (i.e) East
            if colObstacle > colQueen:
                # Checking if the obstacle is above the queen (i.e) NorthEast
                if(rowObstacle > rowQueen):
                    NE = min(NE, colObstacle - colQueen - 1) # Update num of atttack in NorthEast
                # Checking if the obstacle is below the queen (i.e) SouthEast
                else:
                    SE = min(SE, colObstacle - colQueen - 1) # Update num of atttack in SouthEast

            # Checking if the object is to the left of the queen (i.e) West
            else:
                # Checking if the obstacle is above the queen (i.e) NorthWest
                if(rowObstacle > rowQueen):
                    NW = min(NW, colQueen - colObstacle - 1)
                # Checking if the obstacle is below the queen (i.e) SouthWest
                else:
                    SW = min(SW, colQueen - colObstacle - 1)

    return (N + E + W + S + NE + NW + SE + SW)

n = 8
k = 9
row_q = 4
col_q = 3
obstacles = [[3, 3],
             [4, 4],
             [8, 3],
             [6, 1],
             [4, 1],
             [2, 1],
             [2, 5],
             [2, 6],
             [7, 6]]

print(queensAttack(n, k, row_q, col_q, obstacles))
