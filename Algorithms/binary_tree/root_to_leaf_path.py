# -*- coding: UTF-8 -*-

# Program to find all the root to leaf paths

import binary_tree

def root_to_leaf(root, path, index):
	'''Print all the root to leaf paths'''
	
	if not root:
		return

	else:
		if index >= len(path):
			path.append(root.data)
		else:
			path[index] = root.data

		# If we reach leaf nodes, then print the path
		if not root.left and not root.right:
			print path[0:index+1]

		root_to_leaf(root.left, path, index+1)
		root_to_leaf(root.right, path, index+1)

if __name__ == "__main__":
	tree = binary_tree.construct_binary_tree()

	root_to_leaf(tree.root, [], 0)
