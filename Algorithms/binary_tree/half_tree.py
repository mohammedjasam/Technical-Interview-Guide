# -*- coding: UTF-8 -*-

# Program to find half tree 

import binary_tree

def half_tree(root):
	if root is None:
		return None
	
	root.left = half_tree(root.left)
	root.right = half_tree(root.right)

	if not root.left and not root.right:
		return root

	if not root.left:
		return root.right

	if not root.right:
		return root.left

	return root

def inorder(root):
		if root is not None:
			inorder(root.left)
			print root.data
			inorder(root.right)

tree = binary_tree.construct_binary_tree()
root = half_tree(tree.root)

inorder(root)
