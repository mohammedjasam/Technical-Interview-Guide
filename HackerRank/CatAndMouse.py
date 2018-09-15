# Complete the catAndMouse function below.
def catAndMouse(x, y, z):
    disA = abs(x - z)
    disB = abs(y - z)

    if disA == disB:
        return "Mouse C"
    elif abs(x - z) < abs(y - z):
        return "Cat A"
    elif abs(x - z) > abs(y - z):
        return "Cat B"
