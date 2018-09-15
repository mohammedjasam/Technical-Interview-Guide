# -*- coding: UTF-8 -*-

# Program to convert tree to sumTree
import binary_tree

def convert_to_SumTree(root):
	'''Convert a tree to its sum tree'''
	if root is None:
		return 0

	old_value = root.data
	root.data = convert_to_SumTree(root.left) + convert_to_SumTree(root.right)

	return root.data + old_value

if __name__ == "__main__":
	root = binary_tree.Node(10)
	root.left = binary_tree.Node(-2)
	root.right = binary_tree.Node(6)
	root.left.left = binary_tree.Node(8)
	root.left.right = binary_tree.Node(-4)
	root.right.left = binary_tree.Node(7)
	root.right.right = binary_tree.Node(5)
	tree = binary_tree.Tree(root)
	convert_to_SumTree(tree.root)
