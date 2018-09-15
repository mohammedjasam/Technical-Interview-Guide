# -*- coding: UTF-8 -*-

# Iterative postorder traversal using two stacks

import binary_tree

def postorder(root):
	if root is None:
		return

	stack1 = [root]
	stack2 = []

	while stack1:
		s = stack1.pop(-1)
		stack2.append(s)

		if s.left:
			stack1.append(s.left)

		if s.right:
			stack1.append(s.right)

	while(stack2):
		s = stack2.pop(-1)
		print s.data

if __name__ == "__main__":
	tree = binary_tree.construct_binary_tree()
	postorder(tree.root)
