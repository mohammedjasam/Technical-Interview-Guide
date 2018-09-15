# -*- coding: UTF-8 -*-

# Program to construct Balanced BST from a sorted list

import binary_tree

def construct_tree(list, s_in, e_in):

	if s_in > e_in:
		return

	index = (s_in+e_in)/2

	if index < len(list):
		root = binary_tree.Node(list[index])

		root.left = construct_tree(list, s_in, index-1)
		root.right = construct_tree(list, index+1, e_in)

		return root

if __name__=='__main__':
	# tree = binary_tree.construct_binary_tree()
	root = construct_tree([1,2,3,4,5,6,7], 0, 7)
	tree = binary_tree.Tree(root)
	tree.inorder(root)