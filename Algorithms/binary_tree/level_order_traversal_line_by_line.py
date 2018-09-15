# -*- coding: UTF-8 -*-

# Print level order traversal line by line using iterative level order traversal

from __future__ import print_function
import binary_tree
import Queue


def level_order_traversal_helper(root, level):
	'''Print the node if the level is 1'''
	if root is None:
		return

	if level == 1:
		print(root.data, end=" ")

	else:
		level_order_traversal_helper(root.left, level-1)
		level_order_traversal_helper(root.right, level-1)

def level_order_traversal(tree):
	'''Call the level order helper at each level of the tree'''
	height = tree.height(tree.root)

	for i in range(1, height+1):
		level_order_traversal_helper(tree.root, i)
		print ("\n")

def level_order_traversal_using_queue(root):
	'''Print level order traversal using queue'''
	q = Queue.Queue()

	q.put(root)
	while not q.empty():
		number_of_nodes = q.qsize()

		while (number_of_nodes):
			temp = q.get()
			print(temp.data, end=" ")

			if temp.left:
				q.put(temp.left)

			if temp.right:
				q.put(temp.right)

			number_of_nodes -= 1

		print("\n")

if __name__ == "__main__":
	tree = binary_tree.construct_binary_tree()
	level_order_traversal(tree)
	print("Level order traversal using queue")
	level_order_traversal_using_queue(tree.root)
