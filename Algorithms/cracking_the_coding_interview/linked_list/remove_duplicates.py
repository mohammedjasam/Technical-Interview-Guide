# -*- coding: UTF-8 -*-

'''
	Problem: Implement a program to remove duplicates elements from an unsorted linked list
	
	Example: 2 -> 1 -> 7 -> 2 -> 9 -> 1 -> 8 
	Result: 2 -> 1 -> 7 -> 9 -> 8

	Approach 1: Iterate through each element in a linked list and look for the same element in the list ahead. 
	If found, delete that element. 

	Time Complexity: O(n * n)

	Approach 2: Store the elements in a hash-map and if next time the same element is encountered, delete it. 

	Time Complexity: O(n) Space Complexity: O(n)
'''

import linked_list

def remove_duplicates(head):
	''' Remove duplicates using hash map '''
	hash_map = {}
	current = head
	prev = None

	while (current):
		if current.data in hash_map:
			prev.nextnode = current.nextnode

		else:
			hash_map[current.data] = 1

		prev = current
		current = current.nextnode


# Writing unit-test for the above function
# import unittest

# class MyTest(unittest.TestCase):

# 	def test(self):
# 		lList = linked_list.initialize_linked_list()
# 		lList.print_list()
# 		# self.assertEqual(string_rotation("hoolahoop", "lahoophoo"), True)
# 		# self.assertEqual(string_rotation("waterbottle", "erbottlewat"), True)

# unittest.main()

lList = linked_list.initialize_linked_list()
lList.print_list()