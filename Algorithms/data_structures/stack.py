# -*- coding: UTF-8 -*-

''' 
	Problem: Implement stack in python

	Stack: A stack is a data structure which stores elements in a linear fashion such that each element is added and
	removed from the top of the stack.

'''

class Node(object):

	def __init__(self, data, nextnode=None):
		self.data = data
		self.nextnode = nextnode

class Stack(object):

	def __init__(self):
		self.top = None

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
			self.top = node

		else:
			temp = self.top
			self.top = node
			self.top.nextnode = temp

	def pop(self):
		'''
			Function to delete an element from the top of the stack
		'''
		if self.top is None:
			raise ValueError("Stack is empty")

		else:
			print self.top.data, "is deleted"
			self.top = self.top.nextnode


	def peek(self):
		'''
			Function to get the top of the stack
		'''
		if self.top is None:
			raise ValueError("Stack is empty")

		else:
			return (self.top.data)
