# -*- coding: UTF-8 -*-

# Level order tree traversal

'''
	Level order traversal of a tree is also called breadth first traversal of the tree.

	METHOD 1: (Use function to print a given level)

	Time complexity: O(n*n)
'''

import binary_tree

def level_order_traversal_helper(root, level):
	'''Print the node if the level is 1'''
	if root is None:
		return

	if level == 1:
		print root.data

	else:
		level_order_traversal_helper(root.left, level-1)
		level_order_traversal_helper(root.right, level-1)

def level_order_traversal(tree):
	'''Call the level order helper at each level of the tree'''
	height = tree.height(tree.root)

	for i in range(1, height+1):
		level_order_traversal_helper(tree.root, i)

'''
	Method 2: Using queue

	Time Complexity: O(n)
'''

import Queue

def level_order_traversal_using_queue(root):
	'''Print level order traversal using queue'''
	q = Queue.Queue()

	q.put(root)
	while not q.empty():
		temp = q.get()
		print temp.data

		if temp.left:
			q.put(temp.left)

		if temp.right:
			q.put(temp.right)

if __name__ == "__main__":
	# Construct binary tree
	tree = binary_tree.construct_binary_tree()
	print "Level order traversal"
	level_order_traversal(tree)
	print "Level order traversal using queue"
	level_order_traversal_using_queue(tree.root)
	