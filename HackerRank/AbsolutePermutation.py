# https://www.hackerrank.com/challenges/absolute-permutation/problem
# Medium

# Algorithm:
# First, there are two exception cases, like below:#
#   1. k == 0: print all the numbers from 1 to N
#
#   2. If n % (2 * k) is not ZERO, print -1.
#      That's because you'll need to "shuffle" groups of 2 * k elements.
#      For example, when n = 8 and k = 2, you'll start off with
#      [1,2,3,4,5,6,7,8] and shuffle groups of 4 like this:
#      1 and 3
#      2 and 4
#      5 and 7
#      6 and 8
#      ...
#      The approach works in this case because 8 is divisible by 4.
#      Or more generally, it will work when n is divisble by 2*k.
#
#   3. Otherwise, follow the pattern below:#
#      If we go from 1 to N (i),Permutation is either i+k or i-k.
#      It always starts with i + k.
#      1. Put i+k to permutaion for k times
#      2. Switch to i - k for k times
#      3. Repeat 1 & 2 until the end.

def absolutePermutation(n, k):
    # First edge case, when k == 0 return the normal list
    if k == 0:
        return(list(range(1, n + 1)))
    elif n % (2 * k) != 0: # If this is false then return -1
        return([-1])
    else:
        add = True
        perm = []

        for i in range(1, n + 1):
            if add:
                perm.append(i + k)
            else:
                perm.append(i - k)

            if i % k == 0:
                if add:
                    add = False
                else:
                    add = True
        return(perm)

print(absolutePermutation(10, 1))

# ALT

# for _ in range(int(input().strip())):
#     n, k = [int(x) for x in input().strip().split(' ')]
#     if k != 0 and n % k != 0:
#         print(-1)
#         continue
#
#     arr = [None] * (n+1) # initialize iterable
#     for i in range(1,len(arr)):
#         if arr[i] is None:
#             arr[i] = i + k
#             arr[i+k] = i
#
#     print(' '.join([str(j) for j in arr[1:]]))

# TAGS: Revise
