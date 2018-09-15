# -*- coding: UTF-8 -*-

# Program to initialize linked list
import linked_list as ll

# Initialize the following linked listaz
# 4 -> 5 -> 13 -> 6 -> 9 -> 41 -> 8 -> 27 -> 33
def initialize_linked_list():
	lList = ll.LinkedList()
	lList.insert(4)
	lList.insert(5)
	lList.insert(13)
	lList.insert(6)
	lList.insert(9)
	lList.insert(41)
	lList.insert(8)
	lList.insert(4)
	lList.insert(33)

	lList.print_list()
	return lList

# Initialize a linked list by taking elements from an array
def initialize_linked_list_by_array(elements):

	lList = ll.LinkedList()


	for element in elements:
		lList.insert(element)

	lList.print_list()

	return lList.head
