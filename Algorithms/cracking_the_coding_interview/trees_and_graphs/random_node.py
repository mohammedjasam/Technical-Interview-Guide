# -*- coding: UTF-8 -*-

'''
	Problem:
'''

import random
class TreeNode:
	def __init__(self, data):
		self.data = data
		self.left = None
		self.right = None
		self.size = 0

class Tree:
	def __init__(self, data):
		self.root = TreeNode(data)
		self.size = 1

	def insertInOrder(self, root, d):
		node = TreeNode(d)

		if d <= root.data:
			if root.left == None:
				root.left = node
			else:
				self.insertInOrder(root.left, d)

		else:
			if root.right == None:
				root.right = node
			else:
				self.insertInOrder(root.right, d)

		root.size += 1
		self.size += 1

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

	def find(self, root, d):
		if d == root.data:
			return root

		if d < root.data:
			self.find(root.left, d)

		else:
			self.find(root.right, d)

	def getRandom(self, root):
		if root is None:
			return

		leftsize = 0 if root.left is None else root.left.size
		print "leftsize", leftsize
		index = random.randint(1, self.size)
		print index
		if index < leftsize:
			return self.getRandom(root.left)

		elif index == leftsize:
			return self

		else:
			return self.getRandom(root.right)



def initialize():
	tree = Tree(4)
	tree.insertInOrder(tree.root, 3)
	tree.insertInOrder(tree.root, 9)
	tree.insertInOrder(tree.root, 1)
	tree.insertInOrder(tree.root, 12)
	tree.insertInOrder(tree.root, 30)
	tree.insertInOrder(tree.root, 5)
	tree.insertInOrder(tree.root, 2)
	tree.insertInOrder(tree.root, 7)
	print tree
	# print "size", tree.size
	# node = tree.getRandom(tree.root)
	# print "Node data", node.data

if __name__ == "__main__":
	initialize()