# Complete the beautifulDays function below.
def beautifulDays(i, j, k):
    c = 0
    for i in range(i, j + 1):
        if (abs(i - int(''.join(reversed(str(i))))) % k) == 0:
            c += 1
    return c

print(beautifulDays(20, 23, 6))
