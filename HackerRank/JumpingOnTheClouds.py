# https://www.hackerrank.com/challenges/jumping-on-the-clouds/problem

# Greedy approach, select the larger step if its a valid move,
# else take the smaller step.
def jumpingOnTheClouds(c):
    l = 0
    count = 0

    while(l < len(c) - 1):
        if l + 2 < len(c) and c[l + 2] != 1:
            l = l + 2
            count += 1
        else:
            l = l + 1
            count += 1
    return count

print(jumpingOnTheClouds([0,1,0,0,0,1,0]))
