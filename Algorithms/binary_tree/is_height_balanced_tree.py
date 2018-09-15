# -*- coding: UTF-8 -*-

# Programt o check if a tree is height balanced or not. A tree is height balanced if difference in height of left and right subtree is not greater than 1

import binary_tree

def height(root):
	'''Calculate the height of the tree'''
	if root is None:
		return 0

	else:
		left_height = height(root.left)
		right_height = height(root.right)

		return max(left_height, right_height) + 1

def is_balanced_tree(node):
	'''Return true if tree is height balanced'''
	if node == None:
		return True

	else:
		left_height = height(node.left)
		right_height = height(node.right)

		if abs(left_height - right_height) <= 1 and is_balanced_tree(node.left) and is_balanced_tree(node.right):
			return True

		return False

if __name__=="__main__":
	tree = binary_tree.construct_binary_tree()
	print is_balanced_tree(tree.root)
