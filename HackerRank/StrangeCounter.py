# https://www.hackerrank.com/challenges/strange-code/problem
# Easy


def strangeCounter(t):
    rem = 3 # The time upward
    while(rem < t):
        t = t - rem # Subtract from the original
        rem *= 2 # Follow the condition and increment
    return(rem - t + 1) # The difference between time upward and original + 1

print(strangeCounter(8))

# TAGS: revise, time, modulus
