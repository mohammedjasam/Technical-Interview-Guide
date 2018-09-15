# -*- coding: UTF-8 -*-

'''
	Given a text txt[0..n-1] and a pattern pat[0..m-1], write a function search(char pat[], char txt[]) that prints
	all occurrences of pat[] in txt[]. You may assume that n > m.
'''


def genertate_lps(pattern):
	lps = [0] * len(pattern)
	m = len(pattern)
	i = 1
	length = 0
	while (i < m):
		if pattern[i] == pattern[length]:
			length += 1
			lps[i] = length
			i += 1

		else:
			if length:
				length = lps[length-1]
			else:
				lps[i] = 0
				i += 1

	return lps

def match_pattern(pattern, txt):

		lps = genertate_lps(pattern)
		pattern_length = len(pattern)
		txt_length = len(txt)
		i = 0
		j = 0
		while(i < txt_length):
			if j < pattern_length and pattern[j] == txt[i]:
				j += 1
				i += 1

			if j == pattern_length:
				print "Pattern matched at index ", i-j
				j = lps[j-1]

			elif i < txt_length and pattern[j] != txt[i]:
				if j != 0:
					j = lps[j-1]
				else:
					i = i+1 

def test_kmp():
	txt = "AAAAABAAABA" 
	pattern = "AAAA"

	match_pattern(pattern, txt)

if __name__ == "__main__":
	test_kmp()