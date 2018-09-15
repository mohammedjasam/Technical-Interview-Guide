# -*- coding: UTF-8 -*-

# Morris Traversal: Inorder binary tree traversal without recursion and stack

def preorder(root):
	if not root:
		return

	else:
		current = root

		while (current is not None):
			if current.left is None:
				print current.data
				current = current.right

			else:
				if current.left is not None:
					pred = current.left
					while (pred.right is not None and pred.right != current):
						pred = pred.right

					if pred.right is None:
						print current.data
						pred.right = current
						current = current.left

					else:
						pred.right = None
						current = current.right

if __name__ == "__main__":
	import binary_tree
	# construct binary tree
	tree = binary_tree.construct_binary_tree()
	preorder(tree.root)
