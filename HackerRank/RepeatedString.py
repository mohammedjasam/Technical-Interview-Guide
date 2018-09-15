# https://www.hackerrank.com/challenges/repeated-string/problem
import math

# Split the array into two parts. Count the number of a's in the quotient * len(s)
# Add the count of a's from 0 to the partial len of s. This should give the total
# number of a's
def repeatedString(s, n):
    return s.count("a") * (n // len(s)) + s[ : n % len(s)].count("a")
print(repeatedString('a', 22))
