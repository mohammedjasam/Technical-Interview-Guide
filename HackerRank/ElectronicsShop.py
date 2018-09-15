def getMoneySpent(keyboards, drives, b):
    cost = -1
    for i in keyboards:
        for j in drives:
            if i + j <= b:
                if cost < i + j:
                    cost = i + j
    return cost

getMoneySpent([40, 50, 6])
