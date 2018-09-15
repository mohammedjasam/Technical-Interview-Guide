# -*- coding: UTF-8 -*-

# Program to check if the binary tree is a binary search tree(BST) or not
import sys
import binary_tree

'''This is easy but wrong approach to solve this. This just check an element with its child nodes. if they satify the bst condition, it returns true. But for a bst, every node to the left of subtree is lesser than node data and every node to teh right of subtree has greater value than node data'''

# def check_if_bst(node):

# 	if node == None:
# 		return True

# 	# false if left is greater than node
# 	if node.left and node.left.data > node.data:
# 		return False

# 	# false if right is less than node
# 	if node.right and node.right.data < node.data:
# 		return False

# 	# false if any of the sub tree is not bst
# 	if not check_if_bst(node.left) or not check_if_bst(node.right):
# 		return False

# 	# else true
# 	return True

def check_if_bst(node):
	
	return check_if_bst_util(node, -sys.maxint, sys.maxint)

def check_if_bst_util(node, min_val, max_val):

	if node == None:
		return True

	# false if node is lesser than min value or greater than max value
	if node.data < min_val or node.data > max_val:
		return False

	if check_if_bst_util(node.left, min_val, node.data) and check_if_bst_util(node.right, node.data, max_val):
		return True
	else:
		return False


if __name__=="__main__":
	tree = binary_tree.construct_binary_tree()

	print check_if_bst(tree.root)