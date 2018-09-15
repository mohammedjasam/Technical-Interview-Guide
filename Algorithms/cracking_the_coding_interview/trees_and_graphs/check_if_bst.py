# -*- coding: UTF-8 -*-

'''
	Problem: Given a binary tree, check if it is a binary search tree or not. A binary search tree is a binary tree 
	such that all nodes to the left of root are smaller than the root node and all nodes to the right of 
	the root node are larger than the root node.

	Solution 1: Iterate through the tree and compare each node with its left and right node. If anywhere the left and right 
	node values violates, return False else return True. 

	Problem(Incorrect solution): Fails for a tree
								3
							  /  \
							 2    5
							/ \
						   1   4

	Solution 2: Check if the maximum value in the left subtree is smaller than the node and minimum value in the right 
	subtree is greater than the node.

	Inefficient solution as for each node, first we will have to find the min and max value and compare it. It will 
	traverse the same part of the tree many times. 

	Solution 3: Using a helper function BSTUtil(node, max, min) we can traverse down the tree keeping a track of max and
	min value. This will traverse each node only once. 
'''


def BSTUtil(node, maximum, minimum):
	''' Helper function to check if tree is a bst'''
	if node is None:
		return True
	
	# If the node is less than min value or greater than max value, it returns False
	if (node.data < minimum or node.data > maximum):
		return False

	return BSTUtil(node.left, node.data, minimum) and BSTUtil(node.right, maximum, node.data)


def checkBST(node):
	''' 
		Function to check if a binary tree is a bst or not
	'''
	if node is None:
		return True

	# We call th helper function by passing the maximum and minimum values initially
	if BSTUtil(node, 999999999, -99999999999):
		return True
	else:
		return False
