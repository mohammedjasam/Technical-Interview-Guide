# -*- coding: UTF-8 -*-

'''Program to create abstract syntax tree'''

class Node(object):
	def __init__(self, operation=None, value=None, left=None, right=None):
		self.operation = operation
		self.value = value
		self.left = left
		self.right = right


def parse_tree(root):
	if root is None:
		return

	if root.value is not None:
		return root.value

	else:
		left = parse_tree(root.left)
		right = parse_tree(root.right)

		if root.operation is not None:
			if root.operation == "*":
				return left * right
			elif root.operation == "+":
				return left + right
			elif root.operation == "-":
				return left - right
			elif root.operation == "/":
				return left / right

def construct_tree():
	root = Node(operation='+')
	root.left = Node(operation='*')
	root.right = Node(value=5)
	root.left.left = Node(value=25)
	root.left.right = Node(value=6)

	return root

if __name__ == "__main__":
	root = construct_tree()
	print parse_tree(root)
