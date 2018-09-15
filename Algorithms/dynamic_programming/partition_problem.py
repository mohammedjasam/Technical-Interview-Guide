# -*- coding: UTF-8 -*-

# Partition Problem

# Recursive implementation
def partition_problem(arr, index, sum_val):

	if sum_val == 0:
		return True

	if index == 0 and sum_val != 0:
		return False

	if arr[index] > sum_val:
		return partition_problem(arr, index-1, sum_val)

	else:
		return partition_problem(arr, index-1, sum_val-arr[index]) or partition_problem(arr, index-1, sum_val)


# Dynammic Programming Implementation
def partition_problem_dynamic(arr, sum_val):

	n = len(arr)
	soln = []

	for i in range(n+1):
		soln.append([None]*(sum_val+1))

	# When sum value is empty
	for i in range(n+1):
		soln[i][0] = True

	# When arr index is 0
	for j in range(1, sum_val+1):
		soln[0][j] = False

	for i in range(1, n+1):
		for j in range(1, sum_val+1):
			if arr[i-1] > j:
				soln[i][j] = soln[i-1][j]

			else:
				soln[i][j] = soln[i-1][j-arr[i-1]] or soln[i-1][j]

	return soln[n][sum_val]


a = [1, 5, 10]

sum_val = sum(a)

if sum_val % 2 == 1:
	print False
else:
	print partition_problem(a, len(a)-1, sum_val/2)
	print "Solving by DP"
	print partition_problem_dynamic(a, sum_val/2)