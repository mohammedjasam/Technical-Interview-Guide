# -*- coding: UTF-8 -*-

# Check if all the leaves are at same level

import binary_tree


def check_leaves(root, level, given_level):
	if root is None:
		return True

	elif root.left is None and root.right is None:
		if given_level[0] == 0:
			given_level[0] = level
			return True
		else:
			return (level == given_level[0])

	else:
		return check_leaves(root.left, level+1, given_level) and check_leaves(root.right, level+1, given_level)


if __name__=="__main__":
	tree = binary_tree.construct_binary_tree()

	print check_leaves(tree.root, 1, [0])