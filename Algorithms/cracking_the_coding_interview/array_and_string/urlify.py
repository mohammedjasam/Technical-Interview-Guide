'''

	Problem: Write a program to replace all spaces in a string with "%20". Assuming that string has sufficicient space at the end to hold additional 
	characters, you are given true length of the string.

	Example: "Mr John Smith    ", 13
	Output: "Mr%20John%20Smith"

'''

'''
	Approach 1: Append the letters of the string in a list and when space is found append "%20".

	Complexity: O(n)

'''
def urlify(s,length):

	count = 0
	# list is dynamic in python.
	new_string = []

	while (count < length):
		if s[count] == " ":
			new_string.append("%")
			new_string.append("2")
			new_string.append("0")

		else:
			new_string.append(s[count])
			
		count += 1

	return ''.join(new_string)


'''
	Approach 2: First calculate the number of spaces to be replaced. 
				Initialize a list of new_length of the substituted string and substitute the elements starting backward. 
				In this approach we are not using the dynamic property of the list and initializing its length by 
				pre-calculating the length of the new string. 

	Complexity: O(n)
'''

def urlify_2(s, length):

	substitue_string = "%20"
	
	count = 0
	for index in range(length):
		if s[index] == ' ':
			count += 1

	print count

	# Initialize the length of the new string
	new_length = length + (count * 2)
	# Initialize the new string of lenth new_length
	new_string = [None] * new_length

	# Initialize the index at which we start substituting element
	new_index = new_length - 1

	# Index of the original string
	index = length - 1
	

	while (index >= 0):
		# print new_string
		if s[index] == ' ':
			for i in range(3):
				new_string[new_index] = substitue_string[2-i]
				new_index -= 1

		else:
			new_string[new_index] = s[index]
			new_index -= 1

		index -= 1

	return ''.join(new_string)

# Writing unit-test for the above function
import unittest

class MyTest(unittest.TestCase):

	def test(self):
		self.assertEqual(urlify("Mr John Smith    ", 13), "Mr%20John%20Smith")
		self.assertEqual(urlify_2("Mr John Smith    ", 13), "Mr%20John%20Smith")

unittest.main()
