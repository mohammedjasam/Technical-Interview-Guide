# Complete the hurdleRace function below.
def hurdleRace(k, height):
    if k < max(height):
        return max(height) - k
    return 0

print(hurdleRace(2, [2,5,4,5,2]))
