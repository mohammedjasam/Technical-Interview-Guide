# https://www.hackerrank.com/challenges/flatland-space-stations/problem

# The brute force method times out when there are n space stations
# Better approach,
# 1. Use the array c(indices of space stations) and create a lookup - O(1)
#    coz searching through c each time is O(n)
# 2. Run through the lookup
#       if the index is 0: increment count
#       else: Test for leading 0s using the flag
#                 if there is a leading 0s case: add the count to dis list
#                 else: add half the count to dis and set the flags accordingly
# 3. Don't forget the second edge case of trailing 0s, add count - 1 to dis list
# 4. Return the max element in the list
def flatlandSpaceStations(n, c):
    lookup = [0] * n # Lookup to store the space stations
    dis = [] # Used to store the distances
    count = 0
    hasSeen1 = 0 # flag to determine edge case of leading 0s

    # Creating lookup O(n)
    for i in c:
        lookup[i] = 1

    # Traverse through cities and lookup for space station O(n)
    for i in range(n):
        if lookup[i] == 0: # O(1)
            count += 1
        else:
            if hasSeen1:
                dis.append(count // 2)
                count = 1
            else:
                dis.append(count) # Leading 0s edge case
                hasSeen1 = 1
                count = 1
    dis.append(count - 1) # Trailing 0s edge case
    return(max(dis)) # O(n)

print(flatlandSpaceStations(20, [13, 1, 11, 10, 6]))

# TAGS: maximum, max, dis, distance, nearest, max distance from nearest
