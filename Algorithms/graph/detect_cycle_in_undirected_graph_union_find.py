# -*- coding: UTF-8 -*-

'''
	Program to detect cycle in an undirected graph using union-find algorithm
'''

class Edge(object):
	def __init__(self, src, dest):
		self.src = src
		self.dest = dest

class Graph(object):
	def __init__(self, V):
		self.V = V
		# Keep the list of edges
		self.edges = []
		# Store the parent of each node
		self.parent = [-1] * self.V

	def add_edge(self, src, dest):
		'''Add edges to the graph'''
		edge = Edge(src, dest)
		self.edges.append(edge)

	def union(self, src, dest):
		'''When there is a edge between two vertex put them in the same subset'''
		parent = self.get_parent(src)
		self.parent[dest] = parent

	def get_parent(self, vertex):
		'''Return the parent of a vertex and if none return vertex itself'''
		if self.parent[vertex] != -1:
			return self.get_parent(self.parent[vertex])
		else:
			return vertex

	def detect_cycle(self):
		'''Detect cycle in a graph'''
		for edge in self.edges:
			if self.get_parent(edge.src) != self.get_parent(edge.dest):
				self.union(edge.src, edge.dest)
			else:
				return True

		return False

def construct_graph():
	graph = Graph(3)
	graph.add_edge(0, 1)
	graph.add_edge(1, 2)
	graph.add_edge(2, 0)

	return graph

if __name__ == "__main__":
	graph = construct_graph()
	print graph.detect_cycle()
