# Complete the countApplesAndOranges function below.
def countApplesAndOranges(s, t, a, b, apples, oranges):
    cApples, cOranges = 0, 0
    for apple in apples:
        dis = a + apple
        if dis >= s and dis <= t:
            cApples += 1
    for orange in oranges:
        dis = b + orange
        if dis >= s and dis <= t:
            cOranges += 1
    print(cApples)
    print(cOranges)
