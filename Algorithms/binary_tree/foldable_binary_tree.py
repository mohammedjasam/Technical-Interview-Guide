# -*- coding: UTF-8 -*-

'''
	Foldable Binary Tree. Program to find if a tree can be folded or not. A tree can be folded if left and
	right subtrees of the tree are structure wise mirror image of each other. 
'''
import binary_tree

def mirror(root1, root2):
	'''Check if the two sub trees are mirror or not'''
	if not root1 and not root2:
		return True
	elif not root1 or not root2:
		return False
	elif mirror(root1.right, root2.left) and mirror(root1.left, root2.right):
		return True
	else:
		return False

def foldable_tree(root):
	'''Check if teh tree can be folded or not'''
	if root is None:
		return True

	else:
		if mirror(root.left, root.right):
			return True
		else:
			return False

if __name__ == "__main__":
	tree = binary_tree.construct_binary_tree()
	print foldable_tree(tree.root)
