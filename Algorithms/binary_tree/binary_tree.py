# -*- coding: UTF-8 -*-

# Program to construct Binary Tree

class Node(object):

	def __init__(self, data):

		self.data = data
		self.left = None
		self.right = None

class Tree(object):

	def __init__(self, root):

		self.root = root

	def inorder(self, root):
		if root is not None:
			self.inorder(root.left)
			print root.data
			self.inorder(root.right)

	def height(self, root):

		if root is None:
			return 0

		else:
			lh = self.height(root.left)
			rh = self.height(root.right)

			if lh < rh:
				return rh + 1
			else:
				return lh + 1


def construct_binary_tree():

	# initialize root node of a tree
	root = Node(1)

	# initialize a binary tree
	tree = Tree(root)

	root.left = Node(2)
	root.right = Node(3)
	root.left.left = Node(4)
	root.left.right = Node(5)

	return tree
