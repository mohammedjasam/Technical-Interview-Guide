# Complete the cutTheSticks function below.
def cutTheSticks(arr):
    lastMin = minLen = min(arr)
    l = len(arr)
    res = []
    while(l > 0):
        res.append(l)
        for i in range(len(arr)):
            if arr[i] >= minLen:
                arr[i] -= minLen

                if arr[i] == 0:
                    l -= 1
        try:
            minLen = min(i for i in arr if i > 0)
        except:
            return res

l = list(map(int, "5 4 4 2 2 8".split()))

print(cutTheSticks(l))
