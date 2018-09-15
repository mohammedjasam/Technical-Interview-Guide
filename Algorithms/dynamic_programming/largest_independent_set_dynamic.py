# -*- coding: UTF-8 -*-

# Largest Independent set problem i.e. A subset of all tree nodes is an independent set if there is no edge between any two nodes of the subset.

# Dynamic Programming Solution

class Node(object):

	def __init__(self, data):

		self.data = data
		self.left = None
		self.right = None
		self.liss = 0

def largest_independent_set_problem(root):
	if not root:
		return 0

	if root.liss:
		return root.liss

	if not root.left and not root.right:
		return 1

	a = largest_independent_set_problem(root.left) + largest_independent_set_problem(root.right)

	b = 1
	if root.left:
		b += largest_independent_set_problem(root.left.left) + largest_independent_set_problem(root.left.right)

	if root.right:
		b += largest_independent_set_problem(root.right.left) + largest_independent_set_problem(root.right.right)

	root.liss = max(a, b)

	return root.liss

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
print largest_independent_set_problem(root)