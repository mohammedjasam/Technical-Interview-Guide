# a little complex with assigning the array with the rotated state
def circularArrayRotation(a, k, queries):
    l = len(a)
    pos = (l + k) % l
    newAr = [0] * l
    i = 0

    while(i < l):
        newAr[pos] = a[i]
        i += 1
        pos += 1
        if pos > l - 1:
            pos = 0

    res = []

    for i in queries:
        res.append(newAr[i])

    return res
