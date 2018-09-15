'''

	Problem: Three type of edits can be performed on a string: insert a character, remove a character or repcase a character. 
	Write a function to check if the two strings are one edit(or zero edit) away.

	Example: 
		pale, ple -> True
		pales, pale -> True
		pale, bale -> True
		pale, bake -> False

	Solution: Compare the length of the strings, if the length differs by 1, then compare for each letter, bigger string can 
	have only one extra letter. If the length are same, then compare for each letter, and only one letter can be different. 
	Otherwise return false.

	Complexity: O(n)
'''


def check_one_away(s1, s2):

	length1 = len(s1)
	length2 = len(s2)

	if length1 == length2:
		return check_for_same_length_strings(s1, s2, length1)

	# If string1 is smaller than string2 by one letter
	elif length1 + 1 == length2:
		# send the bigger string in first argument
		return check_for_one_extra_letter(s2, s1, length2)

	# IF string1 is bigger than string2 by one letter
	elif length1 == length2 + 1:
		# send the bigger string in first argument
		return check_for_one_extra_letter(s1, s2, length1)

	else:
		return False

def check_for_same_length_strings(s1, s2, length):

	flag = False
	count = 0

	while (count < length):
		if s1[count] != s2[count] and not flag:
			flag = True

		# If more than one letter are different, return False
		elif s1[count] != s2[count] and flag:
			return False

		count += 1

	return True


def check_for_one_extra_letter(s1, s2, length):

	flag = False
	count1 = 0
	count2 = 0

	while (count1 < length and count2 < length-1):

		# Make flasg true when only one character is found different
		if s1[count1] != s2[count2] and not flag:
			flag = True
			count1 += 1

		elif s1[count1] != s2[count2] and flag:
			return False
		
		else:
			count1 += 1
			count2 += 1

	return True

# Writing unit-test for this function
import unittest

class MyTest(unittest.TestCase):

	def test(self):
		self.assertEqual(check_one_away("pale", "ple"), True)
		self.assertEqual(check_one_away("pales", "pale"), True)
		self.assertEqual(check_one_away("pale", "bale"), True)
		self.assertEqual(check_one_away("pale", "bake"), False)

unittest.main()
