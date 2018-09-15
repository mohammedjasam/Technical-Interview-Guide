# -*- coding: UTF-8 -*-

# Identical Trees

'''
	Two trees are identical when they have same data and arrangement of data is also same.
'''


import binary_tree

def identical_trees(root1, root2):
	'''Return true if two trees are identical otherwise returns false'''
	if not root1 and not root2:
		return True

	if not root1 or not root2:
		return False

	else:
		if root1.data == root2.data and identical_trees(root1.left, root2.left) and identical_trees(root1.right, root2.right):
			return True
		else:
			return False

if __name__ == "__main__":
	tree1 = binary_tree.construct_binary_tree()
	tree2 = binary_tree.construct_binary_tree(
	print identical_trees(tree1.root, tree2.root)