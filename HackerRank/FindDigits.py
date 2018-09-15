# Complete the findDigits function below.
def findDigits(n):
    listNum = list(map(int, list(str(n))))

    count = 0
    for i in listNum:
        if i != 0:
            if n % i == 0:
                count += 1
    return(count)



findDigits(123)
