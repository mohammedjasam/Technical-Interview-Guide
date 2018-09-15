# -*- coding: UTF-8 -*-

# Program to find the diameter of a binary tree
# i.e. number of nodes in the longest path between two leaves in the tree

import binary_tree

def diameter(tree, node):

	if node is None:
		return 0

	lh = tree.height(node.left)
	rh = tree.height(node.right)

	return max(lh+rh+1, max(diameter(tree, node.left), diameter(tree, node.right)))


if __name__=="__main__":
	tree = binary_tree.construct_binary_tree()

	print diameter(tree, tree.root)