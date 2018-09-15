# -*- coding: UTF-8 -*-

'''
	Write a function to detect if two trees are isomorphic. Two trees are called isomorphic if one of them can be
	obtained from other by a series of flips, i.e. by swapping left and right children of a number of nodes. Any
	number of nodes at any level can have their children swapped. Two empty trees are isomorphic.
'''

def isomorphic_trees(a, b):
	if a is None and b is None:
		return True

	if a is None or b is None:
		return False

	if a.data != b.data:
		return False

	return (isomorphic_trees(a.left, b.left) and isomorphic_trees(a.right, b.right)) \
		or (isomorphic_trees(a.right, b.left) and isomorphic_trees(a.left, b.right))

if __name__ == "__main__":
	import binary_tree

	n1 = binary_tree.Node(1)
	n1.left = binary_tree.Node(2)
	n1.right = binary_tree.Node(3)
	n1.left.left = binary_tree.Node(4)
	n1.left.right = binary_tree.Node(5)
	n1.right.left = binary_tree.Node(6)
	n1.left.right.left = binary_tree.Node(7)
	n1.left.right.right = binary_tree.Node(8)
 
	n2 = binary_tree.Node(1)
	n2.left = binary_tree.Node(3)
	n2.right = binary_tree.Node(2)
	n2.right.left = binary_tree.Node(4)
	n2.right.right = binary_tree.Node(5)
	n2.left.right = binary_tree.Node(6)
	n2.right.right.left = binary_tree.Node(8)
	n2.right.right.right = binary_tree.Node(7)

	print isomorphic_trees(n1, n2)
