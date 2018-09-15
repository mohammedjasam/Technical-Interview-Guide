# -*- coding: UTF-8 -*-

# Find the closest leaf in a Binary Tree

import binary_tree
import sys

def closest_leaf_util(root):
	if root is None:
		return sys.maxint

	if not root.left and not root.right:
		return 0

	else:
		return min(closest_leaf_util(root.left), closest_leaf_util(root.right)) + 1

def closest_leaf(root, value, ancestors, index):

	if root is None:
		return sys.maxint

	if root.data == value:
		# check for closest leaf node distance downwards
		distance = closest_leaf_util(root)

		# Look for the closest leaf node distance for all its ancestors
		for i in range(index-1, -1, -1):
			distance = min(distance, index-i+closest_leaf_util(ancestors[i]))

		return distance

	if index >= len(ancestors):
		ancestors.append(root)
	else:
		ancestors[index] = root

	return min(closest_leaf(root.left, value, ancestors, index+1), closest_leaf(root.right, value, ancestors, index+1))

tree = binary_tree.construct_binary_tree()
# List that will store ancestors at every index
ancestors = []
print closest_leaf(tree.root, 'C', ancestors, 0)