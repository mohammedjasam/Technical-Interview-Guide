# https://www.hackerrank.com/challenges/beautiful-triplets/problem?h_r=next-challenge&h_v=zen

# Algorithm: Just check the next two elements related to the current element in the arrayLookup
# if you have those elements available then you have the triplet hence, increase the counter
def beautifulTriplets(d, arr):
    arrayLookup = {}

    for i in arr:
        arrayLookup[i] = 1

    count = 0
    for i in range(len(arr)):
        b = arr[i] + d
        c = arr[i] + (2 * d)

        if (b in arrayLookup) and (c in arrayLookup):
            count += 1
    return count

print(beautifulTriplets(d = 3, arr = [1, 2, 4, 5, 7, 8, 10]))
