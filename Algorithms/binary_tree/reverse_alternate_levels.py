# -*- coding: UTF-8 -*-

# Reverse alternate levels of a perfect binary tree

import binary_tree

# Store the nodes at alternate levels by inorder traversal
def store_nodes(root, level, stored_nodes):
	if root is None:
		return

	store_nodes(root.left, level+1, stored_nodes)

	if level % 2 == 1:
		stored_nodes.append(root.data)

	store_nodes(root.right, level+1, stored_nodes)

# Change the nodes at alternate levels by copying the values from stored_nodes
def reverse(root, level, stored_nodes):

	if not root:
		return

	reverse(root.left, level+1, stored_nodes)

	if level % 2 == 1:
		root.data = stored_nodes[0]
		del stored_nodes[0]

	reverse(root.right, level+1, stored_nodes)


tree = binary_tree.construct_binary_tree()
tree.inorder(tree.root)

stored_nodes = []
store_nodes(tree.root, 0, stored_nodes)
# Reverse the stored nodes
stored_nodes = stored_nodes[::-1]

print "Reversing list"
reverse(tree.root, 0, stored_nodes)
tree.inorder(tree.root)



