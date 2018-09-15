# https://www.hackerrank.com/challenges/encryption/problem
import math


# Approach: It is char selection in a long string, since there is a multiple of column index
# that we need to pick at each iteration to join to the result we can use MODULUS

def encryption(s):
    deSpacedString = "".join(s.split()) # Removed Spaces

    L = len(deSpacedString) # Length of String

    rows = math.floor(L ** (0.5)) # Rows for the new encrypted string
    cols = math.ceil(L ** (0.5)) # Cols for the new encrypted string

    # Checking if the rows * cols is greater than the length of the String
    # else we cant fit the string in the new new array with these dimensions
    if rows * cols < L:
        rows += 1
    result = {}

    # Calculating the multiple of each col and adding it to a dictionary to retrieve later
    for i in range(len(deSpacedString)):
        if (i % cols) in result:
            result[i % cols] += deSpacedString[i]
        else:
            result[i % cols] = deSpacedString[i]

    # Generating the result answer
    ans = ""
    for i in range(cols):
        ans += result[i] + " "

    return ans[: -1] # Stripping the last space

print(encryption("feed   the dog"))
