# https://www.hackerrank.com/challenges/two-pluses/problem

def up(i, j, grid):
    c = 0
    while(i > 0):
        i -= 1
        if grid[i][j] == "G":
            c += 1
        else:
            break
    return c

def down(i, j, grid):
    c = 0
    while(i < len(grid) - 1):
        i += 1
        if grid[i][j] == "G":
            c += 1
        else:
            break
    return c

def left(i, j, grid):
    c = 0
    while(j > 0):
        j -= 1
        if grid[i][j] == "G":
            c += 1
        else:
            break
    return c

def right(i, j, grid):
    c = 0
    while(j < len(grid[0]) - 1):
        j += 1
        if grid[i][j] == "G":
            c += 1
        else:
            break
    return c

def checkOverlap(si, sj, fi, fj, second, first):
    smini = (second - 1) // 4
    fmini = (first - 1) // 4
    if fi == si:
        if fj + fmini >= sj - smini:
            return 1
    elif fj == sj:
        if fi + fmini >= si - smini:
            return 1
    elif ((fj + fmini > sj) and (si - smini < fi)) or ((sj - smini < fj) and (fi + fmini > si)):
        return 1
    elif ((fj - fmini < sj) and (si - smini < fi)) or ((sj + smini > fj) and (fi + fmini > si)):
        return 1
    else:
        return 0

def twoPluses(grid):
    first = 1
    second = 1
    fi, fj, si, sj = -1, -1, -1, -1
    for i in range(1, len(grid) - 1):
        for j in range(1, len(grid[0]) - 1):
            if grid[i][j] == "G":
                print(i, j)
                print(up(i, j, grid))
                print(down(i, j, grid))
                print(left(i, j, grid))
                print(right(i, j, grid))


                mini = (min(up(i, j, grid), down(i, j, grid), left(i, j, grid), right(i, j, grid)))
                area = 4 * mini + 1
                print("Mini = ", mini)
                print("area = ", area)
                print("first = ", first)
                print("second = ", second)
                print("_________________________")

                if area >= first:
                    first = area
                elif area >= second:
                    second = area
                si, sj, fi, fj = fi, fj, i, j
                if checkOverlap(si, sj, fi, fj, second, first):
                    print(si, sj, fi, fj, second, first)
                    if si >= 0 and sj >= 0 and fi >= 0 and fj >= 0:
                        return "YES", first * second

    return first, second, first * second


grid = [["B", "B", "G", "B", "B", "B"],
        ["B", "B", "G", "B", "B", "B"],
        ["G", "G", "G", "G", "G", "B"],
        ["B", "B", "G", "G", "G", "B"],
        ["B", "B", "G", "G", "B", "B"],
        ["B", "B", "B", "B", "B", "B"]]

print(twoPluses(grid))

# TAGS: Incomplete
