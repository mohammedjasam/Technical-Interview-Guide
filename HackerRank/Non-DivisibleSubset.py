# Analysis:
# First, let's count the number of integers having every remainder of division by k
# (i.e., 0 through k-1). Let's denote the number of integers from the set which give the remainder t modulo k as A[t].
# Then, consider some specific remainder t > 0.If we take at least one integer with the remainder t and at least one with the remainder k - t,
# then the sum of these two integers will be evenly divisible by k.Therefore, for any fixed t we'll have to decide what to take to the answer set:
# A[t] integers with the remainder t, or A[k-t] integers with the remainder k-t. We choose the greater value among them.

# It works for all except for two cases:
# 1. For t = 0 there's no different pair which would have a sum evenly divisible by k, but we also can't take 2 or more numbers with the remainder
#    equal to 0 because their sum would be evenly divisible by k. So we take min(1, A[0]) to our answer.
# 2. Also, if k is even and t = k/2, then taking two integers with remainder t will make the sum divisible by k, so for even k and t = k/2 we take
#    min(1, A[k/2])

# Complete the nonDivisibleSubset function below.
def nonDivisibleSubset(k, arr):
    d = {x:[] for x in range(k)}
    n = len(arr)
    res = 0
    for i in range(n):
        d[arr[i] % k].append(arr[i])
        count = 0
        if len(d[0]) > 0:
            count = 1

        S = set([(x, k - x) for x in range(1, (k // 2) + 1)])

        for i, j in S:
            if i != j:
                if len(d[i]) > len(d[j]):
                    count += len(d[i])
                else:
                    count += len(d[j])
            else:
                if len(d[i]) > 0:
                    count += 1

        res = count
    return res 

S = [1, 5, 6, 2, 7, 9, 11, 3, 8]
k = 10
print(nonDivisibleSubset(k, S))
