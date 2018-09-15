# https://www.hackerrank.com/challenges/service-lane/problem


def serviceLane(width, cases):
    result = []

    for case in cases:
        i = case[0]
        j = case[1]

        result.append(min(width[i : j + 1]))
    return result

serviceLane(1, [[1, 2], [3, 4]])
