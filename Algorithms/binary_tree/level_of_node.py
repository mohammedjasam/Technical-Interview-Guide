# -*- coding: UTF-8 -*-

# Program to find level of a node in a binary tree

import binary_tree
import copy

def level_of_node(root, node, level):
	if root is None:
		return 0

	if root.data == node:
		return level

	else:
		return max(level_of_node(root.left, node, level+1), level_of_node(root.right, node, level+1))


def find_level():
	tree = binary_tree.construct_binary_tree()
	level = 0
	print level_of_node(tree.root, 8, level+1)


if __name__=="__main__":
	find_level()