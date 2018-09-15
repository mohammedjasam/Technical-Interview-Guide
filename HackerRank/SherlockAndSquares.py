import math
# Complete the squares function below.
def squares(a, b):
    return math.floor(b**(0.5)) - math.ceil(a**(0.5)) + 1
print(squares(100, 1000))
