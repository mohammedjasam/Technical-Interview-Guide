# -*- coding: UTF-8 -*-

# Convert a given Binary Tree to Doubly Linked List 

import binary_tree

def convert_to_doubly_linked_list(root):
	if not root:
		return

	if root.left:
		left = convert_to_doubly_linked_list(root.left)

		while left.right:
			left = left.right

		left.right = root
		root.left = left

	if root.right:
		right = convert_to_doubly_linked_list(root.right)

		while right.left:
			right = right.left

		root.right = right
		right.left = root

	return root

def print_list(root):
	if not root:
		return

	while root.left:
		root = root.left

	head = root

	while head:
		print head.data
		head = head.right

tree = binary_tree.construct_binary_tree()
root = convert_to_doubly_linked_list(tree.root)
print_list(root)