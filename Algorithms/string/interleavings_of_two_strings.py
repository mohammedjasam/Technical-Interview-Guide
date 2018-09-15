# -*- coding: UTF-8 -*-

# Program to print all interleavings of two strings

def print_all_interleavings(str1, str2, str, m, n, i):

	if m == 0 and n == 0:
		print "".join(str)

	else:

		if m != 0:
			str[i] = str1[0]
			print_all_interleavings(str1[1:], str2, str, m-1, n, i+1)

		if n != 0:
			str[i] = str2[0]
			print_all_interleavings(str1, str2[1:], str, m, n-1, i+1)


a = "AB"
b = "CDE"

c = [""] * (len(a)+len(b))

print_all_interleavings(list(a), list(b), c, len(a), len(b), 0)