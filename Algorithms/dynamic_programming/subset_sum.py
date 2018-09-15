# -*- coding: UTF-8 -*-

# Subset sum problem

# Recursive implementation
def subset_sum(arr, sum_value):
	n = len(arr)

	if sum_value == 0:
		return True

	if n == 0  and sum_value != 0:
		return False

	if arr[n-1] > sum_value:
		return subset_sum(arr[0:-1], sum_value)

	else:
		return subset_sum(arr[0:-1], sum_value-arr[-1]) or subset_sum(arr[0:-1], sum_value)


# Dynammic Programming implementation
def subset_sum_dynamic(arr, sum_value):
	n = len(arr)

	soln = []

	for i in range(n+1):
		soln.append([None]*(sum_value+1))

	# when sum_value is empty
	for i in range(0, n+1):
		soln[i][0] = True

	for j in range(sum_value+1):
		soln[0][j] = False

	for i in range(1, n+1):
		for j in range(1, sum_value+1):
			if arr[i-1] > j:
				soln[i][j] = soln[i-1][j]

			else:
				soln[i][j] = soln[i-1][j] or soln[i-1][j-arr[i-1]]

	return soln[n][sum_value]


arr = [1, 5, 10]
sum_value = 8
print subset_sum(arr, sum_value)
print subset_sum_dynamic(arr, sum_value)