# -*- coding: UTF-8 -*-

# Program to check if a tree is complete or not
'''
	A complete binary tree is a binary tree in which every level, except possibly the last, is completely
	filled, and all nodes are as far left as possible.
'''

import binary_tree
import Queue

def check_tree(root):
	'''Check if binary tree is complete'''
	if not root:
		return

	queue = Queue.Queue()
	flag = False
	queue.put(root)
	while not queue.empty():

		s = queue.get()

		if s.left:
			if flag:
				return False
			# Enqueue left child
			queue.append(s.left)
			# If this a non-full node, set the flag as true
		else:
			flag = True

		if s.right:
			if flag:
				return False
			# Enqueue right child
			queue.append(s.right)
		else:
			flag = False

	return True

if __name__ == "__main__":
	tree = binary_tree.construct_binary_tree()
	print check_tree(tree.root)
