# https://www.hackerrank.com/challenges/manasa-and-stones/problem

def stones(n, a, b):
    setList = [[0]]
    index = 0

    # Run till the len of setList is equal to 4
    while(len(setList) < n):
        l = setList[index]
        temp = []

        # Add the two elements to each further element
        for i in l:
            temp.append(i + a)
            temp.append(i + b)

        setList.append(list(set(temp))) # Not adding duplicates
        index += 1 # Move forward

    return(sorted((setList[-1]))) # Returning the result in sorted order

print(stones(4, 10, 100))

# TAGS:  BinaryTree, Recursively adding the two elements to previous, traversal
