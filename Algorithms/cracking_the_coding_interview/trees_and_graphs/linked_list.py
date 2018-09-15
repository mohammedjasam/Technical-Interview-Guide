# -*- coding: UTF-8 -*-

from __future__ import print_function

'''
	Linked list is a dynamic linear data structure where each element is represented as an object.
	Each element is comprised of two items - the data and the reference to next element or next node.
'''

# Class to initialize a node for a linked list
class Node(object):
	def __init__(self, data):
		self.data = data
		self.nextnode = None

# Class to create a Linked List
class LinkedList(object):
	def __init__(self, head=None):
		self.head = head

	# Function to search an element in a linked list and print it's index
	def search(self, head, data, index):
		if head.data == data:
			print (index)
		else:
			# Search for the element by calling itself recursively
			if head.nextnode:
				return self.search(head.nextnode, data, index+1)
			else:
				raise ValueError("Node not in linked list")

	# Function to print all the nodes in a linked list starting from first node
	def print_list(self):
		if self.head == None:
			raise ValueError("List is empty")

		current = self.head 
		while(current):
			print (current.data, end="  ")
			current = current.nextnode
		print ('\n')

	# Function to get the length of the linked list
	def size(self):
		if self.head == None:
			return 0

		size = 0
		current = self.head
		while(current):
			size += 1
			current = current.nextnode

		return size

	# Function to insert a node in a linked list
	def insert(self, data):
		node = Node(data)
		if not self.head:
			self.head = node
		else:
			node.nextnode = self.head
			self.head = node

	# Function to delete a node in a linked list
	def delete(self, data):
		if not self.head:
			return
		
		temp = self.head
		
		# Check if head node is to be deteled
		if head.data == data:
			head = temp.nextnode
			print ("Deleted node is " + str(head.data))
			return

		while(temp.nextnode):
			if (temp.nextnode.data == data):
				print ("Node deleted is " + str(temp.nextnode.data))
				temp.nextnode = temp.nextnode.nextnode
				return
			temp = temp.nextnode
		print ("Node not found")
		return

