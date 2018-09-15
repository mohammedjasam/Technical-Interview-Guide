# -*- coding: UTF-8 -*-

# Program to find all ancestors of a node in a binary tree

import binary_tree

def find_ancestors(root, node, index, path):
	'''Print all the ancestors of a node'''
	if root is None:
		return

	if root.data == node:
		print path[0:index]
		return

	else:
		if index < len(path):
			path[index] = root.data
		else:
			path.append(root.data)

		find_ancestors(root.left, node, index+1, path)
		find_ancestors(root.right, node, index+1, path)

if __name__ == "__main__":
	tree = binary_tree.construct_binary_tree()
	find_ancestors(tree.root, 4, 0, [])
