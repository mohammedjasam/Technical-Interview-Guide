# -*- coding: UTF-8 -*-

'''

	Problem: Implement a method to perform basic string compression using the counts of repeated characters.

	example: aabcccccaaa -> a2b1c5a3
			 aabcbaah -> aabcbaah

	If the compressed string is not smaller than the original string, return the original string.

	Solution: Iterate through the string, if the next word is equal to the previous word, increase the count, if not equal then
	append the word and count to the list(dynamic array) and reset the count to 1. Join the list. If the resulting string is 
	smaller than the original, return the new string otherwise return the original string.

	Time Complexity: O(n)
	Space Complexity: O(n)

'''

def string_compression(s):

	count = 1

	# Store strings in array rather then complex string concatenation
	new_string = [s[0]]

	for i in range(1, len(s)):
		if s[i] == s[i-1]:
			count += 1

		else:
			new_string.append(str(count))
			new_string.append(s[i])
			count = 1

	# after the string ends, add the count at the last
	new_string.append(str(count))

	if len(new_string) < len(s):
		return ''.join(new_string)

	else:
		return s


'''
	Optimization: In the above solution, it compresses the string first and then check for the length. This solution can 
	be further optimized by first calculating if the new string is smaller than the previous string, and compress only if it is
	smaller. It avoid us creating a string that we never use. Downside is we have to loop through the characters twice which has 
	nearly same duplicated code. 

	Complexity: O(n)

'''

def string_compression(s):

	new_string_length = 1

	for i in range(1, len(s)):

		if s[i] != s[i-1]:
			new_string_length += 1

	if new_string_length * 2 > len(s):
		return s
	else:
		return do_string_compression(s)


def do_string_compression(s):

	count = 1
	new_string = [s[0]]

	for i in range(1, len(s)):
		if s[i] == s[i-1]:
			count += 1

		else:
			new_string.append(str(count))
			new_string.append(s[i])
			count = 1

	# after the string ends, add the count at the last
	new_string.append(str(count))

	return ''.join(new_string)


# Writing unit-test for the above function
import unittest

class MyTest(unittest.TestCase):

	def test(self):
		self.assertEqual(string_compression("aabcbaah"), "aabcbaah")
		self.assertEqual(string_compression("aabcccccaaa"), "a2b1c5a3")

unittest.main()
