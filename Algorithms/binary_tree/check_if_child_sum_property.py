# -*- coding: UTF-8 -*-

'''
	Program to check if child sum property holds in the binary tree. For every node, data value must be equal to
	sum of data values in left and right children.
'''

import binary_tree

def child_sum_property(root):
	'''Return true if a tree holds a child sum property'''
	if root is None:
		return True
	
	else:
		if root.left is None and root.right is None:
			return True
		else:
			left = root.left.data if root.left is not None else 0
			right = root.right.data if root.right is not None else 0

			if root.data != left + right:
				return False
			else:
				return child_sum_property(root.left) and child_sum_property(root.right)

if __name__=="__main__":
	tree = binary_tree.construct_binary_tree()
	print child_sum_property(tree.root)
