# Complete the saveThePrisoner function below.
def saveThePrisoner(numPrisoners, numSweets, start):
    if ((numSweets + start - 1) % numPrisoners == 0):
        return(numPrisoners)
    else:
        return ((numSweets + start - 1) % numPrisoners)
print(saveThePrisoner(3, 7, 3))
