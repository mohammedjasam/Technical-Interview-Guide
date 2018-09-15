# -*- coding: UTF-8 -*-

# Edit distance 

''' 
	Given two strings of size m, n and set of operations replace (R), insert (I) and delete (D) all at equal cost. Find minimum 
	number of edits (operations) required to convert one string into another.

	Time Complexity(Recursive): Worst case time-complexity of recursive solution can be O(3^m)

	Time Complexity(Dynamic): Worst case time-complexity of dynamic solution can be O(m*n)
'''
import sys

def edit_distance(s1, s2):
	''' Recursively find the minimum edit distance to convert string s1 to string s2'''
	if len(s1) == 0 and len(s2) == 0:
		return 0

	if len(s1) == 0:
		return len(s2)

	if len(s2) == 0:
		return len(s1)

	if s1[0] == s2[0]:
		return edit_distance(s1[1:], s2[1:])

	else:
		# If the first letters of two strings is not same, then we calculate the minimum edit distance in
		# Insertion, Deletion or edit
		return min(edit_distance(s1, s2[1:]), edit_distance(s1[1:], s2), edit_distance(s1[1:], s2[1:])) + 1

def edit_distance_dynamic(s1, s2):
	m = len(s1)
	n = len(s2)
	sol = [[sys.maxint] * (n+1) for i in range(m+1)]

	for i in range(m+1):
		for j in range(n+1):
			if i == 0 and j == 0:
				sol[i][j] = 0

			# When string s1 is of length 0, then it will insert all the letters of string s2
			elif i == 0:
				sol[i][j] = j

			# If string s2 is of length 0, then it will delete all the letters of string s1
			elif j == 0:
				sol[i][j] = i

			# If both the letters are same, then it will be same as previous edit distance. 
			elif s1[i-1] == s2[j-1]:
				sol[i][j] = sol[i-1][j-1]
			
			else:
				# insertion, deletion and editing
				sol[i][j] = min(sol[i][j-1], sol[i-1][j], sol[i-1][j-1]) + 1

	return sol[m][n]  

import unittest

class MyTest(unittest.TestCase):
	def setUp(self):
		self.str1 = "SUNR"
		self.str2 = "SUNUE"
	
	def test_edit_distance_recursive(self):
		self.assertEqual(edit_distance(self.str1, self.str2), 2)

	def test_edit_distance_dynamic(self):
		self.assertEqual(edit_distance_dynamic(self.str1, self.str2), 2)

if __name__ == "__main__":
	unittest.main()
