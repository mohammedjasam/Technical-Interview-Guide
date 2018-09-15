# -*- coding: UTF-8 -*-

'''
	Construct tree from its preorder and postorder traversal
	A Full Binary Tree is a binary tree where every node has either 0 or 2 children
'''

import binary_tree

index_pre = 0
def construct_tree(preorder, postorder, st_in, end_in):
	global index_pre

	if index_pre >= len(preorder) or st_in > end_in:
		return

	else:
		root = binary_tree.Node(preorder[index_pre])
		index_pre += 1

		if st_in == end_in:
			return root

		# Look for the preorder value in postorder, all the elements before index_pre will be in left subtree
		index = postorder.index(preorder[index_pre])

		if index <= len(postorder):
			root.left = construct_tree(preorder, postorder, st_in, index)

			root.right = construct_tree(preorder, postorder, index+1, end_in-1)

	return root


if __name__ == "__main__":
	preorder = [1, 2, 4, 8, 9, 5, 3, 6, 7]
	postorder = [8, 9, 4, 5, 2, 6, 7, 3, 1]

	root = construct_tree(preorder, postorder, 0, len(postorder)-1)
	print "Inorder traversal of constructed tree"
	tree = binary_tree.Tree(root)
	tree.inorder(root)
