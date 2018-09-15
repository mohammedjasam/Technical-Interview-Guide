# -*- coding: UTF-8 -*-

# Populate inorder successor of tree


class Node(object):
	def __init__(self, data=None, left=None, right=None, next=None):
		self.data = data
		self.left = left
		self.right = right
		self.next = next

next = None

def inorder(root):

	while root.left:
		root = root.left

	temp = root
	
	while temp:
		print temp.data
		temp = temp.next

def inorder_successor(root):

	global next
	
	if not root:
		return

	inorder_successor(root.right)

	root.next = next
	next = root

	inorder_successor(root.left)

def construct_binary_tree():
	root = Node(26)
	root.left = Node(10)
	root.right = Node(3)
	root.left.left = Node(4)
	root.left.right = Node(6)
	root.right.right = Node(13)
	root.right.left = Node(5)

	return root


root = construct_binary_tree()
inorder_successor(root)
inorder(root)