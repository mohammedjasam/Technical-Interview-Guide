# -*- coding: UTF-8 -*-

'''
	Given a text txt[0..n-1] and a pattern pat[0..m-1], write a function search(char pat[], char txt[]) that prints all 
	occurrences of pat[] in txt[]. You may assume that n > m.

	Worst case complexity: O(m * (n-m+1))
'''

def check_for_rest(txt, i, pattern):
	'''Check if the all the letters of the pattern are present in the txt starting at index i'''
	for j, s  in enumerate(pattern):
		if not txt[i+j] == s:
			return False

	return True

def search_pattern(str, pattern):
	'''Search for the pattern in the string and return all the positions where it is found'''
	found_at = []
	pattern_len = len(pattern)
	string_len = len(str)
	for i in range(string_len-pattern_len+1):
		# If first letter matches match the entire pattern 
		if str[i] == pattern[0]:
			if check_for_rest(str, i, pattern):
				found_at.append(i)

	return found_at


def pattern_test():

	txt = "AABAACAADAABAAABAA"
	pattern = "AABA"

	assert search_pattern(txt, pattern) == [0, 9, 13]

if __name__ == "__main__":
	pattern_test()