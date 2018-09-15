# -*- coding: UTF-8 -*-

# Program to find lowest common ancestor of two nodes

import bst

def lowest_common_ancestor(root, node1, node2):

	if root == None:
		return

	if root.data > node1 and root.data > node2:
		lowest_common_ancestor(root.left, node1, node2)

	if root.data < node1 and root.data < node2:
		lowest_common_ancestor(root.right, node1, node2)

	return root.data

if __name__=="__main__":

	tree = bst.Tree()
	elements = [3, 5, 9, 8, 1, 7]

	root = tree.insert(tree.root, 6)

	for element in elements:
		tree.insert(root, element)

	# tree.inorder(root)

	print lowest_common_ancestor(root, 5, 9)
