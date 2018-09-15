# -*- coding: UTF-8 -*-

# Iterative preorder traversal

import binary_tree

def iterative_preorder(root):
	'''Print preorder traversal using stack'''
	if root is None:
		return

	stack = [root]
	curr = root

	while stack:
		s = stack.pop(-1)
		print s.data

		if s.right:
			stack.append(s.right)

		if s.left:
			stack.append(s.left)

if __name__ == "__main__":
	tree = binary_tree.construct_binary_tree()
	iterative_preorder(tree.root)
