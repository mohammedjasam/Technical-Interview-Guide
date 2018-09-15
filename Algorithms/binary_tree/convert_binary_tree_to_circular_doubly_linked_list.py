# -*- coding: UTF-8 -*-

'''
	Given a Binary Tree, convert it to a Circular Doubly Linked List (In-Place).

	* The left and right pointers in nodes are to be used as previous and next pointers respectively 
	in converted Circular Linked List.
	* The order of nodes in List must be same as Inorder of the given Binary Tree.
	* The first node of Inorder traversal must be head node of the Circular List.
'''

class Node(object):
	def __init__(self, data, left=None, right=None):
		self.data = data
		self.left = left
		self.right = right

def concatenate(left_list, right_list):
	'''Concatenate the left and right circular linked list'''
	if left_list is None:
		return right_list

	if right_list is None:
		return left_list

	# Store the last Node of left List
	left_last = left_list.left
	# Store the last Node of right List
	right_last = right_list.left

	# Connect the last node of Left List with the first Node of the right List
	left_last.right = right_list
	right_last.left = left_last

	# Left of first node points to the last node in the list
	left_list.left = right_last
	# Right of last node refers to the first node of the List
	right_last.right = left_list

	return left_list

def bTree_to_cList(root):
	'''Convert binary tree to circular linked list'''
	if root is None:
		return

	left = bTree_to_cList(root.left)
	right = bTree_to_cList(root.right)

	root.left = root.right = root

	return concatenate(concatenate(left, root), right)

def display_cList(head):
	'''Print the circular linked list'''
	current = head
	while (current.right != head):
		print current.data
		current = current.right
	print current.data

def construct_tree():
	'''Construct a binary tree'''
	import binary_tree

	root = Node(10)
	root.left = Node(12)
	root.right = Node(15)
	root.left.left = Node(25)
	root.left.right = Node(30)
	root.right.left = Node(36)

	return root

if __name__ == "__main__":
	root = construct_tree()

	head = bTree_to_cList(root)
	display_cList(head)
