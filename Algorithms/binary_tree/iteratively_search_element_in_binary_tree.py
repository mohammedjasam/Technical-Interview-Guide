# -*- coding: UTF-8 -*-

# Iterative search for a key in a binary tree

import binary_tree

def search(root, x):

	if root is None:
		return

	queue = [root]

	while queue:

		node = queue[0]

		if node.data == x:
			return True

		del queue[0]

		if node.left != None:
			queue.append(node.left)
		if node.right != None:
			queue.append(node.right)

	return False

tree = binary_tree.construct_binary_tree()

print search(tree.root, 100)






