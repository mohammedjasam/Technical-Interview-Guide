# Complete the breakingRecords function below.
def breakingRecords(scores):
    miniCount, maxiCount = 0, 0
    mini, maxi = scores[0], scores[0]

    for score in scores:
        if score < mini:
            mini = score
            miniCount += 1
        elif score > maxi:
            maxi = score
            maxiCount += 1

    return([maxiCount, miniCount])
