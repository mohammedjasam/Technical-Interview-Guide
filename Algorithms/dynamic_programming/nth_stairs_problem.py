# -*- coding: UTF-8 -*-

# nth stairs problem

# Recursive implementation
def n_stairs(N):
	if N == 0 or N == 1 or N == 2: 
		return N

	else:
		return n_stairs(N-1) +	n_stairs(N-2)

# Implementation through Dynamic Programming
def n_stairs_dynamic(N):
	soln = [-1] * N

	soln[0] = 1
	soln[1] = 2

	for i in range(2, N):
		soln[i] = soln[i-1] + soln[i-2]

	return soln[N-1]

if __name__ == "__main__":
	N = 4
	print n_stairs(4)
	print n_stairs_dynamic(N)
