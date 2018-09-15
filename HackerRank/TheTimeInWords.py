# https://www.hackerrank.com/challenges/the-time-in-words/problem


def timeInWords(h, m):
    ByOne = [0, 'one', 'two', 'three', 'four', 'five', 'six', 'seven', 'eight', 'nine', 'ten',
             'eleven', 'twelve', 'thirteen', 'fourteen', 'fifteen', 'sixteen', 'seventeen',
             'eighteen', 'ninteen', 'twenty']

    ByQua = ["%s o' clock", "quarter past %s", "half past %s", "quarter to %s"]

    for i in range(1, 10):
        ByOne.append('twenty %s' %ByOne[i])

    hour = ByOne[h] if (m < 31) else ByOne[h + 1]

    if not m % 15:
        return(ByQua[m // 15] % hour)
    elif m < 30:
        if m < 10:
            return("%s minute" % ByOne[m] + " past %s" %hour)
        else:
            return("%s minutes" % ByOne[m] + "s" * (m == 1) + " past %s" %hour)
    else:
        return("%s minutes" % ByOne[60 - m] + "s" * (m == 59) + " to %s" %hour)

print(timeInWords(1, 1))
