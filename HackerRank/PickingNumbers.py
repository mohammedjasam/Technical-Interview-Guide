# The algorithm completes in O(n) complexity
def pickingNumbers(a):
    # O(n)
    m = max(a) # Find max element in the array to create an array with those many indices
    lookup = [0] * m # create an empty array

    # O(n)
    for i in a:
        lookup[i - 1] += 1 # Fill the indices with the count of those numbers in the original array

    res = 0 # Final Result

    # O(n)
    # Traverse through the array and find which two consecutive indices
    # contribute to max sum of their values
    for i in range(len(lookup) - 1):
        val = lookup[i] + lookup[i + 1]

        if res < val: # Finding max count
            res = val # updating the max count
    return res

print(pickingNumbers([4, 6, 5, 3, 3, 1]))
