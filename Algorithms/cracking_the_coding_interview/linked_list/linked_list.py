# -*- coding: UTF-8 -*-

from __future__ import print_function


class Node(object):
	'''Represent a single node in a linked list'''

	def __init__(self, data, nextnode=None):
		self.data = data
		self.nextnode = nextnode


class LinkedList(object):
	'''Represent a linked list'''

	def __init__(self, head=None):
		self.head = head
	
	def insert(self, data):
		'''Inserts an element in a linked list'''

		node = Node(data, None)

		if self.head == None:
			self.head = node

		else:

			node.nextnode = self.head
			self.head = node

	def delete_at_position(self, position):
		'''Deletes a node at a particular position in linked list'''

		if head == None:
			raise ValueError("Linked list is empty")

		index = 0
		current = self.head

		while (index < position-1 and current.nextnode):
			current = current.nextnode
			index += 1

		if not current.nextnode:
			# TODO: Do proper exception handline in Python
			return "Linked list index out of range"

		current.nextnode = current.nextnode.nextnode

	def get_size(self):
		'''Get the size of the linked list'''
		count = 0
		current = self.head
		while current:
			count += 1
			current = current.nextnode

		return count

	def is_empty(self):
		'''Check if the linked list is empty'''

		if not self.head:
			return True

		return False

	def print_list(self):
		'''Print the elements in a linked list'''

		if not self.head:
			raise ValueError("List is empty")

		current = self.head
		while current:
			print(current.data, end=" ")
			current = current.nextnode

		print ("\n")


def initialize_linked_list():
	'''Initialize a linked list and insert the following elements in the linked list'''
	'''4, 5, 13, 6, 9, 41, 8, 4, 33'''
	lList = LinkedList()
	lList.insert(4)
	lList.insert(5)
	lList.insert(13)
	lList.insert(6)
	lList.insert(9)
	lList.insert(41)
	lList.insert(8)
	lList.insert(4)
	lList.insert(33)

	return lList

if __name__ == "__main__":
	initialize_linked_list()
