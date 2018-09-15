# -*- coding: UTF-8 -*-

'''

	Problem: Given a string, check if it is a permutation of palindromic String. The palindrome does not 
	need to be limited to just dictionary words. 

	Input: Tact Coa
	Output: True (permuatations: "taco cat")
'''

'''
	Approach 1: Get all permutation of a string and check for each if its a palindrome or not

	Time Complexity: O(n!) where n is the length of the string
'''

# TODO: Write a program to get all the permutation of a string


'''

	Approach 2: Store all the characters of a string in a hash map and then check in the hash map if any two characters comes 
	odd number of times, return False

	Time Complexity: O(n) Space Complexity: O(n)
'''
def permuation_palindrome_string(s):

	# the upper-lower case letter will be treated same
	s = s.lower()
	# spaces in the string does not matter
	s = s.replace(" ", "")

	hash_map = {}

	for c in s:
		hash_map.setdefault(c, 0)
		hash_map[c] += 1

	flag = False
	for key, value in hash_map.iteritems():
		if flag and value % 2:
			return False

		if value % 2:
			flag = True
		

	return True

'''

	Any string of even length should have all even counts of characters in order to be a palindrome. A string of odd length should 
	have only one character with odd count. So we just need to make sure that there is only one such character. We can avoid one 
	loop in the above solution by counting the number of odd-even with each character value.

	Time Complexity: O(n) Space Complexity: O(n)
'''

def permutation_palindrome_string_2(s):

	# Consider upper and lower case characters as same
	s = s.lower()
	# Spaces are not considered
	s = s.replace(" ", "")

	hash_map = {}
	count_odd = 0

	for c in s:

		# Check and store in hash_map
		hash_map.setdefault(c, 0)
		hash_map[c] += 1

		# check for the count each time
		if hash_map[c] % 2:
			count_odd +=1
		else:
			count_odd -= 1

	if count_odd <= 1:
		return True

	return False

# Writing unit-test for the above function
import unittest

class MyTest(unittest.TestCase):

	def test(self):
		self.assertEqual(permuation_palindrome_string("Tact Coa"), True)
		self.assertEqual(permutation_palindrome_string_2("Tact Coa"), True)

unittest.main()
