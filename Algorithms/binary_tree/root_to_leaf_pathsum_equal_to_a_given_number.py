# -*- coding: UTF-8 -*-

'''
	Given a binary tree and a number, return true if the tree has a root-to-leaf path such that adding up
	all the values along the path equals the given number. Return false if no such path can be found.
'''

# Time complexity: O(n)
def node_to_leaf_sum(root, remaining_sum):
	'''Return true if there exists a path with the sum between root to leaf node'''
	if root is None:
		return remaining_sum == 0

	else:

		sub_sum = remaining_sum - root.data

		if sub_sum == 0 and root.left is None and root.right is None:
			return True

		elif sub_sum <= 0:
			return False

		else:
			return node_to_leaf_sum(root.left, sub_sum) or node_to_leaf_sum(root.right, sub_sum)

if __name__ == "__main__":
	import binary_tree
	tree = binary_tree.construct_binary_tree()

	print node_to_leaf_sum(tree.root, 6)
