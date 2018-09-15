# -*- coding: UTF-8 -*-

''' 
	Problem: Implement a stack such that it returns the minimum element in stack. All the operations such as push, pop 
	and min operates in O(1) time. 

	Stack: A stack is a data structure which stores elements in a linear fashion such that each element is added and
	removed from the top of the stack.

'''

class Node(object):

	def __init__(self, data):
		self.data = data
		self.nextnode = None
		self.substack_min = None

class Stack(object):

	def __init__(self):
		self.top = None
		self.min = None

	def is_empty(self):
		'''
			Function to check if the stack is empty
		'''
		if self.top is None:
			return True

		return False

	def push(self, data):
		'''
			Function to insert an element to the top of a stack
		'''
		node = Node(data=data)

		if self.top is None:
			# Update the substack min with the top node
			node.substack_min = node
			self.top = node
			self.min = self.top

		else:
			temp = self.top
			self.top = node
			self.top.nextnode = temp
			# Each node will have the current min in their substack min
			node.substack_min = self.min

			if data < self.min.data:
				# If the current top data is less than the current min, then min is changed to the current top
				self.min = self.top

	def pop(self):
		'''
			Function to delete an element from the top of the stack
		'''
		if self.top is None:
			raise ValueError("Stack is empty")

		else:
			# If the min is popped, the the new min will be substack min of the current min value
			if (self.top == self.min):
				self.min = self.top.substack_min

			self.top = self.top.nextnode

	def get_min(self):
		if self.min is None:
			raise ValueError("Stack is empty")

		print self.min.data

	def peek(self):
		'''
			Function to get the top of the stack
		'''
		if self.top is None:
			raise ValueError("Stack is empty")

		else:
			print (self.top.data)
