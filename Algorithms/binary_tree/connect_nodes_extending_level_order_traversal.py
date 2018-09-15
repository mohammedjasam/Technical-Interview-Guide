# -*- coding: UTF-8 -*-

# Connect nodes at same level, extending level order traversal

import binary_tree

class Node(object):
	def __init__(self, data=None, left=None, right=None, nextRight=None):
		self.data = data
		self.left = left
		self.right = right
		self.nextRight = nextRight

class Queue_Node(object):
	def __init__(self, node, level):
		self.node = node
		self.level = level

def print_nextRight(root, value):
	if not root:
		return

	if root.data == value and root.nextRight:
		print root.nextRight.data
	else:
		print_nextRight(root.left, value)
		print_nextRight(root.right, value)

def inorder(root):
	if root is not None:
		inorder(root.left)
		print root.data
		inorder(root.right)

def connect_nodes(root):
	'''Connect nodes at the same level using level order traversal'''
	if root is None:
		return

	else:
		level = 0
		q = Queue_Node(root, level)
		queue = [q]
		while queue:
			s = queue[0]
			del queue[0]

			if queue and queue[0].level == s.level:
				s.node.nextRight = queue[0].node
			else:
				s.node.nextRight = None

			if s.node.left:
				queue.append(Queue_Node(s.node.left, level+1))
			if s.node.right:
				queue.append(Queue_Node(s.node.right, level+1))

import Queue
def connect(root):
	if root is None:
		return

	else:
		queue = Queue.Queue()
		queue.put(root)

		while !queue.empty:

			num_elements = q.size()

			while (num_elements):
				s = q.get()

				if s.left:
					q.put(s.left)

				if s.right:
					q.put(s.right)

				num_elements -= 1

def construct_binary_tree():
	root = Node(26)
	root.left = Node(10)
	root.right = Node(3)
	root.left.left = Node(4)
	root.left.right = Node(6)
	root.right.right = Node(13)
	root.right.left = Node(5)

	return root

if __name__ == "__main__":
	root = construct_binary_tree()
	connect_nodes(root)
	print_nextRight(root, 10)
