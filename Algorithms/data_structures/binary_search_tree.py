# -*- coding: UTF-8 -*-

'''
	Program to implement binary search tree

'''

class Node(object):
	'''
		Node class represents each node of the binary search tree
	'''
	def __init__(self, data):
		self.data = data
		self.left = None
		self.right = None


class BinarySearchTree(object):
	'''
		Class to represent binary search tree
	'''
	def __init__(self):
		self.root = None

	def insert(self, data, root):
		'''
			Function to insert node in a binary search tree
		'''
		if root is None:
			return Node(data)

		elif data <= root.data:
			root.left = self.insert(data, root.left)

		else:
			root.right = self.insert(data, root.right)

		return root

	def inorder(self, node):
		''' 
			Function to print the inorder traversal of the tree
		'''
		if node is None:
			return

		self.inorder(node.left)
		print (node.data)
		self.inorder(node.right)


def initialize():
	'''
		Function to initialize a binary search tree
	'''
	bst = BinarySearchTree()

	bst.root = bst.insert(6, bst.root)
	bst.insert(1, bst.root)
	bst.insert(9, bst.root)
	bst.insert(3, bst.root)
	bst.inorder(bst.root)

	return bst

if __name__ == "__main__":
	initialize()
