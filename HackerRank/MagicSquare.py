### RULES TO GENERATE MAGIC SQUARE!!!!
# 1. The position of next number is calculated by decrementing row number of
# previous number by 1, and incrementing the column number of previous number by 1.
# At any time, if the calculated row position becomes -1, it will wrap around to n-1.
# Similarly, if the calculated column position becomes n, it will wrap around to 0.

# 2. If the magic square already contains a number at the calculated position,
# calculated column position will be decremented by 2, and calculated row position
# will be incremented by 1.

# 3. If the calculated row position is -1 & calculated column position is n,
# the new position would be: (0, n-2).
## REFERENCE : https://www.geeksforgeeks.org/magic-square/

# Checks if the calculated index is valid
def Valid(n, i, j, rule):
    if rule == 1 or rule == 2:
        if i == -1:
            i = n - 1
        if j == n:
            j = 0
        return i, j
    elif rule == 3:
        i = 0
        j = n - 2
        return 0, n - 2

# Calculates the next Index
def CalcIndex(n, i, j, rule):
    if rule == 2:
        i += 1
        j -= 2
        return Valid(n, i, j, rule) # Check if either i = - or j = n
    elif rule == 1:
        i -= 1
        j += 1
        if i == -1 and j == n:
            return Valid(n, i, j, 3) # Condition 3 when i = -1 AND j = n
        return Valid(n, i, j, rule) # Check if either i = - or j = n

# Prints the Magic Square
def PrintMagicSqure(magicSquare):
    for i in magicSquare:
        print(i)

def GenMagicSquare(n):
    # Observation: The number 1 is always placed at the postion (n/2, n-1)
    dropI = int(n / 2)
    dropJ = n - 1

    # Variable that holds the next number to be placed in the matrix to form a magic square
    dropNum = 1

    # Empty matrix of
    magicSquare = []
    for i in range(n):
        magicSquare.append([0] * n)

    while(dropNum <= (n * n)):
        if magicSquare[dropI][dropJ] == 0:
            magicSquare[dropI][dropJ] = dropNum
            dropNum += 1
            dropI, dropJ = CalcIndex(n, dropI, dropJ, 1)
        else:
            dropI, dropJ = CalcIndex(n, dropI, dropJ, 2)
            magicSquare[dropI][dropJ] = dropNum
            dropNum += 1
            dropI, dropJ = CalcIndex(n, dropI, dropJ, 1)

    return magicSquare

try:
    PrintMagicSqure(GenMagicSquare(21))
except Exception as e:
    print("Cannot build a Magic Squre for this Size")
