# -*- coding: UTF -*-

'''
	Problem: Implement a queue using two stacks

	Solution: Insert elements in one stack. When a pop request comes, pop all the elements and put them in the other stack.
	Then remove the top from the second stack. Now, until the second stack is empty, pop is done from second stack. 
	When stack stack becomes empty and there is a pop request, pop all the elements from first stack and put them in second 
	stack. 
'''

from stack import Stack


class QueueViaStack(object):

	def __init__(self):
		self.stack1 = Stack()
		self.stack2 = Stack()

	def enqueue(self, data):
		'''
			Function to insert elements into a queue
		'''
		self.stack1.push(data)


	def deque(self):
		'''
			Function to delete elements from a queue
		'''
		if self.stack2.is_empty():
			while(not self.stack1.is_empty()):
				top = self.stack1.peek()
				self.stack1.pop()
				self.stack2.push(top)

		top = self.stack2.peek()
		print top, "is deleted from queue"

		self.stack2.pop()

	def is_empty(self):
		'''
			Function to check if the queue is empty
		'''
		if self.stack1.is_empty() and self.stack2.is_empty():
			return True

		return False
