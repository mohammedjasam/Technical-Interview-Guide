# Complete the viralAdvertising function below.
def viralAdvertising(n):
    sumLiked = 0
    day = 1
    liked = 5 // 2
    sumLiked += liked
    receivedBy = liked * 3

    # print(liked, receivedBy)

    while(day < n):
        day += 1
        liked = receivedBy // 2
        receivedBy = liked * 3
        sumLiked += liked

    return sumLiked
print(viralAdvertising(3))
