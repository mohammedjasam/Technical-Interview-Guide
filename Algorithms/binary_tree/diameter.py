# -*- coding: UTF-8 -*-

'''
	The diameter of a tree (sometimes called the width) is the number of nodes on the longest path between two
	leaves in the tree.
'''

import binary_tree

def height(root):
	'''Calculate and return the height of the tree'''
	if not root:
		return 0

	else:
		return max(height(root.left), height(root.right)) + 1

# Time Complexity: O(n^2)
def diameter(root):
	'''Calculate the diameter of the tree'''
	if not root:
		return 0

	else:
		lh = height(root.left)
		rh = height(root.right)

		ld = diameter(root.left)
		rd = diameter(root.right)

		return max(lh+rh+1, max(ld, rd))

if __name__ == "__main__":
	tree = binary_tree.construct_binary_tree()
	print diameter(tree.root)