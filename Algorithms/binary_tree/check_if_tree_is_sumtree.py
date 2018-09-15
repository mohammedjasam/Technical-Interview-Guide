# -*- coding: UTF-8 -*-

'''
	Check if a given tree is a sumTree i.e. A SumTree is a Binary Tree where the value of a node is equal
	to sum of the nodes present in its left subtree and right subtree.
'''
import binary_tree

def check_sumtree(root):
	if not root or (not root.left and not root.right):
		return True

	else:

		if check_sumtree(root.left) and check_sumtree(root.right):

			if not root.left:
				ls = 0
			elif not root.left.left and not root.left.right:
				ls = root.left.data
			else:
				ls = 2 * root.left.data

			if not root.right:
				rs = 0
			elif not root.right.left and not root.right.right:
				rs = root.right.data
			else:
				rs = 2 * root.right.data

			if root.data == (ls+rs):
				return True

		return False

if __name__ == "__main__":
	root = binary_tree.Node(26)
	root.left = binary_tree.Node(10)
	root.right = binary_tree.Node(3)
	root.left.left = binary_tree.Node(4)
	root.left.right = binary_tree.Node(6)
	root.right.right = binary_tree.Node(3)
	tree = binary_tree.Tree(root)
	tree.inorder(root)
	print check_sumtree(tree.root)
