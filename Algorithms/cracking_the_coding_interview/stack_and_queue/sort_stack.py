# -*- coding: UTF-8 -*-

'''
	Problem: Implement a program to sort a stack such that smallest items are on the top. 

	Solution: Insert each element in a sorted way. One stack will keep the sorted elements. When a new element is to be
	inserted, all the elements less than that element are popped and pushed to the second stack. Then this element is pushed
	and all the popped elements are pushed back.

'''

from stack import Stack

class SortStack(object):

	def __init__(self):
		self.stack1 = Stack()
		self.stack2 = Stack()

	def push(self, data):
		'''
			Function to insert element in an sorted stack
		'''

		if not self.stack1.is_empty():
			while(not self.stack1.is_empty() and self.stack1.peek() < data):
				top = self.stack1.peek()
				self.stack1.pop()
				self.stack2.push(top)

		self.stack1.push(data)

		if not self.stack2.is_empty():
			while(not self.stack2.is_empty()):
				top = self.stack2.peek()
				self.stack2.pop()
				self.stack1.push(top)

	def pop(self):
		'''
			Function to pop element from the sorted stack
		'''
		if self.stack1.is_empty():
			raise ValueError("Stack is empty")

		self.stack1.pop()

	def is_empty(self):
		''' 
			Function to check if the sorted stack is empty
		'''
		if self.stack1.is_empty():
			return True

		return False
