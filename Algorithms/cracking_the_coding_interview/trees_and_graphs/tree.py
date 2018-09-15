# -*- coding: UTF-8 -*-

class TreeNode(object):
	''' 
		Class to represent a tree node
	'''
	def __init__(self, data):
		self.data = data
		self.children = []

	def add(self, child):
		'''
			Add the child node
		'''
		self.children.append(child)

	def __str__(self):
		text = str(self.data)
		text +=   ': {' + ', '.join([str(child) for child in self.children]) + "} "
		
		return text

def initialize():
	tree = TreeNode(5)

	# Initialize the child nodes
	child_1 = TreeNode(4)
	child_2 = TreeNode(6)
	child_3 = TreeNode(8)
	child_child = TreeNode(3)

	# Connect the child nodes to the parent node
	child_1.add(child_child)
	tree.add(child_1)
	tree.add(child_2)
	tree.add(child_3)

	print(tree)

if __name__ == "__main__":
	initialize()
