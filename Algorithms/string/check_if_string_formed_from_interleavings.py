# -*- coding: UTF-8 -*-

# Program to Check if a string is formed by interleaving of two strings

def check(str, str1, str2, m, n, i):

	if m == 0 and n == 0 and i == 0:
		return True
	else:
		if m > 0 and i > 0 and str[0] == str1[0]:
			return check(str[1:], str1[1:], str2, m-1, n, i-1)

		elif n > 0 and i > 0 and str[0] == str2[0]:
			return check(str[1:], str1, str2[1:], m, n-1, i-1)

		else:
			return False

a = list("CABD")
b = list("AB")
c = list("CD")

print check(a, b, c, len(b), len(c), len(a))

