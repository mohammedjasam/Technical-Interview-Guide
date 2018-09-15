# -*- coding: UTF-8 -*-

'''
	Problem: A child is running up the staircase with n steps and can hop either 1 step, 2 steps, or 3 steps at a time.
	Implement a method to count how many possible ways the child can run up the stairs.
'''

def step_recursive(n):
	''' Recursive solution to count the possible ways to run up the stairs '''
	if n < 0:
		return 0

	if n == 0:
		return 1
	
	else:
		return step_recursive(n-1) + step_recursive(n-2) + step_recursive(n-3)

def step_dynamic(n):
	'''Count the number of ways to take n steps usng dynamic programming'''
	soln = [0] * (n+1)
	soln[0] = 1
	
	for i in range(1, n+1):
		if i >= 1:
			soln[i] += soln[i-1]
		if i >= 2:
			soln[i] += soln[i-2]
		if i >= 3:
			soln[i] += soln[i-3]

	return soln[n]

if __name__ == "__main__":
	print "Counting possible ways using recursion"
	print step_recursive(4)
	print step_recursive(5)
	print step_recursive(6)
	print "Counting possible ways using dynamic programming"
	print step_dynamic(4)
	print step_dynamic(5)
	print step_dynamic(6)
