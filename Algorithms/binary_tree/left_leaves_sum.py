# -*- coding: UTF-8 -*-

# Program to find sum of all left leaves

import binary_tree

max_sum = 0

def sum_left_leaves(root):
	global max_sum

	if root is None:
		return

	if root.left and not root.left.left and not root.left.right:
		max_sum += root.left.data

	sum_left_leaves(root.left)
	sum_left_leaves(root.right)


tree = binary_tree.construct_binary_tree()
sum_left_leaves(tree.root)
print max_sum
