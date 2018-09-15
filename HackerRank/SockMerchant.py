# Complete the sockMerchant function below.
def sockMerchant(n, ar):
    sockList = {}
    totalPairs = 0

    for i in ar:
        if i in sockList:
            del sockList[i]
            totalPairs += 1
        else:
            sockList[i] = 1
    return totalPairs
