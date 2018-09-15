# Complete the countingValleys function below.
def countingValleys(n, s):
    val = 0
    count = 0
    l = [0]
    for i in s:
        if i == 'U':
            last = val
            val += 1
        else:
            last = val
            val -= 1

        if val == 0:
            if last > 0:
                pass
            else:
                count += 1
    return(count)
countingValleys(5, "UDUDUDUDUDUD")
