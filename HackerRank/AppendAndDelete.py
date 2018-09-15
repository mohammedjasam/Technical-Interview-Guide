# Complete the appendAndDelete function below.
def appendAndDelete(s, t, k):
    minOps = 0
    ls = len(s)
    lt = len(t)
    m = min(lt, ls)
    same = 0

    for i in range(m):
        if s[i] == t[i]:
            same += 1
        else:
            break
    # Case A
    if (ls + lt - (2 * same)) > k:
        print("NO")
    elif(ls + lt - (2 * same)) % 2 == k % 2:
        print("YES")
    elif(ls + lt) < k:
        print("YES")
    else:
        print("NO")

print(appendAndDelete("ashley", "ash", 2))
