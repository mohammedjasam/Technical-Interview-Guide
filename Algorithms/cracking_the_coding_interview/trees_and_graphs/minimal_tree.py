# -*- coding: UTF-8 -*-

'''
	Problem: Given a sorted array with unique integer elements, write a algorithm to create a binary tree with 
	minimum height.

	Solution: Our main objective is to divie node such that left subtree and right subtree have equal number of nodes.
	Hence, the middle of each subsection becomes the root of the node. Left half of the array becomes the left subtree and
	right half of the array becomes the right subtree.
'''

import binary_tree

def minimal_tree(sorted_array, start, end):

	if end < start:
		return None

	index = start + (end - start)/2

	node = binary_tree.BinaryTreeNode(sorted_array[index])
	node.left = minimal_tree(sorted_array, start, index-1)
	node.right = minimal_tree(sorted_array, index+1, end)

	return node

def minimal_tree_helper():
	sorted_array = [3, 5, 7, 8, 10, 13, 15]

	root = minimal_tree(sorted_array, 0, len(sorted_array)-1)
	print (root)

if __name__ == "__main__":
	minimal_tree_helper()
