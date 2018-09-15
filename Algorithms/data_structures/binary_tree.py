# -*- coding: UTF-8 -*-

'''
	Class to represent a binary tree node
'''

class BinaryTreeNode(object):

	def __init__(self, data):
		self.data = data
		self.left = None
		self.right = None

	def add_left(self, left):
		'''
			Function to add node at the left of the current node
		'''
		self.left = left

	def add_right(self, right):
		'''
			Function to add node at the right of the current node
		'''
		self.right = right

	def __str__(self):
		text = str(self.data)
		text += ":"

		child = {}
		if self.left:
			child["left"] = str(self.left)

		if self.right:
			child["right"] = str(self.right)
		
		text += str(child)
		return text


def initialize():
	root = BinaryTreeNode(5)

	# Initialize the child nodes
	child_1 = BinaryTreeNode(4)
	child_2 = BinaryTreeNode(6)
	child_child_1 = BinaryTreeNode(3)
	child_child_2 = BinaryTreeNode(1) 
	child_child_3 = BinaryTreeNode(13) 
	child_child_4 = BinaryTreeNode(12) 

	# Connect the child nodes to the parent node
	child_1.add_left(child_child_1)
	child_1.add_right(child_child_2)
	child_2.add_left(child_child_3)
	child_2.add_right(child_child_4)
	root.add_left(child_1)
	root.add_right(child_2)

	print root
	return root

if __name__ == "__main__":
	initialize()
