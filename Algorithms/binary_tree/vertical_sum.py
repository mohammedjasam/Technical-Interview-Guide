# -*- coding: UTF-8 -*-

import binary_tree

# Program to find vertical sum of a tree. 
'''
	hd for root is 0, a right edge (edge connecting to right subtree) is considered as +1 horizontal distance
	and a left edge is considered as -1 horizontal distance.
'''

def vertical_sum(root, distance, hash_map):
	'''Calculate the vertical sum of a tree'''
	if root is None:
		return

	hash_map.setdefault(distance, 0)
	hash_map[distance] += root.data

	vertical_sum(root.left, distance-1, hash_map)
	vertical_sum(root.right, distance+1, hash_map)

if __name__ == "__main__":
	tree = binary_tree.construct_binary_tree()

	sum_dict = {}
	vertical_sum(tree.root, 0, sum_dict)
	print sum_dict
