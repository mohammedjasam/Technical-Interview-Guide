# https://www.hackerrank.com/challenges/kaprekar-numbers/problem

def FindModifiedKarprekar(p, q):
    res = []
    for n in range(p, q + 1):
        string = str(n * n)
        if len(string) == 1:
            string = '0' + string

        l = len(string)
        A = int(str(string[ : l // 2]))
        B = int(str(string[(l // 2) : ]))

        if n != 0:
            if A + B == n:
                # print(n)
                res.append(n)
    return res
    # return res

def kaprekarNumbers(p, q):
    res = FindModifiedKarprekar(p, q)
    if len(res) > 0:
        for i in res:
            print(i, end = " ")
    else:
        print("INVALID RANGE")

kaprekarNumbers(1, 100)
