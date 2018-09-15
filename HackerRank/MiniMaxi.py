# Assigning the values to mini & maxi
# is important to get the right result
def miniMaxSum(arr):
    total = sum(arr)
    mini, maxi = total, arr[0]
    for i in arr:
        val = total - i
        if val < mini:
            mini = val
        if val > maxi:
            maxi = val
    print(mini, maxi)

miniMaxSum([1,2,3,4,5])
