# coding: UTF-8

'''
	Problem: Write a code to partition a linked list around a value x, such that all nodes less than x comes before all nodes greater
	than or equal to x. If x is contained within a ist, the values of x only need to be after the elements less than x. The element 
	x can appear anywhere in the "right partition", it does not need to appear between the left and right partitions.

	Input: 3 -> 5 -> 8 -> 5 -> 10 -> 2 -> 1 [partition=5]
	Output: 3 -> 1 -> 2 -> 10 -> 5 -> 5 -> 8 
'''

from __future__ import print_function

class Node(object):
	'''Represent a single node in a linked list'''

	def __init__(self, data, nextnode=None):
		self.data = data
		self.nextnode = nextnode


class LinkedList(object):
	'''Represent a linked list'''

	def __init__(self, head=None, tail=None):
		self.head = head
		self.tail = tail
	
	def insert_head(self, data):
		'''Inserts an element at the head in a linked list'''

		node = Node(data, None)

		if self.head == None:
			self.head = node

		else:

			node.nextnode = self.head
			self.head = node

	def insert_tail(self, data):
		'''Insert an element at the tail in a linked list'''

		node = Node(data, None)

		if self.head == None:
			self.head = node
			self.tail = node
		else:
			self.tail.nextnode = node
			self.tail = self.tail.nextnode

	def print_list(self):
		'''Print the elements in a linked list'''

		if not self.head:
			raise ValueError("List is empty")

		current = self.head
		while current:
			print(current.data, end=" ")
			current = current.nextnode

		print ("\n")

def partition(head, k):
	'''Partition the linked list on number k'''

	current = head
	linked_list = LinkedList()

	while(current != None):
		if current.data >= k:
			linked_list.insert_tail(current.data)

		else:
			linked_list.insert_head(current.data)

		current = current.nextnode

	linked_list.print_list()

if __name__ == "__main__":
	import linked_list
	llist = linked_list.initialize_linked_list()
	llist.print_list()

	partition(llist.head, 13)
