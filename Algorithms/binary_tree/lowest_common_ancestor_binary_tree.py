# -*- coding: UTF-8 -*-

# Program to find lowest common ancestor of binary tree

import binary_tree

def find_path(root, path, node1):

	if root is None:
		return False

	path.append(root.data)

	if root.data == node1:
		return path

	if (root.left and find_path(root.left, path, node1)) or (root.right and find_path(root.right, path, node1)):
		return True

	del path[-1]

	return False

def lowest_common_ancestor(root, node1, node2):

	path1 = []
	path2 = []

	if not find_path(root, path1, node1) or not find_path(root, path2, node2):
		return -1

	i = 0
	while (i < len(path1) and i < len(path2)):
		if path1[i] != path2[i]:
			break
		i += 1

	print path1[i-1]

if __name__=="__main__":
	tree = binary_tree.construct_binary_tree()

	lowest_common_ancestor(tree.root, 5, 4)
