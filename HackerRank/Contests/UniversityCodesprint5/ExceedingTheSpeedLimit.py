# https://www.hackerrank.com/contests/university-codesprint-5/challenges/exceeding-speed-limit

def solve(s):
    if s <= 90:
        return "0 No punishment"
    elif s > 90 and s <= 110:
        return str((s - 90) * 300) + " Warning"
    elif s > 110:
        return str((s - 90) * 500) + " License removed"


print(solve(85))
