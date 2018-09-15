# -*- coding: UTF-8 -*-

# Morris Traversal: Inorder binary tree traversal without recursion and stack

import binary_tree

def find_inorder_pred(current):
	'''Find inorder predecessor of a node'''
	pred = current.left
	if pred.right is not None and pred.right != current:
		pred = pred.right

	return pred

def inorder(root):
	'''Print inorder traversal of a binary tree'''
	if root is None:
		return

	current = root

	while current is not None:
		if current.left is None:
			print current.data
			current = current.right

		elif current.left is not None:
			pred = find_inorder_pred(current)

			if pred.right is None:
				pred.right = current
				current = current.left

			else:
				pred.right = None
				print current.data
				current = current.right

if __name__ == "__main__":
	# construct binary tree
	tree = binary_tree.construct_binary_tree()

	inorder(tree.root)
