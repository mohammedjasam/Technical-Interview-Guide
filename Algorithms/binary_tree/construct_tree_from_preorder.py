# -*- coding: UTF-8 -*-

# Program to construct a tree from its preorder traversal
import binary_tree
import sys

preIndex = 0

def construct_tree(preorder, maximum, minimum, key):

		global preIndex

		if preIndex > len(preorder):
			return

		if key > minimum and key < maximum:

			root = binary_tree.Node(key)

			preIndex += 1

			if preIndex < len(preorder):

				root.left = construct_tree(preorder, root.data, minimum, preorder[preIndex])

				root.right = construct_tree(preorder, maximum, root.data, preorder[preIndex])

			return root

if __name__=="__main__":

	root = construct_tree([3, 2, 1, 5, 4, 6], sys.max_int, -sys.max_int, 3)

	tree = binary_tree.Tree(root)

	tree.inorder(root)