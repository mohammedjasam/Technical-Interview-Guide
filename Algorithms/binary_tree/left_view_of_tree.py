# -*- coding: UTF-8 -*-

# Program to print left view of a tree

import binary_tree

max_level = 0

def left_view_of_tree(node, level):
	global max_level

	if node is None:
		return

	if  max_level < level:
		print node.data, level, max_level
		max_level = level

	left_view_of_tree(node.left, level+1)
	left_view_of_tree(node.right, level+1)


if __name__=="__main__":
	tree = binary_tree.construct_binary_tree()
	print "Printing lef view of tree"
	left_view_of_tree(tree.root, 1)