# https://www.hackerrank.com/challenges/minimum-distances/problem


def minimumDistances(array):
    lookup = {}
    minDistance = sum(array)

    for x in range(len(array)):
        if array[x] in lookup:
            dis = abs(lookup[array[x]] - x)
            if minDistance > dis:
                minDistance = dis
        else:
            lookup[array[x]] = x
    if minDistance != sum(array):
        return minDistance
    return -1

print(minimumDistances(list(map(int, "1 2 3 4 10".split()))))
