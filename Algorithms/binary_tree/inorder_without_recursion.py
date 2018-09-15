# -*- coding: UTF-8 -*-

import binary_tree

# Program to print inorder traversal of tree without using recursion and using stack

def inorder_without_recursion(node):
	if node is None:
		return

	stack = []
	current = node
	done = False

	while(not done):

		if current:
			stack.append(current)
			current = current.left

		else:
			if stack:
				last_item = stack.pop(-1)
				print last_item.data

				if last_item.right != None:
					current = last_item.right

			else:
				done = True

if __name__ == '__main__':
	tree = binary_tree.construct_binary_tree()

	print "Inorder traversal without using recursion"
	inorder_without_recursion(tree.root)