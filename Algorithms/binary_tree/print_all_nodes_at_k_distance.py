# -*- coding: UTF-8 -*-

# Print all the nodes that are at the kth distance from the root node

import binary_tree

def all_nodes_at_k_distance(node, k):
	'''Print nodes at k distance from root node'''
	if node is None:
		return

	if k == 0:
		print node.data

	all_nodes_at_k_distance(node.left, k-1)
	all_nodes_at_k_distance(node.right, k-1)


def k_distance(root, distance, k):
	'''Print nodes at k distance from root node'''
	if root is None:
		return

	if distance == k:
		print(root.data)

	else:
		k_distance(root.left, distance+1, k)
		k_distance(root.right, distance+1, k)

if __name__=="__main__":
	tree = binary_tree.construct_binary_tree()

	print "Nodes at kth distance"
	all_nodes_at_k_distance(tree.root, 1)
	k_distance(tree.node, 0, 1)
