# https://www.hackerrank.com/challenges/bigger-is-greater/problem
# Lexicographical Permutation Algorithm: https://www.nayuki.io/page/next-lexicographical-permutation-algorithm

# ALGORITHM:
# 1. Find largest index i such that array[i − 1] < array[i].
#    (If no such i exists, then this is already the last permutation.)
#
# 2. Find largest index j such that j ≥ i and array[j] > array[i − 1].
#
# 3. Swap array[j] and array[i − 1].
#
# 4. Reverse the suffix starting at array[i].

# -- Basic version --
#
# Computes the next lexicographical permutation of the specified list in place,
# returning whether a next permutation existed. (Returns False when the argument
# is already the last possible permutation.)
## Example:
#   arr = [0, 1, 0]
#   next_permutation(arr)  (returns True)
#   arr has been modified to be [1, 0, 0]

def next_permutation(arr):
    i = len(arr) - 1

    while i > 0 and arr[i - 1] >= arr[i]:
        i -= 1
    if i <= 0:
        return [], False


    j = len(arr) - 1

    # Find the next smallest number
    while(arr[j] <= arr[i - 1]):
        j -= 1

    # Swap those elements
    arr[i - 1], arr[j] = arr[j], arr[i - 1]

    # Reverse the suffix array
    arr[i : ] = arr[len(arr) - 1 : i - 1 : -1]

    return arr, True

def biggerIsGreater(word):
    alphabets = "abcdefghijklmnopqrstuvwxyz"
    lookupAlpha = {a : b for a, b in zip(alphabets, range(1, 27))}
    lookupNum = {a : b for a, b in zip(range(1, 27), alphabets)}
    wordMap = []

    for w in word:
        wordMap.append(lookupAlpha[w])

    res, val = next_permutation(wordMap)

    if val == True:
        s = ""
        for i in res:
            s += lookupNum[i]
    return s

print(biggerIsGreater("abdc"))








# -- Comparator version --
#
# Computes the next lexicographical permutation of the specified list in place,
# returning whether a next permutation existed. (Returns False when the argument
# is already the last possible permutation.)
#
# comp is a comparison function - comp(x, y) returns a negative number if x is considered to be less than y,
# a positive number if x is considered to be greater than y, or 0 if x is considered to be equal to y.
#
def next_permutation_comp(arr, comp):
	# Find non-increasing suffix
	i = len(arr) - 1
	while i > 0 and comp(arr[i - 1], arr[i]) >= 0:
		i -= 1
	if i <= 0:
		return False

	# Find successor to pivot
	j = len(arr) - 1
	while comp(arr[j], arr[i - 1]) <= 0:
		j -= 1
	arr[i - 1], arr[j] = arr[j], arr[i - 1]

	# Reverse suffix
	arr[i : ] = arr[len(arr) - 1 : i - 1 : -1]
	return True
