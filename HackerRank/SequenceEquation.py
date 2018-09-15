# Complete the permutationEquation function below.
def permutationEquation(p):
    lookup = {}
    res = []
    for x in range(len(p)):
        lookup[p[x]] = x + 1

    for x in range(len(p)):
        res.append(lookup[lookup[x + 1]])
    return res
permutationEquation([2,3,1])
