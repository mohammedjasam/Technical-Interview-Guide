# -*- coding: UTF-8 -*-

'''
	Problem: If two nodes are given, find the first commom ancestor of two nodes. 

	Solution: At any node, check if the two nodes lie only in the left subtree or right subtree. If they lie on one side,
	then call the recursion on that side. Otherwise return the node. 


'''

def common_ancestor(root, p, q):
	''' Function to find the first common ancestor of two nodes '''

	if not root:
		return None

	# If the p or q is equal to the root node, then root is the first ancestor
	if root == p or root == q:
		return root

	left = common_ancestor(root.left, p, q)
	right = common_ancestor(root.right, p, q)

	# If two nodes lie on both left and right subtree
	if left is not None and right is not None:
		return root

	# If both nodes lie in the left subtree
	if right is None:
		return left
	# If both nodes lie on the right subtree
	if left is None:
		return right

def main_function():
	''' Function to initialize the binary tree'''
	import binary_tree
	root = binary_tree.initialize()
	node = common_ancestor(root, root.left, root.right.right)
	print node.data

if __name__ == "__main__":
	main_function()
