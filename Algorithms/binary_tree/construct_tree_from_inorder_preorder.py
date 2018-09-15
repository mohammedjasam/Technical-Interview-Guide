# -*- coding: UTF-8 -*-

# Program to construct binary tree from its inorder and preorder traversal

import binary_tree

preindex = 0

def construct_tree(preorder, inorder, start, end):
	global preindex

	if start > end:
		return

	root = binary_tree.Node(preorder[preindex])
	preindex += 1

	if start == end:
		return root

	index = inorder.index(root.data)
	
	if index >= 0:
		root.left = construct_tree(preorder, inorder, start, index-1)
		root.right = construct_tree(preorder, inorder, index+1, end)

	return root

if __name__=="__main__":

	root = construct_tree([1, 2, 4, 5, 3], [4, 2, 5, 1, 3], 0, 4)

	tree = binary_tree.Tree(root)

	tree.inorder(root)
