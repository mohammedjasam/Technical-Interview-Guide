class Node(object):

	def __init__(self, data):
		self.data = data
		self.left = None
		self.right = None


class Tree(object):

	def __init__(self):
		self.root = None

	def insert(self, node, data):
		if node is None:
			return Node(data)

		if data > node.data:
			node.right = self.insert(node.right, data)
		else:
			node.left = self.insert(node.left, data)

		return node

	def inorder(self, root):
		if root is not None:
			self.inorder(root.left)
			print root.data
			self.inorder(root.right)

	def preorder(self, root):
		if root is not None:
			print root.data
			self.preorder(root.left)
			self.preorder(root.right)

	def postorder(self, root):
		if root is not None:
			self.postorder(root.left)
			self.postorder(root.right)
			print root.data

	def height(self, root):
		if root is None:
			return 0

		else:
			l = self.height(root.left)
			r = self.height(root.right)

			if l > r:
				return l + 1
			else:
				return r + 1

	def search(self, node, data):

		if node == None:
			return None

		if node.data == data:
			return node

		if node.data < data:
			self.search(node.right, data)
		else:
			self.search(node.left, data)

		return node
