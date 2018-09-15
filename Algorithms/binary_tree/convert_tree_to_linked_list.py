# -*- coding: UTF-8 -*-

# Program to convert a binary tree to doubly linked list

import binary_tree

def convert_tree_linked_list(root):

	if root is None:
		return None

	if root.left is not None:

		left = convert_tree_linked_list(root.left)

		while left.right:
			left = left.right

		left.right = root
		root.left = left

	if root.right is not None:

		right = convert_tree_linked_list(root.right)

		while right.left:
			right = right.left

		right.left = root
		root.right = right

	return root

tree = binary_tree.construct_binary_tree()

tree.inorder(tree.root)

root = convert_tree_linked_list(tree.root)

# Node returned will be root of the previous tree.
# Inorder to print the linked list, we have to iterate to its left
while root.left:
	root = root.left

print "After conversion"

while (root):
	print root.data
	root = root.right
