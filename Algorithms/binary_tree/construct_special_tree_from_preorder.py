# -*- coding: UTF-8 -*-

# Program to construct a special tree from preorder traversal

'''
	Given an array ‘pre[]’ that represents Preorder traversal of a spacial binary tree where 
	every node has either 0 or 2 children. One more array ‘preLN[]’ is given which has only two 
	possible values ‘L’ and ‘N’. The value ‘L’ in ‘preLN[]’ indicates that the corresponding node 
	in Binary Tree is a leaf node and value ‘N’ indicates that the corresponding node is non-leaf node. 
'''
import binary_tree

index = -1
def construct_tree(pre, preLN):
	global index
	index += 1

	if len(pre) == 0:
		return

	root = binary_tree.Node(pre[index])

	if preLN[index] == "N":
		root.left = construct_tree(pre, preLN)
		root.right = construct_tree(pre, preLN)

	return root

pre = [10, 30, 20, 5, 15]
preLN = ['N', 'N', 'L', 'L', 'L']

root = construct_tree(pre, preLN)
tree = binary_tree.Tree(root)
tree.inorder(tree.root)