# -*- coding: UTF-8 -*-

'''

   Problem: Implement an algorithm to determine if a string has all unique characters. 

'''
   

'''
   Naive Approach: Loop through each character in the string and check in the entire string if that character is present. 
   If even one such character found, 
   return False.

   Time complexity: O(n*2) where n is the length of the string.    

'''
def is_unique(s):

   length = len(s)

   for a in range(length):
      for b in range(a+1, length):
         if s[a] == s[b]:
            return False

   # When string has all unique characters
   return True

'''
   Approach 2: Sort the string first and loop over the string and compare each character with its next character, if 
   there is one such character, it returns false. 

   Time complexity: Sorting O(n*logn) and looping over string O(n). So the complexity will come down to O(n*logn)
'''

def check_is_unique(s):

   # Calling inbuilt sort function in Python
   s = sorted(s)

   length = len(s)
   for i in range(length-1):
      for j in range(i+1, length):
         # Comparing each element with its next element
         if s[i] == s[j]:
            return False

   return True


'''
   Approach 3: Store each character in a hash_map with key as each character and if any character is already found in 
   hash_map return false.

   Time complexity: O(n) to loop over string
   Space Complexity: O(n) to store n characters 

'''
def unique_character_string(s):

	# Declaring hash_map using python dictionaries
	hash_map = {}

	for letter in s:
		if letter in hash_map:
			return False
		else:
			hash_map[letter] = True

	return True

''' 
   Approach 4: Using sets and checking is the len of the set is equal to the original length. If they are equal, then
   the string contains unique characters.
'''

def is_unique_string(s):

   return len(set(s)) == len(s)

'''
   Approach 5: Considering the string characters belong to ascii letters, we will create a list which stores the ascii characters 
   and a frequency list to store the frequency of each letter. 
'''

def is_unique_string_ascii(s):
   '''Returns true if a string contains all unique characters and false if not'''
   import string
   characters = list(string.ascii_letters)
   frequencies = [(c, 0) for c in characters]

   for letter in s:
      index = characters.index(letter)
      if frequencies[index][1] == 1:
         return False
      else:
         frequencies[index] = (letter, frequencies[index][1]+1)

   return True

# Writing unit-test for this function
import unittest

class MyTest(unittest.TestCase):

   def test(self):
      # Unit test for Approach 1
      self.assertEqual(is_unique("paledr"), True)
      self.assertEqual(is_unique("abcdfrea"), False)
      # Unit test for approach 2
      self.assertEqual(check_is_unique("palednsp"), False)
      self.assertEqual(check_is_unique("paleldnas"), False)
      # Unit test for approach 3
      self.assertEqual(unique_character_string("palesarthd"), False)
      self.assertEqual(unique_character_string("palesarthds"), False)

      self.assertEqual(is_unique_string("palesarthd"), False)
      self.assertEqual(is_unique_string("palesrthd"), True)

      self.assertEqual(is_unique_string_ascii("palesarthd"), False)
      self.assertEqual(is_unique_string_ascii("palesrthd"), True)

unittest.main()
