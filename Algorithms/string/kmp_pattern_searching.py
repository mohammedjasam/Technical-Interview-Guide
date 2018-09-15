# -*- coding: UTF-8 -*-

# KMP algorithm to search for pattern in a string

def KMPSearch(pattern, text):

	lps = computeLPS(pattern)

	i = 0
	j = 0
	while i < len(text):
		if pattern[j] == text[i]:
			i += 1
			j += 1

		if j == len(pattern):
			print "Pattern found at %s"%str(i-j)
			j = lps[j-1]

		elif i < len(text) and pattern[j] != text[i]:
			if j != 0:
				j = lps[j-1]
			else:
				i += 1

# Compute longest proper suffix for pattern
def computeLPS(pattern):

	lps = [0]*len(pattern)

	lps[0] = 0
	i = 1
	l = 0

	while i < len(pattern):
		if pattern[i] == pattern[l]:
			l += 1
			lps[i] = l
			i += 1

		else:
			if l != 0:
				l = lps[l-1]

			else:
				lps[i] = 0
				i += 1

	return lps

S = "AABAACAADAABAAABAA"
P = "AABA"

KMPSearch(P, S)