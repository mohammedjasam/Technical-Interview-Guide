# coding: UTF-8

'''
	Problem:  You have two numbers represented by a linked list, where each node contains a single digit. The digits are 
	stored in reverse order, such that the 1's digit is at the head of the list. Write a function that adds the two 
	numbers and return the sum as a linked list. 

	Input: (7 -> 1 -> 6) + (5 -> 9 -> 2). That is 617 + 295
	Output: 2 -> 1 -> 9 That is, 912
'''
from __future__ import print_function

class Node(object):
	'''Represent a single node in a linked list'''

	def __init__(self, data, nextnode=None):
		self.data = data
		self.nextnode = nextnode


class LinkedList(object):
	'''Represent a linked list'''

	def __init__(self, head=None, end=None):
		self.head = head
		self.end = end

	def insert(self, data):
		'''Insert a node at the end of the linked lsit'''
		node = Node(data)

		if self.head is None:
			self.head = node
			self.end = node
		else:
			self.end.nextnode = node
			self.end = self.end.nextnode

	def print_list(self):
		'''Print the elements in a linked list'''

		if not self.head:
			raise ValueError("List is empty")

		current = self.head
		while current:
			print(current.data, end=" ")
			current = current.nextnode

		print ("\n")

def sum_two_numbers(linked_list1, linked_list2):
	'''Calculate the sum of linked list''' 

	carry = 0
	new_linked_list = LinkedList()

	while(linked_list1 != None or linked_list2 != None):
		sum = 0
		if (linked_list1 != None):
			sum += linked_list1.data

		if (linked_list2 != None):
			sum += linked_list2.data

		if carry:
			sum += carry

		carry = sum / 10

		new_linked_list.insert(sum % 10)
		
		linked_list1 = linked_list1.nextnode
		linked_list2 = linked_list2.nextnode

	if carry:
		new_linked_list.insert(carry)

	return new_linked_list

if __name__ == "__main__":
	# Initializing linked list 1 number (617)
	linked_list1 = LinkedList()
	linked_list1.insert(7)
	linked_list1.insert(1)
	linked_list1.insert(6)
	linked_list1.print_list()

	# Initializing linked list 2 number(295)
	linked_list2 = LinkedList()
	linked_list2.insert(5)
	linked_list2.insert(9)
	linked_list2.insert(2)
	linked_list2.print_list()

	new_linked_list = sum_two_numbers(linked_list1.head, linked_list2.head)

	print ("Sum of two numbers")
	new_linked_list.print_list()
