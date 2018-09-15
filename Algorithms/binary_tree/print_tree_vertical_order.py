# -*- coding: UTF-8 -*-

'''Print a Binary Tree in Vertical Order'''

import binary_tree

def vertical_order_print(root, distance, hash_map):
	if root is None:
		return

	hash_map.setdefault(distance, [])
	hash_map[distance].append(root.data)

	vertical_order_print(root.left, distance-1, hash_map)
	vertical_order_print(root.right, distance+1, hash_map)

if __name__ == "__main__":
	tree = binary_tree.construct_binary_tree()

	hash_map = {}
	vertical_order_print(tree.root, 0, hash_map)

	print hash_map
