# https://www.hackerrank.com/challenges/fair-rations/problem

# Idea: If the sum of the array is ODD,
# then adding 2's to its each time will not make it even
# Hence, While summing the bread check if the sum turns out to be odd
# if so, add 2 to the count, return count if sum is even
def fairRations(breadArray):
    s = 0
    count = 0

    for i in breadArray:
        s += i
        if s % 2 != 0:
            count += 2

    return count if not (s % 2) else "NO"

array = [1, 0, 1, 1, 1, 1, 0, 1]
print(fairRations(array))

# TAGS: bread, distribution, fair, 2 bread
