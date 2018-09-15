# -*- coding: UTF-8 -*-

# Palindrome partitioning

import sys

# Function to check if a string is palindrome or not
def is_palindrome(string, st_in, end_in):

	if st_in == end_in:
		return True

	if string[st_in] == string[end_in] and is_palindrome(string, st_in+1, end_in-1):
		return True

	else:
		return False

# Recursive approach
def palindromic_partitioning(string, st_in, end_in):
	if st_in == end_in:
		return 0

	if is_palindrome(string, st_in, end_in):
		return 0

	else:
		minimum = sys.maxint
		for i in range(st_in, end_in):
			res = palindromic_partitioning(string, st_in, i) + 1 + palindromic_partitioning(string, i+1, end_in)

			if res < minimum:
				minimum = res

		return minimum

# Dynamic Programming approach
def palindromic_partitioning_dynamic(string):
	n = len(string)

	C = []
	P = []
	for i in range(n):
		C.append([None]*n)
		P.append([None]*n)

	for i in range(n):
		C[i][i] = 0
		P[i][i] = True

	for L in range(2, n+1):
		for i in range(n-L+1):
			j = i+L-1
			if L == 2:
				P[i][j] = (string[i] == string[j])
			else:
				P[i][j] = (string[i] == string[j]) and P[i+1][j-1]

			if P[i][j]:
				C[i][j] = 0
			else:				
				C[i][j] = sys.maxint
				for k in range(i, j):
					res = C[i][k] + C[k+1][j] + 1
					if res < C[i][j]:
						C[i][j] = res

	return C[0][n-1]

a = "ababbbabbababa"
print palindromic_partitioning(a, 0, len(a)-1)
print "Solving by DP"
print palindromic_partitioning_dynamic(a)
