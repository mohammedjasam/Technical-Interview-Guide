# -*- coding: UTF-8 -*-

'''
	Problem: Given a binary tree, make linked lists for each level of tree 

	    5
	   / \
	  3   9
	 / \
	1   4

	It will make 3 linked lists:
	1
	3 -> 9
	1 -> 4

	Solution 1: Calculate the height of the tree. Then loop through each level of the tree and convert them into a linked
	list.

	Problem: Inefficient solution as it iterates through same nodes multiple times
'''

import binary_tree
import linked_list
import queue


def calculate_height(root):
	''' Function to calculate the height of the tree'''
	if root is None:
		return 0

	else: 
		return max(calculate_height(root.left), calculate_height(root.right)) + 1

def convert_to_linked_list(root, height, ll):
	''' Function to convert level wise tree to linked lists'''
	if root is None:
		return

	if height == 1:
		# if height is 1, then it inserts the root into a linked list
		ll.insert(root.data)
	else:
		convert_to_linked_list(root.left, height-1, ll)
		convert_to_linked_list(root.right, height-1, ll)


def level_tree():
	'''
		Function to intialize a tree and call level wise traversal
	'''
	root = binary_tree.initialize()
	# height = calculate_height(root)

	# for level in range(1, height+1):
	# 	ll = linked_list.LinkedList()
	# 	convert_to_linked_list(root, level, ll)
	# 	ll.print_list()
	print level_of_node(root, 1, 0)


def level_of_node(root, node, level):
    if root is None:
        return -1

    if root.data == node:
        return level

    return max(level_of_node(root.left, node, level+1), level_of_node(root.right, node, level+1))

# -------------------------------------------------------------------------------------------------------------


def level_order_traversal(root):
	if root is None:
		return

	q = queue.Queue()
	q.enqueue(root)
	print q.isEmpty()
	while (not q.isEmpty()):
		temp = q.deque()
		print temp.data
		if temp.left is not None:
			q.enqueue(temp.left)
		if temp.right is not None:
			q.enqueue(temp.right)
		

if __name__ == "__main__":
	level_tree()
