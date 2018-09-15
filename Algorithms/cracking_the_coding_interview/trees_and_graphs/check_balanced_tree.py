# -*- coding: UTF-8 -*-

'''
	Problem: Check if a binary tree is balanced. 
	Balanced tree is defined to be a tree such that the heights of the two subtree of any node never 
	differ by more than one.

	Solution: At each node calculate the difference of height of left subtree and right subtree and if the difference is 
	greater than one, returns False. Also checks the same for left node and right node. 
'''
import binary_tree

def calculate_height(root):
	''' Function to calculate the height of the subtree'''
	if root is None:
		return 0

	else: 
		return max(calculate_height(root.left), calculate_height(root.right)) + 1

def bruteforce_check_balanced(root):
	''' Function to check if the tree is balanced'''
	if root is None:
		return True

	left_height = calculate_height(root.left)
	right_height = calculate_height(root.right)

	difference = abs(left_height - right_height)

	if difference > 1:
		return False

	return bruteforce_check_balanced(root.left) and bruteforce_check_balanced(root.right)

def main_function():
	root = binary_tree.initialize()
	print calculate_height(root)

	print bruteforce_check_balanced(root)

if __name__ == "__main__":
	main_function()
