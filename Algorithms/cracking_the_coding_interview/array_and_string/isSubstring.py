# -*- coding: UTF-8 -*-

'''

	Problem: Program to check if one word is a substring of another. If you have two strings s1 and s2, write code to check 
	if s2 is a rotation of s1 using only one call to isSubstring. 

	example: hoolahoop is a rotation of "lahoophoo"
			oophoolah
'''

'''
	Naive approach: Compare each character of the first string with the first character pf the second string.
	Whenever it matches then rotate the first string and compare the two strings. If the two strings are same then one
	is rotation of another.

	Time Complexity: O(n) We will have to concatenate string which is inefficient.
'''

def string_rotation(s1, s2):

	length1 = len(s1)
	length2 = len(s2)

	if length1 != length2:
		return False

	for index in range(length1):
		if s1[index] == s2[0]:
			new_string = s1[index: length1] + s1[:index]
			if new_string == s2:
				return True

	return False

'''
	Approach 2: Add the second string to the same string and then find the first string in the second string. If you can
	find it, then it is a substring otherwise not. The criteria is s1 is always a substring of s2s2.

	Time Complexity: O(n) where n is the length of the string.

'''
def isSubstring(s1, s2):

	s2s2 = s2 + s2

	# in checks if one string is part of another.
	if s1 in s2s2:
		return True

	else:
		return False


# Writing unit-test for the above function
import unittest

class MyTest(unittest.TestCase):

	def test(self):
		self.assertEqual(string_rotation("hoolahoop", "lahoophoo"), True)
		self.assertEqual(string_rotation("waterbottle", "erbottlewat"), True)

unittest.main()
