# -*- coding: UTF-8 -*-

'''
	Program to count leaf nodes in a binary tree.

	A node is a leaf node if both left and right child nodes of it are NULL.

	Time Complexity: O(n)
'''

import binary_tree

def count_leaf_nodes(root):
	if root is None:
		return 0
	
	if root.left is None and root.right is None:
		return 1

	else:
		return count_leaf_nodes(root.left) + count_leaf_nodes(root.right)

if __name__ == "__main__":
	tree = binary_tree.construct_binary_tree()
	print count_leaf_nodes(tree.root)
