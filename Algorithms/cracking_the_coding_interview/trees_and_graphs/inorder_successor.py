# -*- coding: UTF-8 -*-

'''
	Problem: Find the inorder successor of the node in a binary tree.

	Solution: Inorder succesor of a node in a binary tree is the leftmost node in the right subtree of the node. If the 
	right subtree is None, look for the parents and find a parent which is the leftnode of its parent and return it. 

	Example:

	        5
	      /   \
	     4     6
	   /  \  /  \
	  3    1 13  12

	Inorder successor(6) -> returns 12
	Inorder successor(1) -> returns 5
	Inorder successor(3) -> returns 4
'''


class BinaryTreeNode(object):
	'''
		Binary tree class where each node also stores its parent node. 
	'''
	def __init__(self, data):
		self.data = data
		self.left = None
		self.right = None
		self.parent = None

	def add_left(self, left):
		'''
			Function to add node at the left of the current node
		'''
		self.left = left
		self.left.parent = self
		

	def add_right(self, right):
		'''
			Function to add node at the right of the current node
		'''
		self.right = right
		self.right.parent = self

	def __str__(self):
		text = str(self.data)
		text += ":"

		child = {}
		if self.left:
			child["left"] = str(self.left)

		if self.right:
			child["right"] = str(self.right)
		
		text += str(child)
		return text


def get_inorder_successor(node):
	'''
		Function to get the inorder successor of the node given
	'''
	if node is None:
		return "Node is None"

	if (node.right is not None):
		return leftmost_node(node.right)

	else:
		n = node
		parent = n.parent

		while(parent is not None and n == parent.right):
			n = parent
			parent = n.parent

		return parent


def leftmost_node(node):
	''' 
		For a given node, return the leftmost node in the node subtree
	'''
	if node.left is None:
		return node
	
	if node.left:
		return leftmost_node(node.left)



def main_function():
	root = BinaryTreeNode(5)

	# Initialize the child nodes
	child_1 = BinaryTreeNode(4)
	child_2 = BinaryTreeNode(6)
	child_child_1 = BinaryTreeNode(3)
	child_child_2 = BinaryTreeNode(1) 
	child_child_3 = BinaryTreeNode(13) 
	child_child_4 = BinaryTreeNode(12) 

	# Connect the child nodes to the parent node
	child_1.add_left(child_child_1)
	child_1.add_right(child_child_2)
	child_2.add_left(child_child_3)
	child_2.add_right(child_child_4)
	root.add_left(child_1)
	root.add_right(child_2)

	print root
	temp = root.left.right
	successor = get_inorder_successor(temp)
	print successor.data

if __name__ == "__main__":
	main_function()
