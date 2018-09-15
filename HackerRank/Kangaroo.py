# Complete the kangaroo function below.
def kangaroo(x1, v1, x2, v2):
    if x1 == x2 and v1 == v2:
        return ("YES")
    elif x1 == x2 and v1 > v2:
        return ("NO")
    elif x1 <= x2 and v1 <= v2:
        return ("NO")
    else:
        if (x1 - x2) % (v1-v2) == 0:
            return 'YES'
        else:
            return 'NO'
