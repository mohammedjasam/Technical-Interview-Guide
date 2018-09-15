# Complete the bonAppetit function below.
def bonAppetit(bill, k, b):
    cost = 0
    cost = sum(bill) - bill[k]

    herShare = cost // 2

    if b == herShare:
        return "Bon Appetit"
    else:
        return int(b - herShare)

print(bonAppetit([3, 10, 2, 9], 1, 7))
