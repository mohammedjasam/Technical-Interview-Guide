# -*- coding: UTF-8 -*-

# Program to calculate edit distance between two strings

# Recursive solution to implement edit distance
def edit_distance(str1, str2, m, n):
	if m == 0 and n == 0:
		return 0
	if m == 0:
		return n
	if n == 0:
		return m

	left = edit_distance(str1, str2, m-1, n) + 1
	right = edit_distance(str1, str2, m, n-1) + 1

	corner = edit_distance(str1, str2, m-1, n-1) + (str1[m-1] != str2[n-1])

	return min(left, min(right, corner))

a = list("abc")
b = list("abcd")
print edit_distance(a, b, len(a), len(b))