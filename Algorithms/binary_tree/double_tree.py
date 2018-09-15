# -*- coding: UTF-8 -*-

'''
	Write a program that converts a given tree to its Double tree. To create Double tree of the given tree,
	create a new duplicate for each node, and insert the duplicate as the left child of the original node.
'''
import binary_tree

def double_tree_1(root):
	'''Convert the tree to its double tree'''
	if root is None:
		return
	else:
		temp = root.left
		root.left = binary_tree.Node(root.data)
		root.left.left = temp

		double_tree_1(root.left.left)
		double_tree_1(root.right)

		return root

def double_tree(root):
	'''Convert the tree to its double tree'''
	if root is None:
		return
	else:

		double_tree(root.left)
		double_tree(root.right)

		temp = root.left
		root.left = binary_tree.Node(root.data)
		root.left.left = temp

	return root

if __name__ == "__main__":
	tree = binary_tree.construct_binary_tree()

	tree.inorder(tree.root)
	print "Conversion to double tree using method 1"
	tree.root = double_tree_1(tree.root)
	tree.inorder(tree.root)

	tree = binary_tree.construct_binary_tree()
	print "Conversion to double tree using method 2"
	tree.root = double_tree(tree.root)
	tree.inorder(tree.root)
