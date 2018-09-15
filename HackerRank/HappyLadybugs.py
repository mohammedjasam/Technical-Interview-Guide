# https://www.hackerrank.com/challenges/happy-ladybugs/problem
# Easy

# # Algorithm:
# Dont bother swapping characters until you find a valid string. Here is the trick:
# Happy Conditions:
# Either there are at least one empty cell and there is no Letter with count 1
# or there is no empty cell but the given string is happy
def happyLadyBugs(b):
    for a in set(b):
        if a != "_" and b.count(a) == 1:
            return "NO"

    if b.count("_") == 0:
        for i in range(1, len(b) - 1):
            if b[i - 1] != b[i] and b[i + 1] != b[i]:
                return "NO"
    return "YES"

print(happyLadyBugs("RBY_YBR"))

# TAGS: Array lookups, unhappy
