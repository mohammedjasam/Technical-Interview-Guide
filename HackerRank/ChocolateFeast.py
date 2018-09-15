# https://www.hackerrank.com/challenges/chocolate-feast/problem

# Algorithm is specified in the question
def chocolateFeast(n, c, m):
    chocolates = n // c
    wrappers = chocolates
    count = chocolates

    while(wrappers >= m):
        chocolates = wrappers // m
        wrappers = wrappers % m + chocolates
        count += chocolates

    return count



print(chocolateFeast(7,3,2))
