# -*- coding: UTF-8 -*-

# Print spiral order traversal using iterative method using two stacks

import binary_tree

def spiral_order_traversal(root):
	'''Print the level order traversal in spiral way'''
	if not root:
		return

	# It can be done uisng two stacks
	s1 = [root]
	s2 = []

	while s1 or s2:

		while s1:
			s = s1.pop(-1)
			print s.data

			if s.right:
				s2.append(s.right)

			if s.left:
				s2.append(s.left)

		while s2:
			s = s2.pop(-1)
			print s.data

			if s.left:
				s1.append(s.left)

			if s.right:
				s1.append(s.right)

if __name__ == "__main__":
	tree = binary_tree.construct_binary_tree()
	spiral_order_traversal(tree.root)
