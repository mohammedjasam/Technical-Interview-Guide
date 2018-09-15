# -*- coding: UTF-8 -*-

# Deepest left leaf node in a Binary Tree

# 1. Take two arguments root and its level
# 2. Global deepest_node declared, and deepest level
# 3. Do postorder traversal and chek if a node is leaf node and if its level is greater then deepest_level then assign it values 

import binary_tree

# Global variables keep track of deepest leaf node level and its value
deepest_level = -1
deepest_node = None

def deepest_level_leaf_node(root, level):
	global deepest_level
	global deepest_node

	if not root:
		return

	if not root.left and not root.right and level > deepest_level:
		deepest_level = level
		deepest_node = root.data

	deepest_level_leaf_node(root.left, level+1)
	deepest_level_leaf_node(root.right, level+1)


tree = binary_tree.construct_binary_tree()
deepest_level_leaf_node(tree.root, 1)
print deepest_node