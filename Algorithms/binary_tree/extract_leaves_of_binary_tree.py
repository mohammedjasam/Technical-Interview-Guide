# -*- coding: UTF-8 -*-

# Program to extract the leaves of a binary tree in a doubly linked list

import binary_tree

class Node(object):

	def __init__(self, data):

		self.data = data
		self.nextnode = None

head = None

def extract_leaves(root):
	global head
	if root == None:
		return None

	if not root.left and not root.right:
		temp = Node(root.data)
		
		if head is not None:
			temp.nextnode = head

		head = temp
		return None

	root.right = extract_leaves(root.right)
	root.left = extract_leaves(root.left)
	
	return root

tree = binary_tree.construct_binary_tree()
tree.inorder(tree.root)

root = extract_leaves(tree.root)
print "After extracting leaves"
tree.inorder(root)

print "Linked list"
while head:
	print head.data
	head = head.nextnode
