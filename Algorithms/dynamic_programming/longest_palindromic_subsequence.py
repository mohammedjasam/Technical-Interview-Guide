# -*- coding: UTF-8 -*-

# Longest Palindromic subsequence

'''
	Given a sequence, find the length of the longest palindromic subsequence in it. 

	For example, if the given sequence is “BBABCBCAB”, then the output should be 7 as “BABCBAB” is the longest 
	palindromic subseuqnce in it. 

	“BBBBB” and “BBCBB” are also palindromic subsequences of the given sequence, but not the longest ones.
'''

# Time Complexity: O(2^n) as there are 2^n possible subsequences
def longest_palindrome(sequence, i, j):
	'''Calculate longest palindromic subsequence using recursion'''
	if i > j:
		return 0
	
	# When the length of palindrome is odd and i == j
	if i == j:
		return 1
	
	# When the palindrome is even length and both the elements at i and j are equal
	if i+1 == j and sequence[i] == sequence[j]:
		return 2

	# If elements at i and j are equal
	elif sequence[i] == sequence[j]:
		return longest_palindrome(sequence, i+1, j-1) + 2

	else:
		return max(longest_palindrome(sequence, i+1, j), longest_palindrome(sequence, i, j-1))

# Time Complexity: O(n*n)
def longest_palindrome_dynamic(sequence, length):
	'''Calculate longest palindromic subsequence using dynamic programming'''
	soln = [[0] * (length) for i in range(length)]
	
	# When subsequence is of length 1
	for i in range(len(sequence)):
		soln[i][i] = 1

	# Subsequence will start from 2 to length
	for i in range(2, length+1):
		for j in range(0, length-i+1):
			k = j+i-1

			if i == 2 and sequence[j] == sequence[k]:
				soln[j][k] = 2

			elif sequence[j] == sequence[k]:
				soln[j][k] = soln[j+1][k-1] + 2

			else:
				soln[j][k] = max(soln[j][k-1], soln[j+1][k])

	return soln[0][len(sequence)-1]	

import unittest

class MyTest(unittest.TestCase):
	def setUp(self):
		self.sequence = "BBAAB"
		self.length = len(self.sequence)
	
	def test_longest_palindrome(self):
		self.assertEqual(longest_palindrome(self.sequence, 0, self.length-1), 4)

	def test_longest_palindrome_dynamic(self):
		self.assertEqual(longest_palindrome_dynamic(self.sequence, self.length), 4)

if __name__ == "__main__":
	unittest.main()
