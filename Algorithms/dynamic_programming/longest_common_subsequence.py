# -*- coding: UTF-8 -*-

# Longest common subsequence

'''
	Problem: Given two sequences, find the length of longest subsequence present in both of them.

	We can solve this problem by finding all the subsequences of both given sequences and find the longest matching
	subsequence.

	Complexity: Exponential as there are (2 ^ n) possible subsequences of a given sequence and to compare
	them you will have to loop through all the subsequences of both the sequences.

	Optimal Substructure: Let's s1 and s2 are the two sequence. If the first letter of both sequence is same, then the
	problem can be written as LCS(s1, s2) = LCS(s1[1:], s2[1:]) + 1 otherwise it will be
	LCS(s1, s2) = max(LCS(s1[1:], s2), LCS(s1, s2[1:])).
'''

# Time complexity: Exponential O(2 ^ n)
def longest_common_subsequence(s1, s2):
	''' Return length of longest common subsequence using recursion'''
	if len(s1) == 0 or len(s2) == 0:
		return  0

	if s1[0] == s2[0]:
		return longest_common_subsequence(s1[1:], s2[1:]) + 1

	else:
		return max(longest_common_subsequence(s1[1:], s2), longest_common_subsequence(s1, s2[1:]))

# Time complexity: O(m * n) where m is length of string 1 and n is length of string 2
def longest_common_subsequence_dynamic(s1, s2):
	''' Dynamic Programming approach to find the length of longest common subsequence'''
	m = len(s1)
	n = len(s2)

	soln = [[0] * (n+1) for i in range(m+1)]
	for i in range(1, m+1):
		for j in range(1, n+1):
			if s1[i-1] == s2[j-1]:
				soln[i][j] = soln[i-1][j-1] + 1
			else:
				soln[i][j] = max(soln[i-1][j], soln[i][j-1])

	return soln[m][n]

import unittest

class MyTest(unittest.TestCase):
	def setUp(self):
		self.str1 = "AGGTAB"
		self.str2 = "GXTXAYB"

	def test_lcs_recursive(self):
		self.assertEqual(longest_common_subsequence(self.str1, self.str2), 4)

	def test_lcs_dynamic(self):
		self.assertEqual(longest_common_subsequence_dynamic(self.str1, self.str2), 4)

if __name__ == "__main__":
	unittest.main()
