# -*- coding: UTF-8 -*-

# Print reverse level order traversal. The idea is to print last level first, then second last level, and so on.

from Queue import *
import binary_tree

def reverse_level_order(root):
	'''Print reverse level order traversal of a tree'''
	if not root:
		return

	queue = Queue()
	queue.put(root)
	stack = []

	while not queue.empty():
		s = queue.get()
		stack.append(s)

		if s.left:
			queue.put(s.left)

		if s.right:
			queue.put(s.right)

	while stack:
		s = stack.pop()
		print s.data

if __name__ == "__main__":
	tree = binary_tree.construct_binary_tree()
	reverse_level_order(tree.root)
