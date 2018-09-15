# https://www.hackerrank.com/challenges/acm-icpc-team/problem


# Converting binary string of 0s and 1s to its Use int(bin_string, 2)
# Ex: int('101', 2) = 5
# Python's Bitwise does the bitwise or between two integers quickly
# 5 | 6 = 7
# convert the result to binary again, to check the number of 1s in it
# Finally, do this for all pairs and then find max and count the # of max
def acmTeam(topic):
    result = []

    for i in range(len(topic) - 1):
        for j in range(i + 1, len(topic)):
            # Converting to integers
            A = int(topic[i], 2)
            B = int(topic[j], 2)

            # Finding the OR result
            val = A | B

            # Converting to Binary and counting the number of 1s
            val = bin(val).count('1')

            # Appending to the result
            result.append(val)

    return max(result), result.count(max(result))

print(acmTeam(['11101', '10101', '11001', '10111', '10000', '01110']))
