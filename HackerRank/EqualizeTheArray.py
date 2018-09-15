# https://www.hackerrank.com/challenges/equality-in-a-array/problem

# Find the max reccuring element and delete its count from the len of the array
def equalizeArray(arr):
    d = {}
    maxElementCount = -1

    for element in arr:
        if element in d:
            d[element] += 1
        else:
            d[element] = 1

        if d[element] > maxElementCount:
            maxElementCount = d[element]
    return len(arr) - maxElementCount

print(equalizeArray([1,1,1,2,2]))
