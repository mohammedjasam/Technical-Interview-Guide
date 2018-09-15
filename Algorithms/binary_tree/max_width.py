# -*- coding: UTF-8 -*-

# Program to print the maximum width of a tree

import binary_tree

def max_width(tree):
	'''Return the maximum width of the binary tree'''
	h = tree.height(tree.root)

	# count stores the number of nodes at each level
	count = [0] * h
	max_width_util(tree.root, count, 0)

	return max(count)

def max_width_util(root, count, level):
	'''Increase the count at each level'''
	if root:
		count[level] += 1
		max_width_util(root.left, count, level+1)
		max_width_util(root.right, count, level+1)

if __name__=="__main__":
	tree = binary_tree.construct_binary_tree()
	print max_width(tree)
