# -*- coding: UTF-8 -*-

# Maximum Length Chain of Pairs

def max_length_chain(arr, length):

	if length == 0:
		return 0

	if length == 1:
		return 1

	if length == 2:
		if arr[length-1][0] > arr[0][1]:
			return 2

		else:
			return 1

	else:
		return max(1+max_length_chain(arr, length-1), max_length_chain(arr, length-1))

def max_length_chain_dynamic(arr):

	length = len(arr)

	soln = [-1]*(length+1)
	soln[0] = 0
	soln[1] = 1
	soln[2] = 2 if arr[1][0] > arr[0][1] else 1
	for L in range(3, length+1):
		for i in range(L):
			if soln[L] < soln[i] + 1 and arr[L-1][1] > arr[i-1][0]:
				soln[L] = soln[i] + 1

	print soln[length]

arr = [[5, 24], [15, 25], [27, 40], [50, 60]]
print max_length_chain(arr, len(arr))
max_length_chain_dynamic(arr)

