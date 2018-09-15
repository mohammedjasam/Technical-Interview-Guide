# Complete the jumpingOnClouds function below.
def jumpingOnClouds(c, k):
    e = 100
    n = len(c)
    i = 0
    print("first index:", i, "value is:", c[i], "energy is:", e)
    print()
    while(e > 0):
        i = (i + k) % n
        e -= 1
        if c[i] == 1:
            e -= 2
        print("next index:", i, "value is:", c[i], "energy is:", e)
        print()
        if i == 0:
            break
    return(e)

l = "0 0 1 0"
print(jumpingOnClouds(list(map(int, l.split())), 2))
