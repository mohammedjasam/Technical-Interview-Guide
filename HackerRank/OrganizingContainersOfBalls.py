# https://www.hackerrank.com/challenges/organizing-containers-of-balls/problem
import sys

# Solution: For each swap operation, the net gain of each container is 0
# countBalls - an array of total number of balls in each container
# countBox - an array of total number of balls in each category
# Sort both countBalls and countBox, traverse and check similarity
# If dissimilar return Impossible else Possible
def organizingContainers(container):
    countBox = []
    countBalls = [0] * len(container[0])

    # Counting the sum of the boxes and the number of balls of each type in all boxes
    for box in container:
        countBox.append(sum(box))
        for i in range(len(box)):
            countBalls[i] += box[i]

    # Sorting is necessary because the type of ball at index i,
    # does not necessarily belong to box i
    countBox = sorted(countBox)
    countBalls = sorted(countBalls)

    for i in range(len(countBox)):
        if countBox[i] != countBalls[i]:
            return "Impossible"
    return "Possible"
