# -*- coding: UTF-8 -*-

# Program to find maximum sum of root to leaf

import binary_tree

max_sum = 0

def maximum_root_to_leaf(root, path, index):
	'''Calculate the maximu root to leaf path'''
	global max_sum

	if not root:
		return

	else:
		if index >= len(path):
			path.append(root.data)
		else:
			path[index] = root.data

		# If we reach leaf nodes, then calculate the path suma and compare with max_sum
		if not root.left and not root.right:
			if sum(path[0:index+1]) > max_sum:
				max_sum = sum(path[0:index+1]) 

		maximum_root_to_leaf(root.left, path, index+1)
		maximum_root_to_leaf(root.right, path, index+1)

if __name__ == "__main__":
	tree = binary_tree.construct_binary_tree()

	maximum_root_to_leaf(tree.root, [], 0)
	print max_sum
