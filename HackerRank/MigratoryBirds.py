# Find the most repetitive smallest element
def migratoryBirds(arr):
    minVal = arr[0]
    maxCount = -1
    d = {}
    for n in arr:
        if n in d:
            d[n] += 1
        else:
            d[n] = 1

        # if the maxCount is <= then it updates the maxCount,
        # the = is required to update the minval that has the
        # same count as then maxVal
        if maxCount <= d[n]:
            maxCount = d[n]
            if n <= minVal:
                minVal = n
            else:
                if d[minVal] < maxCount:
                    minVal = n
    return(minVal)

l = [1, 2, 3, 4, 5, 4, 3]
migratoryBirds(l)
