# Complete the birthday function below.
def birthday(s, d, m):
    i, j = 0, m
    res = 0

    # Scan through the array with a window size of the month
    # calculate the sum of the window slit array
    # if it is equal to the date then increment counter else
    # move on to the next window slit
    while(j <= len(s)):
        if sum(s[i : j]) == d:
            res += 1
        i += 1
        j += 1
    return res
