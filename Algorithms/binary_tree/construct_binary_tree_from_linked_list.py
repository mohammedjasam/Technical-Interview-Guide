# -*- coding: UTF-8 -*-

# Construct a complete binary tree from its linked list representation

import binary_tree
from linked_list import linked_list

def construct_tree(head, index):
	'''Construct tree from linked list and return root of the tree'''
	current = head
	count = 0
	while (count < index and current):
		current = current.nextnode
		count = count + 1

	if current is None:
		return

	root = binary_tree.Node(current.data)

	root.left = construct_tree(head, 2*index+1)
	root.right = construct_tree(head, 2*index+2)

	return root

if __name__ == "__main__":
	# Create a linked list
	head = linked_list.Node(10)
	head.nextnode = linked_list.Node(12)
	head.nextnode.nextnode = linked_list.Node(15)
	head.nextnode.nextnode.nextnode = linked_list.Node(25)
	head.nextnode.nextnode.nextnode.nextnode = linked_list.Node(30)
	head.nextnode.nextnode.nextnode.nextnode.nextnode = linked_list.Node(36)

	root = construct_tree(head, 0)
	tree = binary_tree.Tree(root)
	tree.inorder(tree.root)
