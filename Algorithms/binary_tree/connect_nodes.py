# -*- coding: UTF-8 -*-

# Program to connect nodes which are at the same level

import binary_tree

class Node(object):
	def __init__(self, data):
		self.data = data
		self.left = None
		self.right = None
		self.next = None

def connect_nodes(root):
	'''Connect nodes in a tree considering that it is a complete binary tree'''
	if root == None:
		return

	'''Before setting next of left and right children, set next of children of other 
	nodes at same level (because we can access children of other nodes using p's next only)'''
	if root.next != None:
		connect_nodes(root.next)

	if root.left:
		if root.right:
			root.left.next = root.right
			root.right.next = getNextRight(root)
		else:
			root.left.next = getNextRight(root)

	if root.right:
		if root.next:
			root.right.next = root.next.left
		else:
			root.right.next = None

	connect_nodes(root.right)
	connect_nodes(root.left)


def inorder(root):
	'''Print inorder traversal of a tree'''
	if root is not None:
		inorder(root.left)
		print root.data
		if root.next:
			print "Next " + str(root.next.data)
		inorder(root.right)
		

def construct_binary_tree():
	# initialize root node of a tree
	root = Node(1)

	# initialize a binary tree
	tree = binary_tree.Tree(root)

	root.left = Node(2)
	root.right = Node(3)
	root.right.left = Node(4)
	root.right.right = Node(5)
	root.right.left.right = Node(6)

	return tree

if __name__=="__main__":
	tree = construct_binary_tree()
	connect_nodes(tree.root)
	inorder(tree.root)
