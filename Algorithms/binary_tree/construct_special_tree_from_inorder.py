# -*- coding: UTF-8 -*-

'''
	Given Inorder Traversal of a Special Binary Tree in which key of every node is greater than keys in
	left and right children, construct the Binary Tree and return root.
'''
import binary_tree

def special_tree(sequence, left, right):
	if left > right:
		return

	else:
		index = left
		# Find the highest element in the increasing sequence
		while (index < right and sequence[index] < sequence[index+1]):
			index = index + 1

		root = binary_tree.Node(sequence[index])

		root.left = special_tree(sequence, left, index-1)
		root.right = special_tree(sequence, index+1, right)

		return root

if __name__ == "__main__":
	inorder = [1, 5, 10, 40, 30, 15, 28, 20]

	root = special_tree(inorder, 0, len(inorder)-1)
	tree = binary_tree.Tree(root)
	tree.inorder(tree.root)
